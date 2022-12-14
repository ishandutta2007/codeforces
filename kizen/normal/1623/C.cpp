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
		for(int i = 0; i < n; ++i){
			cin >> a[i];
		}
		int low = 0, high = (int)1e9, mid;
		while(low < high){
			mid = (low + high) / 2 + 1;
			auto b = a;
			for(int i = n - 1; i >= 2; --i){
				int can = min(a[i], max(0ll, b[i] - mid)) / 3;
				b[i - 2] += can * 2, b[i - 1] += can, b[i] -= can * 3;
			}
			int f = 1;
			for(int i = 0; i < n; ++i){
				if(b[i] < mid){
					f = 0;
					break;
				}
			}
			if(f){
				low = mid;
			}
			else{
				high = mid - 1;
			}
		}
		cout << low << '\n';
	}
	return 0;
}