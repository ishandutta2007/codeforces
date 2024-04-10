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
int cnt[300300];
int res[300300];
bool vis[300300];
int n,m;
int dfs(int x,int k,int goal)
{
	vis[x]++;
	if(res[(x+k)%n]==goal)
		return 0;
	return dfs(res[(x+k)%n],k,goal)+1;
}
void solve()
{
	cin>>n>>m;
	for(int i=0;i<=n;i++)
		cnt[i]=vis[i]=0;
	for(int i=0;i<n;i++)
	{
		cin>>res[i];
		res[i]--;
	}
	for(int i=0;i<n;i++)
		cnt[(i-res[i]+n)%n]++;
	vector<int> vk;
	for(int i=0;i<n;i++)
		if(cnt[i]>=n-m-m)
			vk.pb(i);
	vector<int> res1;
	for(int i=0;i<sz(vk);i++)
	{
		int k=vk[i];
		for(int j=0;j<n;j++)
			vis[j]=0;
		int ans=0;
		for(int j=0;j<n;j++)
			if(!vis[j])
				ans+=dfs(j,k,j);
		if(ans<=m)
			res1.pb(k);
	}
	cout<<sz(res1)<<" ";
	for(int i=0;i<sz(res1);i++)
		cout<<res1[i]<<" ";
	puts("");
	return ;
}
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		solve();
	}
	return 0;
}