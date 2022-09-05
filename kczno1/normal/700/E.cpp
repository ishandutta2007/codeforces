#include<bits/stdc++.h>
using namespace std;

template <typename T> void chmax(T &x,const T &y)
{
	if(x<y)x=y;
}
template <typename T> void chmin(T &x,const T &y)
{
	if(x>y)x=y;
}
typedef pair<int,int> pii;
#define rep(i,l,r) for(int i=l;i<=r;++i)
#define per(i,r,l) for(int i=r;i>=l;--i)
const int N=2e5+5,L=18;
char s[N];
int n,r[N],dp[N];

int sa[N],qa[2][N],*rk=qa[0],*tmp=qa[1],cnt[N],h[N],mn_h[L][N];
void init_sa()
{
	rep(i,1,n)++cnt[s[i]-'a'+1];
	rep(i,1,26)cnt[i]+=cnt[i-1];
	per(i,n,1)sa[cnt[s[i]-'a'+1]--]=i;
	rk[sa[1]]=1;
	rep(i,2,n)rk[sa[i]]=rk[sa[i-1]]+(s[sa[i]]!=s[sa[i-1]]);
	for(int l=1,m;(m=rk[sa[n]])<n;l<<=1)
	{
		int top=0;
		rep(i,n-l+1,n)tmp[++top]=i;
		rep(i,1,n)
		if(sa[i]>l)tmp[++top]=sa[i]-l;
		
		rep(i,1,m)cnt[i]=0;
		rep(i,1,n)++cnt[rk[i]];
		rep(i,1,m)cnt[i]+=cnt[i-1];
		per(i,n,1)sa[cnt[rk[tmp[i]]]--]=tmp[i];
		
		swap(rk,tmp);
		rk[sa[1]]=1;
		rep(i,2,n)rk[sa[i]]=rk[sa[i-1]]+(tmp[sa[i]]!=tmp[sa[i-1]]
			||tmp[sa[i]+l]!=tmp[sa[i-1]+l]); 
//		rep(i,1,n)cerr<<sa[i]<<" ";cerr<<endl;
//		rep(i,1,n)cerr<<rk[i]<<" ";cerr<<endl;
//		exit(0);
	}
//	rep(i,1,n)cerr<<sa[i]<<" ";cerr<<endl;
//	rep(i,1,n)cerr<<rk[i]<<" ";cerr<<endl;
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
//	rep(i,1,n)cerr<<sa[i]<<" ";cerr<<endl;
}
pii get_seg(int i,int len)
{
	int l=i;
	per(j,L-1,0)
	if(l-(1<<j)>=1&&mn_h[j][l-(1<<j)]>=len)l-=1<<j;
	int r=i;
	per(j,L-1,0)
	if(r+(1<<j)<=n&&mn_h[j][r]>=len)r+=1<<j;
//	cerr<<i<<" "<<len<<" "<<l<<" "<<r<<endl;
	return {l,r};
}
namespace ZKW
{
const int T=N*3;
int d,mn[T];pii mx[T];//min_j max_{r_j,dp_j}
void init()
{
	for(d=1;d<n;d<<=1);d-=1;
	rep(i,1,n+d+1)mn[i]=N;
}
pii query_mx(int i)
{
	i+=d;
	pii ans=mx[i];
	while(i>>=1)chmax(ans,mx[i]);
	return ans;
}
int query_mn(pii seg)
{
	int l=seg.first+d,r=seg.second+d;
	int ans=min(mn[l],mn[r]);
	if(l==r)return ans;
	while(l+1!=r)
	{
		if(l%2==0)chmin(ans,mn[l+1]);
		if(r%2)chmin(ans,mn[r-1]);
		l>>=1;r>>=1;
	}
	return ans;
}
void set_mx(pii seg,pii x)
{
	int l=seg.first+d,r=seg.second+d;
	chmax(mx[l],x);chmax(mx[r],x);
	if(l==r)return ;
	while(l+1!=r)
	{
		if(l%2==0)chmax(mx[l+1],x);
		if(r%2)chmax(mx[r-1],x);
		l>>=1;r>>=1;
	}
}
void set_mn(int i,int x)
{
	i+=d;
	while(mn[i]>x){mn[i]=x;i>>=1;}
}
};

int main()
{
#ifdef kcz
	freopen("1.in","r",stdin);
#endif
	cin>>n;
	scanf("%s",s+1);
	init_sa();
	ZKW::init();
	per(i,n,1)
	{
		pii mx=ZKW::query_mx(rk[i]);
		if(!mx.first)dp[i]=r[i]=1;
		else
		{
			dp[i]=mx.second+1;
			r[i]=ZKW::query_mn(get_seg(rk[i],mx.first))-i+mx.first;
		}
		ZKW::set_mx(get_seg(rk[i],r[i]),{r[i],dp[i]}); 
		ZKW::set_mn(rk[i],i);
		//cerr<<dp[i]<<" "<<r[i]<<endl;
	}
	int mx=0;
	rep(i,1,n)chmax(mx,dp[i]);
	cout<<mx;
}