#include <bits/stdc++.h>
using namespace std;
#define int long long
signed main(){
	cin.tie(nullptr)->sync_with_stdio(false);
	int t;
	cin >> t;
	while(t--){
		int n,k;
		cin >> n >> k;
		set<int>s;
		for(int i = 1; i<=2*n; i++){
			s.insert(i);
		}
		vector<pair<int,int>>arr;
		for(int i = 0; i<k; i++){
			int x,y;
			cin >> x >> y;
			if(x>y)swap(x,y);
			s.erase(x); s.erase(y);
			arr.push_back({x,y});
		}
		vector<int>rem;
		for(int nxt: s)rem.push_back(nxt);
		for(int i = 0; i<rem.size()/2; i++){
			int x = rem[i]; int y = rem[i+rem.size()/2];
			arr.push_back({x,y});
			//cout << x << " " << y << "\n";
		}
		assert(arr.size()==n);
		int ans = 0;
		for(int i = 0; i<n; i++){
			for(int j = i+1; j<n; j++){
				vector<int>a;
				a.push_back(arr[i].first);
				a.push_back(arr[j].first);
				a.push_back(arr[i].second);
				a.push_back(arr[j].second);
				sort(a.begin(),a.end());
				if(arr[i].first==a[0]&&arr[i].second==a[2])ans++;
				if(arr[i].first==a[1]&&arr[i].second==a[3])ans++;
			}
		}
		cout << ans << "\n";
	}
	return 0;
}