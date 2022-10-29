/***************************************************************
	File name: F.cpp
	Author: huhao
	Create time: Sat 29 May 2021 02:55:43 PM CST
***************************************************************/
#include<stdio.h>
#include<string.h>
#include<math.h>
#include<algorithm>
#include<assert.h>
#define i64 long long
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
const int N=300010;
struct Hash
{
	i64 h[N],p[N],mod,n;
	Hash(){ memset(h,0,sizeof(h)); memset(p,0,sizeof(p)); }
	void init(int N,i64 sed,i64 Mod,char *s)
	{
		Hash(); n=N; mod=Mod; p[0]=1;
		fr(i,1,n) p[i]=p[i-1]*sed%mod;
		fr(i,1,n) h[i]=(h[i-1]+p[i]*s[i])%mod;
	}
	bool operator()(i64 p1,i64 p2,i64 l){ if(p1>p2) std::swap(p1,p2); return p2+l-1<=n&&((h[p1+l-1]-h[p1-1])*p[p2-p1]-(h[p2+l-1]-h[p2-1]))%mod==0; }
} h1,h2;
int n,l[N],r[N],f[N],t[N][26],c,lst;
int sa[N],rk[N];
char s[N];
int Q[N],L,R,d[N];
i64 ans,Ans[N];
#include<set>
std::set<int> S[N];
int lcs(int p1,int p2)
{
	int l=1,r=n-p1+2;
	while(l<r)
	{
		int mid=(l+r)>>1;
		if(h1(p1,p2,mid)&&h2(p1,p2,mid)) l=mid+1;
		else r=mid;
	}
	return l-1;
}
int cmp(int x,int y)
{
	int l=lcs(x,y);
//	printf("%d %d  %d %c %c  %d %d\n",x,y,l,s[x+l],s[y+l],h1(x,y,l+1),h2(x,y,l+1));
//	assert(s[x+l]!=s[y+l]);
	return s[x+l]<s[y+l];
}
void add(int C,int i)
{
	int p=lst,q,np=++c,nq; l[np]=l[p]+1; r[np]=i; lst=np;
	while(p&&!t[p][C]){ t[p][C]=np; p=f[p]; }
	if(!p){ f[np]=1; return ; }
	q=t[p][C];
	if(l[q]==l[p]+1){ f[np]=q; return ; }
	nq=++c; f[nq]=f[q]; f[q]=f[np]=nq; memcpy(t[nq],t[q],sizeof(t[nq])); l[nq]=l[p]+1;
	while(p&&t[p][C]==q){ t[p][C]=nq; p=f[p]; }
}
std::set<int>::iterator a1(std::set<int>::iterator it){ return ++it; }
std::set<int>::iterator d1(std::set<int>::iterator it){ return --it; }
void ins(int i,int p)
{
//	printf("+ %d %d\n",i,sa[p]);
	auto it=S[i].insert(p).first; Ans[i]+=n-sa[p]+1;
//	printf(" %d %d\n",it!=S[i].begin(),a1(it)!=S[i].end());
	if(it!=S[i].begin()&&a1(it)!=S[i].end()) Ans[i]+=lcs(sa[*d1(it)],sa[*a1(it)]);
	if(it!=S[i].begin()) Ans[i]-=lcs(sa[*d1(it)],sa[*it]);
	if(a1(it)!=S[i].end()) Ans[i]-=lcs(sa[*it],sa[*a1(it)]);
}
int main()
{
	scanf("%s",s+1); n=strlen(s+1); c=lst=1;
	if(n==1){ printf("3\n"); return 0; }
	fr(i,1,n) add(s[i]-'a',0);
	l[0]=-1;
	fr(i,1,c) ans+=l[i]-l[f[i]];
//	fr(i,1,c) printf("%d %d\n",l[i],f[i]);
//	printf("%lld\n",ans);
	c=lst=1; memset(f,0,sizeof(f)); memset(t,0,sizeof(t)); memset(l,0,sizeof(l)); memset(r,0,sizeof(r));
	fr(i,1,n-1) add(s[i]-'a',i);
	l[0]=-1;
	fr(i,1,c) ans+=l[i]-l[f[i]];
//	printf("%lld\n",ans);
	h1.init(n,10007,998244353,s); h2.init(n,233,1000000007,s);
	fr(i,1,n) sa[i]=i;
	std::sort(sa+1,sa+n+1,cmp);
	fr(i,1,n) rk[sa[i]]=i;
	L=1; fr(i,2,c) d[f[i]]++;
	fr(i,1,c) if(!d[i]) Q[++R]=i;
	while(L<=R)
	{
		int u=Q[L++];
		if(f[u]){ d[f[u]]--; if(!d[f[u]]) Q[++R]=f[u]; }
	}
//	fr(i,1,c) printf("%d%c",f[i],i==c?'\n':' ');
//	fr(i,1,R) printf("%d%c",Q[i],i==R?'\n':' ');
	fr(i,1,c) if(r[i]&&r[i]!=n-1) ins(i,rk[r[i]+2]);
	ins(1,rk[2]);
	fr(i,1,R)
	{
		int u=Q[i],v=f[u]; ans+=(l[u]-l[f[u]])*Ans[u];
//		printf("%d %lld  %d %d\n",u,Ans[u],l[u],l[f[u]]);
		if(v)
		{
			if(S[u].size()>S[v].size()){ std::swap(S[u],S[v]); std::swap(Ans[u],Ans[v]); }
			for(auto i:S[u]) ins(v,i);
			S[u].clear(); Ans[u]=0;
		}
	}
//	for(auto i:S[1]) printf("%d ",sa[i]);; putchar(10);
	printf("%lld\n",ans);
	return 0;
}