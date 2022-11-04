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
		int n;
		cin >> n;
		vi a(n), b(n);
		vi am(n, 0);
		for(int i = 0; i < n; i++) {
			cin >> a[i];
			--a[i];
		}
		for(int i = 0; i < n; i++) {
			cin >> b[i];
			--b[i];
		}
		bool ok = true;
		int pt1 = n - 1;
		int pt2 = n - 1;
		while(pt2 >= 0) {
			if(a[pt1] == b[pt2]) {
				int now = b[pt2];
				int amount2 = 0;
				while(pt2 >= 0 && b[pt2] == now) {
					++amount2;
					--pt2;
				}
				int amount1 = 0;
				while(pt1 >= 0 && a[pt1] == now) {
					++amount1;
					--pt1;
				}
				if(am[now] + amount2 < amount1) {
					ok = false;
					break;
				}
				am[now] = am[now] + amount2 - amount1;
			} else {
				if(am[a[pt1]] == 0) {
					ok = false;
					break;
				}
				--am[a[pt1]];
				--pt1;
			}
		}
		if(ok) {
			cout << "YES\n";
		} else {
			cout << "NO\n";
		}
	}
}