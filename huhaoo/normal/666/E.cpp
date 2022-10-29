/***************************************************************
	File name: E.cpp
	Author: huhao
	Create time: Tue 17 Dec 2019 05:47:34 PM CST
***************************************************************/
#include<stdio.h>
#include<string.h>
#include<math.h>
#include<algorithm>
#define fr(i,a,b) for(int i=(a),end_##i=(b);i<=end_##i;i++)
#define fd(i,a,b) for(int i=(a),end_##i=(b);i>=end_##i;i--)
int read()
{
	int r=0,t=1,c=getchar();
	while(c<'0'||c>'9')
	{
		t=c=='-'?-1:1;
		c=getchar();
	}
	while(c>='0'&&c<='9')
	{
		r=r*10+c-48;
		c=getchar();
	}
	return r*t;
}
const int N=500010,L=20;
#define pii std::pair<int,int>
namespace seg
{
	const int M=40000010;
	int s[M][2],cnt;
	pii m[M];
	void update(int k){ m[k]=std::max(m[s[k][0]],m[s[k][1]]); }
	void Modify(int &k,int l,int r,int p)
	{
		if(!k) k=++cnt;
		if(l==r){ m[k].first++; m[k].second=-l; return ; }
		int mid=(l+r)>>1;
		if(p<=mid) Modify(s[k][0],l,mid,p);
		else Modify(s[k][1],mid+1,r,p);
		update(k);
	}
	int Sum(int a,int b,int l,int r)
	{
		if(!a||!b) return a+b;
		int k=++cnt;
		if(l==r){ m[k]=pii(m[a].first+m[b].first,-l); }
		else
		{
			int mid=(l+r)>>1;
			s[k][0]=Sum(s[a][0],s[b][0],l,mid);
			s[k][1]=Sum(s[a][1],s[b][1],mid+1,r);
			update(k);
		}
		return k;
	}
	pii Max(int k,int l,int r,int L,int R)
	{
		if(!k||l>R||L>r) return pii(-1,0);
		if(L<=l&&r<=R) return m[k];
		int mid=(l+r)>>1;
		return std::max(Max(s[k][0],l,mid,L,R),Max(s[k][1],mid+1,r,L,R));
	}
}
int n,m,lst,cnt,t[N][26],r[N],Q[N],_l,_r,dg[N],F[N][L+5],p[N],q,l[N],f[N],ml[N];
char s[N],c[N];
void attend(int id,int c)
{
	int p=lst,np=++cnt,q,nq;
	l[np]=l[p]+1; seg::Modify(r[np],1,m,id); lst=np;
	while(p&&!t[p][c]){ t[p][c]=np; p=f[p]; }
	if(!p){ f[np]=1; return; }
	q=t[p][c];
	if(l[q]==l[p]+1){ f[np]=q; return; }
	nq=++cnt; f[nq]=f[q]; f[q]=f[np]=nq; l[nq]=l[p]+1;
	memcpy(t[nq],t[q],sizeof(t[nq]));
	while(p&&t[p][c]==q){ t[p][c]=nq; p=f[p] ; }
}
int main()
{
	scanf("%s",s+1); n=strlen(s+1);
	m=read(); cnt=1;
	fr(i,1,m)
	{
		scanf("%s",c+1); lst=1;
		fr(j,1,strlen(c+1)) attend(i,c[j]-'a');
	}
	fr(i,2,cnt) dg[f[i]]++;
	fr(i,1,cnt) if(!dg[i]) Q[++_r]=i;
	_l=1;
	while(_l<=_r)
	{
		int u=Q[_l++]; dg[f[u]]--;
		if(!dg[f[u]]) Q[++_r]=f[u];
	}
	fr(i,1,cnt-1) r[f[Q[i]]]=seg::Sum(r[f[Q[i]]],r[Q[i]],1,m);
	fr(i,1,cnt) F[i][0]=f[i];
	fr(i,1,L) fr(j,1,cnt) F[j][i]=F[F[j][i-1]][i-1];
	p[0]=1; ml[0]=0;
	fr(i,1,n)
	{
		p[i]=p[i-1]; ml[i]=ml[i-1];
		while(p[i]&&!t[p[i]][s[i]-'a']){ p[i]=f[p[i]]; ml[i]=l[p[i]]; }
		if(p[i]){ p[i]=t[p[i]][s[i]-'a']; ml[i]++; }
		else p[i]=1;
	}
	q=read();
	while(q--)
	{
		int cl=read(),cr=read(),sl=read(),sr=read(),ls=sr-sl+1;
		if(ml[sr]<ls){ printf("%d 0\n",cl); continue; }
		int u=p[sr];
		fd(i,L,0) if(l[F[u][i]]>=ls) u=F[u][i];
		pii ans=seg::Max(r[u],1,m,cl,cr);
		if(ans.first<=0) printf("%d 0\n",cl);
		else printf("%d %d\n",-ans.second,ans.first);
	}
	return 0;
}