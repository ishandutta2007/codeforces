#define _USE_MATH_DEFINES
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;

const int N=200100;
int g[N];
ll w[N];
int n;

main(){
	cin.tie(0);cin.sync_with_stdio(0);
	int tc;cin>>tc;
	while(tc--){
		cin>>n;
		vector<int>g(n);
		for(int i=0;i<n;++i)cin>>w[i];
		for(int i=0;i<n-1;++i){
			int u,v;cin>>u>>v;--u;--v;
			++g[u];++g[v];
		}
		vector<pair<ll,int>>ver(n);
		for(int i=0;i<n;++i)ver[i]={w[i],g[i]};
		sort(ver.rbegin(),ver.rend());
		ll sm=accumulate(w,w+n,0ll);
		cout<<sm<<" ";
		for(int i=0;i<n;++i){
			while(ver[i].second-->1){
				sm+=ver[i].first;
				cout<<sm<<" ";
			}
		}
		cout<<endl;
	}
}