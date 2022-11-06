#include <bits/stdc++.h>
using namespace std;
#define int long long
signed main(){
	cin.tie(nullptr)->sync_with_stdio(false);
	int t;
	cin >> t;
	while(t--){
		int n;
		cin >> n;
		vector<int>b(n+1);
		vector<vector<pair<int,int>>>vals(n+1);
		for(int i = 1; i<=n; i++){
			cin >> b[i];
			int l = 0; int r = 0;
			if(true){
				int low = 0; int high = n+1; int mid = (low+high)/2;
				while(low+1<high){
					if(i/mid<=b[i])high = mid;
					else low = mid;
					mid = (low+high)/2;
				}
				l = high;
			}
			if(true){
				int low = 0; int high = n+1; int mid = (low+high)/2;
				while(low+1<high){
					if(i/mid>=b[i])low = mid;
					else high = mid;
					mid = (low+high)/2;
				}
				r = low;
			}
			//cout << l << " " << r << "\n";
			vals[r].push_back({l,i});
		}
		vector<int>ans(n+1);
		set<pair<int,int>>s;
		for(int i = n; i>=1; i--){
			for(pair<int,int>nxt: vals[i]){
				s.insert(nxt);
			}
			pair<int,int>p = *--s.end();
			ans[p.second] = i;
			s.erase(--s.end());
		}
		for(int i = 1; i<=n; i++){
			cout << ans[i] << " ";
		}
		cout << "\n";
	}
	return 0;
}