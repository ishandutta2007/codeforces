#include<bits/stdc++.h>
#define fr(i,a,b) for(int i=(a),end_##i=(b);i<=end_##i;i++)
#define fd(i,a,b) for(int i=(a),end_##i=(b);i>=end_##i;i--)
#define i64 long long
int read()
{
	int r=0,t=1,c=getchar();
	while(c<'0'||c>'9'){ t=c=='-'?-1:1; c=getchar(); }
	while(c>='0'&&c<='9'){ r=(r<<3)+(r<<1)+(c^48); c=getchar(); }
	return r*t;
}
const int N=400010;
int n,t[N][26],l[N],cnt,lst,f[N];
int L[N];
char s[N]; int c[N][26];
int d[N],_d[N];
std::vector<int> e[N]; int R[N];
namespace seg
{
	const int M=10000000;
	int c;
	int t[M][2];
	int clone(int k){ c++; t[c][0]=t[k][0]; t[c][1]=t[k][1]; return c; }
	int modify(int k,int l,int r,int p)
	{
		if(l==r) return k?k:++c;
		k=clone(k); int mid=(l+r)>>1;
		if(p<=mid) t[k][0]=modify(t[k][0],l,mid,p);
		else t[k][1]=modify(t[k][1],mid+1,r,p);
		return k;
	}
	int query(int k,int l,int r,int p)
	{
		if(!k||r<p) return r+1;
		if(l==r) return l;
		int mid=(l+r)>>1,ans=query(t[k][0],l,mid,p);
		if(ans==mid+1) ans=query(t[k][1],mid+1,r,p);
		return ans;
	}
	int Query(int k,int l,int r,int p)
	{
//		printf("%d %d %d  %d\n",k,l,r,p);
		if(!k||l>p) return l-1;
		if(l==r) return l;
		int mid=(l+r)>>1,ans=Query(t[k][1],mid+1,r,p);
		if(ans==mid) ans=Query(t[k][0],l,mid,p);
		return ans;
	}
	int merge(int u,int v)
	{
		if(!u||!v) return u+v;
		int k=++c; t[k][0]=merge(t[u][0],t[v][0]); t[k][1]=merge(t[u][1],t[v][1]);
		return k;
	}
}
void dfs(int u){ for(auto v:e[u]){ dfs(v); R[u]=seg::merge(R[u],R[v]); } }
int _f[N];
int q[N];
int F[N][20];
int Q(int l,int r){ int q=::q[r]; fd(i,19,0) if(::l[F[q][i]]>=r-l+1) q=F[q][i]; return q; }
int query(int p,int l,int r,int op)
{
	int q=Q(l,r); //printf("%d %d %d %d  %d\n",p,l,r,op,p);
	return op==0?seg::Query(R[q],1,n,p):seg::query(R[q],1,n,p+(r-l));
}
int check(int l,int r)
{
	int p=l; int cnt=0;
	while(1)
	{
		int q=query(r,l,p,0)-(p-l); if(p-l==r-q) return p!=r;
		p=query(l,q,r,1); if(p-l==r-q) return p!=r;
	}
}
std::vector<int> D[N];
int main()
{
	n=read(); scanf("%s",s+1); cnt=lst=1;
	fr(i,1,n)
	{
		int np=++cnt,nq,p=lst,q; lst=cnt; int c=s[i]-'a';
		l[np]=i; R[np]=seg::modify(0,1,n,i);
		while(p&&!t[p][c]){ t[p][c]=np; p=f[p]; }
		if(!p){ f[np]=1; continue; }
		q=t[p][c];
		if(l[q]==l[p]+1){ f[np]=q; continue; }
		nq=++cnt; memcpy(t[nq],t[q],sizeof(t[nq])); f[nq]=f[q]; f[q]=f[np]=nq; l[nq]=l[p]+1;
		while(p&&t[p][c]==q){ t[p][c]=nq; p=f[p]; }
	}
	fr(i,1,n){ c[i][s[i]-'a']++; fr(j,0,25) c[i][j]+=c[i-1][j]; }
	fr(i,2,cnt) e[f[i]].push_back(i);
	dfs(1);
	fr(i,2,n) if(D[i].empty()) for(int j=i;j<=n;j+=i) D[j].push_back(i);
	q[0]=1;
	fr(i,1,n) q[i]=t[q[i-1]][s[i]-'a'];
	fr(i,1,cnt) F[i][0]=f[i];
	fr(i,1,19) fr(j,1,cnt) F[j][i]=F[F[j][i-1]][i-1];
	fr(i,1,n)
	{
		d[i]=_d[i]=n+1;
		int p=i;
		while(p>=1)
		{
			int q=query(p-1,p,i,0);
			if(!q) break;
			if(Q(q+1,i)==Q(q-(i-(q+1)),q)){ d[i]=i-q; break; }
			p=q;
		}
		p=i;
		while(p<=n)
		{
			int q=query(p+1,i,p,1);
			if(q>n) break;
			q-=p-i;
//			printf("%d %d %d\n",i,p,q);
			if(Q(i,q-1)==Q(q,q+(q-1-i))){ _d[i]=q-i; break; }
			p=q;
		}
	}
	_f[0]=-1; fr(i,1,n) _f[i]=std::max(_f[i-1],i-d[i]-d[i]);
//	fr(i,1,n) printf("%d%c",d[i],i==n?'\n':' ');
//	fr(i,1,n) printf("%d%c",_d[i],i==n?'\n':' ');
	fr(T,1,read())
	{
		int l=read(),r=read(),ans=-1;
		fr(i,0,25) if(c[r][i]-c[l-1][i]>=2) ans=4;
		if(c[l-1][s[r]-'a']!=c[r-1][s[r]-'a']) ans=3;
		if(c[l][s[l]-'a']!=c[r][s[l]-'a']) ans=3;
		if(_f[r]+1>=l) ans=3;
		if(r-d[r]-d[r]+1>=l) ans=2;
		if(l+_d[l]+_d[l]-1<=r) ans=2;
		if(ans!=2&&check(l,r)) ans=2;
		for(auto i:D[r-l+1])
		{
			if(Q(l,r-(r-l+1)/i)==Q(l+(r-l+1)/i,r)) ans=1;
//			printf("%d %d  %d %d   %d %d\n",l,l+(r-l+1)/i-1,r-(r-l+1)/i+1,r,Q(l,r-(r-l+1)/i),Q(l+(r-l+1)/i,r));
		}
		printf("%d\n",ans);
	}
	return 0;
}