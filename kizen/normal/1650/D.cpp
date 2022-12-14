#include <bits/stdc++.h>
#define int long long
#define mi(x, y) (x = min(x, y))
#define ma(x, y) (x = max(x, y))
using namespace std;

signed main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int t; cin >> t;
	while(t--){
		int n; cin >> n;
		vector<int> a(n);
		for(auto&i:a){
			cin >> i;
		}
		vector<int> out;
		for(int i = n - 1; i >= 0; --i){
			int ans = 0;
			while(a[i] != i + 1){
				int imsi = a[0];
				for(int j = 0; j < i; ++j){
					a[j] = a[j + 1];
				}
				a[i] = imsi;
				++ans;
			}
			out.push_back(ans);
		}
		reverse(out.begin(), out.end());
		for(auto&i:out) cout << i << ' ';
		cout << '\n';
	}
	return 0;
}