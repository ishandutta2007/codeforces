#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef vector<long long> vl;



int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	#ifdef _FILE
		freopen("input.txt", "r", stdin);
		freopen("output.txt", "w", stdout);
	#endif
	int t;
	cin >> t;
	while(t--) {
		vi x(3), y(3);
		for(int i = 0; i < 3; i++) {
			cin >> x[i] >> y[i];
		}
		int ans = 0;
		for(int i = 0; i < 3; i++) {
			int j = (i + 1) % 3;
			int other = (i + 2) % 3;
			if(y[i] != y[j]) continue;
			if(y[other] < y[i]) {
				ans = abs(x[i] - x[j]);
			}
		}
		cout << ans << '\n';
	}
}