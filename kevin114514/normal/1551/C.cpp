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
int n;
string s[200200];
int calc(char target)
{
	vector<int> v;
	for(int i=0;i<n;i++)
	{
		int cnt=0;
		for(int j=0;j<s[i].length();j++)
			if(s[i][j]==target)
				cnt++;
			else	cnt--;
		v.pb(cnt);
	}
	rsrt(v);
	int len=0,cnt=0;
	for(int i=0;i<n;i++)
		if(cnt+v[i]>0)
		{
			cnt+=v[i];
			len++;
		}
	return len;
}
void solve()
{
	cin>>n;
	for(int i=0;i<n;i++)
		cin>>s[i];
	int ans=0;
	for(char c='a';c<'f';c++)
		ans=max(ans,calc(c));
	cout<<ans<<endl;
}
int main()
{
	int t;
	cin>>t;
	while(t--)
		solve();
	return 0;
}