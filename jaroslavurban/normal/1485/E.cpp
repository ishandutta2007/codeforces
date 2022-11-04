#define _USE_MATH_DEFINES
#include <bits/stdc++.h>
using namespace std;

// bool xd=any_of(a.begin(),a.end(),[&](int x){return x==9;});
// all_of, none_of
// int cnt=count(a.begin(),a.end(),x);
// bool found=binary_search(a.begin(),a.end(),x); true if x in sorted array
// int xd=*max_element(a.begin(),a.end());
// min_element

typedef long long ll;
typedef long double ld;


const int N=200100;
vector<int>g[N];
int n;
int a[N],dpt[N],pos[N],par[N];
ll dpval[N];
vector<vector<int>>dp;
vector<vector<ll>>mxl,mxr;

void dod(int u,int p,int d){
	if(dp.size()==d)dp.push_back({});
	dpt[u]=d;
	par[u]=p;
	dp[d].push_back(u);
	for(auto v:g[u])if(v!=p)dod(v,u,d+1);
}

ll getdp(int u,int mul);

ll getv(int u){
	ll res=0;
	// i'm giving the kid
	res=max(res,a[dp[dpt[u]].back()]+getdp(u,-1));
	res=max(res,-a[*dp[dpt[u]].begin()]+getdp(u,+1));
	// he is
	res=max(res,mxl[dpt[u]][pos[u]]+a[u]);
	res=max(res,mxr[dpt[u]][pos[u]]-a[u]);
	return res;
}

ll getdp(int u,int mul){
	if(~dpval[u])return dpval[u]+(a[u]*mul);
	if(!u+g[u].size()<=1)return (dpval[u]=0)+a[u]*mul;
	for(auto v:g[u])if(v!=par[u])dpval[u]=max(getv(v),dpval[u]);
	return dpval[u]+(a[u]*mul);
}


main(){
	cin.tie(0);ios::sync_with_stdio(0);
	int tc;cin>>tc;
	while(tc--){
		dp.clear();
		mxl.clear();
		mxr.clear();
		cin>>n;
		for(int i=0;i<n;++i)g[i].clear();
		set<pair<int,int>>got;
		memset(dpval,-1,sizeof(*dpval)*n);
		for(int i=1;i<n;++i){
			int v;cin>>v;--v;
			if(got.count({i,v}))continue;
			got.insert({i,v});
			got.insert({v,i});
			g[i].push_back(v);
			g[v].push_back(i);
		}
		for(int i=1;i<n;++i)cin>>a[i];
		dod(0,0,0);
		mxl.resize(dp.size());
		mxr.resize(dp.size());
		for(int i=0;i<dp.size();++i){
			sort(dp[i].begin(),dp[i].end(),[&](int x,int y){
				return a[x]<a[y];
			});
			for(int j=0;j<dp[i].size();++j)pos[dp[i][j]]=j;
			mxl[i].resize(dp[i].size());
			mxr[i].resize(dp[i].size());
		}
		for(int i=dp.size()-1;i>=0;--i){
			for(int j=0;j<dp[i].size();++j){
				mxl[i][j]=max(j?mxl[i][j-1]:ll(-1e18),getdp(dp[i][j],-1));
			}
			for(int j=dp[i].size()-1;j>=0;--j)
				mxr[i][j]=max(j<dp[i].size()-1?mxr[i][j+1]:ll(-1e18),getdp(dp[i][j],+1));
		}
		cout<<getdp(0,1)<<endl;
	}
}