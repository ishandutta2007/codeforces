#include <bits/stdc++.h>
using namespace std;
#define int long long
#define x first
#define y second
signed main(){
	cin.tie(nullptr)->sync_with_stdio(false);
	int n,k;
	cin >> n >> k;
	int rq = (n+k-2)/(k-1);
	vector<int>arr(n*k+1);
	for(int i = 1; i<=n*k; i++){
		cin >> arr[i];
	}
	set<pair<pair<int,int>,int>>s;
	for(int i = 1; i<=n; i++){
		int idx = 0;
		for(int j = 1; j<=n*k; j++){
			if(arr[j]==i){
				idx = j;
				break;
			}
		}
		int idx2 = 0;
		for(int j = idx+1; j<=n*k; j++){
			if(arr[j]==i){
				idx2 = j;
				break;
			}
		}
		s.insert({{idx,idx2},i});
	}
	int cur = 0;
	map<int,pair<int,int>>ans;
	set<pair<int,int>>s2;
	for(int i = 1; i<=n*k; i++){
		while(s.size()&&(*s.begin()).x.x==i){
			auto p = *s.begin();
			s.erase(s.begin());
			cur++;
			s2.insert({p.x.y,p.y});
		}
		while(cur>rq){
			cur--;
			auto p = *--s2.end();
			s2.erase(p);
			int idx = 0;
			for(int j = p.first+1; j<=n*k; j++){
				if(arr[j]==p.y){
					idx = j;
					break;
				}
			}
			s.insert({{p.x,idx},p.y});
		}
		while(s2.size()&&(*s2.begin()).x==i){
			auto p = *s2.begin();
			s2.erase(p);
			cur--;
			int idx = 0;
			for(int j = p.x-1; j>=1; j--){
				if(arr[j]==p.y){
					idx = j;
					break;
				}
			}
			ans[p.y] = {idx,p.x};
		}
	}
	for(int i = 1; i<=n; i++){
		cout << ans[i].first << " " << ans[i].second << "\n";
	}
	return 0;
}