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
		int n, m;
		cin >> n >> m;
		vector<array<int, 3>> a(m);
		ll sum = 0;
		for(int i = 0; i < m; i++) {
			cin >> a[i][1] >> a[i][0];
			sum += a[i][0];
			a[i][2] = i;
		}
		sort(a.begin(), a.end());
		while(a.size() != n * 2) {
			sum -= a.back()[0];
			a.pop_back();
		}
		sort(a.begin(), a.end(), [&](const array<int, 3>& a, const array<int, 3>& b){return a[1] < b[1];});
		cout << sum << '\n';
		for(int i = 0; i < n; i++) {
			cout << a[i][2] + 1 << ' ' << a[2 * n - i - 1][2] + 1 << '\n';
		}
	}
}