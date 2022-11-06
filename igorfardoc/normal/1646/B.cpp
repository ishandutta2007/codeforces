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
		vi a(n);
		for(int i = 0; i < n; i++) cin >> a[i];
		sort(a.begin(), a.end());
		ll fir = 0;
		ll sec = 0;
		int am1 = (n - 1) / 2 + 1;
		int am2 = am1 - 1;
		for(int i = 0; i < am1; i++) {
			fir += a[i];
		}
		for(int i = 0; i < am2; i++) {
			sec += a[n - i - 1];
		}
		if(fir < sec) {
			cout << "YES\n";
		} else {
			cout << "NO\n";
		}
	}
}