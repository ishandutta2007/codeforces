#include<bits/stdc++.h>
//AtCoder Library
//#define ATCODER
#ifdef ATCODER
#include<atcoder/convolution.hpp>
#include<atcoder/dsu.hpp>
#include<atcoder/fenwicktree.hpp>
#include<atcoder/internal_bit.hpp>
#include<atcoder/internal_math.hpp>
#include<atcoder/internal_queue.hpp>
#include<atcoder/internal_scc.hpp>
#include<atcoder/internal_type_traits.hpp>
#include<atcoder/lazysegtree.hpp>
#include<atcoder/math.hpp>
#include<atcoder/maxflow.hpp>
#include<atcoder/mincostflow.hpp>
#include<atcoder/modint.hpp>
#include<atcoder/scc.hpp>
#include<atcoder/segtree.hpp>
#include<atcoder/string.hpp>
#include<atcoder/twosat.hpp>
using namespace atcoder;
#endif
using namespace std;
#define ll long long
#define pb push_back
#define mp make_pair
#define ALL(x) (x).begin(),(x).end()
#define rALL(x) (x).rbegin(),(x).rend()
#define srt(x) sort(ALL(x))
#define rev(x) reverse(ALL(x))
#define rsrt(x) sort(rALL(x))
#define sz(x) (int)(x.size())
void die(string S){puts(S.c_str());exit(0);}
int dp[2020][2020];
int a[2020];
void solve()
{
	int n,k;
	cin>>n>>k;
	for(int i=0;i<n;i++)
		cin>>a[i];
	for(int i=0;i<=n;i++)
		for(int j=0;j<=n;j++)
			dp[i][j]=0;
	for(int i=0;i<n;i++)
		for(int j=0;j<=n;j++)
		if(dp[i][j]!=n+1)
		{
//			cout<<i<<" "<<j<<" "<<used<<" "<<nxt[i][used+1]<<" "<<dp[i][j]<<endl;
			dp[i+1][j]=max(dp[i+1][j],dp[i][j]);
			dp[i+1][j+1]=max(dp[i+1][j+1],dp[i][j]);
			if(a[i]==i-j+1)
				dp[i+1][j]=max(dp[i+1][j],dp[i][j]+1);
		}
	for(int i=0;i<=n;i++)
		if(dp[n][i]>=k)
		{
			cout<<i<<endl;
			return ;
		}
	puts("-1");
}
int main()
{
	int t;
	cin>>t;
	while(t--)
		solve();
	return 0;
}