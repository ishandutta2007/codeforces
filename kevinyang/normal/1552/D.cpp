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
		vector<int>arr(n+1);
		set<int>s;
		for(int i = 1; i<=n; i++){
			cin >> arr[i];
		}
		bool zero = false;
		for(int i = 1; i<=n; i++){
			s.insert(arr[i]);
			if(arr[i]==0)zero = true;
		}
		if(s.size()<n||zero){
			cout << "YES\n";
			continue;
		}
		bool f = false;
		for(int k = 0; k<n; k++){
			vector<int>arr2;
			for(int i = 0; i<n; i++){
				if(i==k)continue;
				arr2.push_back(arr[i+1]);
			}
			vector<int>q;
			vector<int>q2;
			q.push_back(0);
			for(int i = 0; i<n-1; i++){
				for(int nxt: q){
					q2.push_back(nxt+arr2[i]);
					q2.push_back(nxt);
					q2.push_back(nxt-arr2[i]);
				}
				swap(q,q2);
				q2.clear();
			}
			for(int nxt: q){
				//cout << nxt << " " << arr[k+1] << "\n";
				if(nxt==arr[k+1])f = true;
			}
		}
		if(f)cout << "YES\n";
		else cout << "NO\n";
	}
	return 0;
}