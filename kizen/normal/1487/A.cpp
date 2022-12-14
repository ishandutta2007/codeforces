#include <bits/stdc++.h>

using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int t;
	cin >> t;
	while(t--){
		int n;
		cin >> n;
		vector<int> a(n);
		int mn = (int)1e9;
		for(int i = 0; i < n; ++i){
			cin >> a[i];
			mn = min(mn, a[i]);
		}
		int ans = 0;
		for(int i = 0; i < n; ++i){
			if(a[i] > mn){
				++ans;
			}
		}
		cout << ans << '\n';
	}
	return 0;
}