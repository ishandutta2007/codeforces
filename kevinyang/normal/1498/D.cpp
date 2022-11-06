#include <bits/stdc++.h>
using namespace std;
#define int long long
signed main(){
	cin.tie(nullptr)->sync_with_stdio(false);
	int n,m;
	cin >> n >> m;
	vector<pair<int,int>>dis(m+1,make_pair((int)1e18,0));
	dis[0] = {0,0};
	for(int d = 1; d<=n; d++){
		int t,x1,y;
		cin >> t >> x1 >> y;
		for(int i = 0; i<m; i++){
			if(t==1){
				int v = (100000*i+x1+99999)/100000;
				if(dis[i]<make_pair(d,y)&&v<=m){
					if(dis[i].first<d)dis[v] = min(dis[v],make_pair(d,1LL));
					else dis[v] = min(dis[v],make_pair(d,dis[i].second+1));
				}
			}
			else{
				int v = (i*x1+99999)/100000;
				if(dis[i]<make_pair(d,y)&&v<=m){
					if(dis[i].first<d)dis[v] = min(dis[v],make_pair(d,1LL));
					else dis[v] = min(dis[v],make_pair(d,dis[i].second+1));
				}
			}
		}
	}
	for(int i = 1; i<=m; i++){
		if(dis[i].first==(int)1e18)cout << -1 << " ";
		else cout << dis[i].first << " ";
	}
	cout << "\n";
	return 0;
}