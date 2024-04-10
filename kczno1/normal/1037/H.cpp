#include<bits/stdc++.h>
using namespace std;

typedef pair<int,int> pii;
#define rep(i,l,r) for(int i=l;i<=r;++i)
#define per(i,r,l) for(int i=r;i>=l;--i)
const int N=5e5+5,L=20;
char s[N];int n;
int sa[N],qa[2][N],*rk=qa[0],*tmp=qa[1],cnt[N],h[N],mn_h[L][N],lo[N];
void init_sa()
{
	rep(i,1,n)sa[i]=i;
	sort(sa+1,sa+n+1,[&](int x,int y){return s[x]<s[y];});
	rk[sa[1]]=1;
	rep(i,2,n)rk[sa[i]]=rk[sa[i-1]]+(s[sa[i]]!=s[sa[i-1]]);
	for(int l=1;rk[sa[n]]<n;l<<=1)
	{
		int top=0;
		rep(i,n-l+1,n)tmp[++top]=i;
		rep(i,1,n)
		if(sa[i]>l)tmp[++top]=sa[i]-l;
		
		int m=rk[sa[n]];
		rep(i,1,m)cnt[i]=0;
		rep(i,1,n)++cnt[rk[i]];
		rep(i,1,m)cnt[i]+=cnt[i-1];
		per(i,n,1)sa[cnt[rk[tmp[i]]]--]=tmp[i];
		
		swap(rk,tmp);
		rk[sa[1]]=1;
		rep(i,2,n)rk[sa[i]]=rk[sa[i-1]]+(tmp[sa[i]]!=tmp[sa[i-1]]||tmp[sa[i]+l]!=tmp[sa[i-1]+l]);
	}
	int l=0;
	rep(i,1,n)
	{
		if(l)--l;
		while(s[i+l]==s[sa[rk[i]+1]+l])++l;
		h[rk[i]]=l;
	}
	rep(i,1,n)mn_h[0][i]=h[i];
	rep(j,1,L-1)
	rep(i,1,n-(1<<j)+1)mn_h[j][i]=min(mn_h[j-1][i],mn_h[j-1][i+(1<<j-1)]);
	lo[0]=-1;
	rep(i,2,n)lo[i]=lo[i/2]+1;
}
int query_mn_h(int l,int r)
{
	int j=lo[r-l+1];
	return min(mn_h[j][l],mn_h[j][r-(1<<j)+1]);
}
namespace ZKW
{
const int T=N*3;
int mn[T],d;
void init()
{
	for(d=1;d<n;d<<=1);d-=1;
	rep(i,1,n+d+1)mn[i]=N;
}
void add(int i,int x)
{
	i+=d;
	while(mn[i]>x){mn[i]=x;i>>=1;}
}
int query(int i,int x)
{
	i+=d;
	while(i)
	{
		if(i%2==0&&mn[i+1]<=x)
		{
			++i;
			while(i<=d)i=i*2+(mn[i*2]>x);
			return i-d;
		}
		i>>=1;
	}
	return N;
}
};
int m,fir[N],qr[N];
pii ans[N];
vector<int>lkq[N];

int main()
{
#ifdef kcz
	freopen("1.in","r",stdin);
#endif
	scanf("%s",s+1);
	n=strlen(s+1);
	cin>>m;
	rep(i,1,m)
	{
		fir[i]=++n;
		int l;
		scanf("%d%d%s",&l,qr+i,s+n);
		lkq[l].push_back(i);
		n+=strlen(s+n);
		s[n]=1;
	}
	fir[m+1]=n+1;
	init_sa();
	ZKW::init();
	per(l,fir[1]-1,1)
	{
		ZKW::add(rk[l],l);
		for(auto i:lkq[l])
		{
			int r=qr[i];
			int x=rk[fir[i]],len=fir[i+1]-fir[i]-1;
			per(lcp,len,0)
			{
				int x1=x;
				per(j,L-1,0)
				if(mn_h[j][x1]>lcp)x1+=1<<j;
				int j=ZKW::query(x1,r-lcp);  
				if(j<=n&&query_mn_h(x,j-1)==lcp)
				{
					ans[i].first=sa[j];
					ans[i].second=ans[i].first+lcp;
					break;
				}
			}
		}
	}
	rep(i,1,m)
	if(!ans[i].second)puts("-1");
	else 
	{
		rep(j,ans[i].first,ans[i].second)printf("%c",s[j]);
		puts("");
	}
}