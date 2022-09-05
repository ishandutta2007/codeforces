#include<bits/stdc++.h>
using namespace std;

typedef long long s64;
#define rep(i,l,r) for(int i=l;i<=r;++i)
const int N=30000+2;
bitset<N> get(int l,int r)
{
	bitset<N> all1;
	if(l>r)return all1;
	all1.set();
	return (all1>>(N-1-r))^(all1>>(N-1-(l-1)));
}
int n,b[N];
struct Data
{
	s64 len,ans;
	bitset<N>pre,suf;
};
Data init(int v)
{
	Data x;
	x.len=1;x.ans=(n==1)&&(b[n]>=v);
	rep(i,1,n)x.pre[i]=(b[n-i+1]>=v);
	rep(i,1,n)x.suf[i]=(b[n-i]>=v);
	return x;
}
Data operator +(const Data &l,const Data &r)
{
	Data ans;
	ans.len=l.len+r.len;
	ans.ans=l.ans+r.ans+(l.suf&r.pre&get(max(1LL,n-l.len),min(r.len,n-1LL))).count();
	if(l.len>=n)ans.pre=l.pre;
	else ans.pre=l.pre&(get(1,l.len)|(r.pre<<l.len));
	if(r.len>=n)ans.suf=r.suf;
	else ans.suf=r.suf&(get(n-r.len,n)|(l.suf>>r.len));
	return ans;
}
const int D=20+2,M=60+2,L=60+2;
int d,m,gen[D];
Data dp[L][M];

s64 F(s64 r)
{
	Data ans;
	ans.len=ans.ans=0;
	ans.pre.set();ans.suf.set();
	int v0=0;
	while(r)
	{
		int i=0;
		while(dp[i][0].len<=r/d)++i;
		int j=0;
		while(r>=dp[i][0].len)
		{
			r-=dp[i][0].len;
			ans=ans+dp[i][(v0+gen[j])%m];
			++j;
		}
		(v0+=gen[j])%=m;
	}
	return ans.ans;
}

int main()
{
#ifdef kcz
	freopen("1.in","r",stdin);
#endif
	cin>>d>>m;
	rep(i,0,d-1)scanf("%d",gen+i);	
	cin>>n;
	rep(i,1,n)scanf("%d",b+i);
	s64 l,r;
	cin>>l>>r;
	
	rep(v,0,m-1)dp[0][v]=init(v);
	int i=0;
	while(dp[i][0].len<=r/d)
	{
		++i;
		rep(v,0,m-1)
		{
			dp[i][v]=dp[i-1][v];
			rep(j,1,d-1)dp[i][v]=dp[i][v]+dp[i-1][(v+gen[j])%m];
		}
	}
		
	cout<<F(r)-F(l+n-2);
}