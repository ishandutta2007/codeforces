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
int dp[100100];
void solve()
{
	string s,t;
	cin>>s>>t;
	rev(s);
	rev(t);
	for(int i=1;i<=s.length();i++)
		dp[i]=-1;
	for(int i=0;i<s.length();i++)
		if(dp[i]>=0)
		{
			if(dp[i]<t.length()&&s[i]==t[dp[i]])
				dp[i+1]=max(dp[i+1],dp[i]+1);
			dp[i+2]=max(dp[i+2],dp[i]);
		}
	if(*max_element(dp,dp+1+s.length())==t.length())
		puts("YES");
	else	puts("NO");
	return ;
}
int main()
{
	int t;
	cin>>t;
	while(t--)
		solve();
	return 0;
}