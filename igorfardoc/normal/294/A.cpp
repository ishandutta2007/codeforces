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
	int n;
	cin >> n;
	vi a(n);
	for(int i = 0; i < n; i++) {
		cin >> a[i];
	}
	int m;
	cin >> m;
	for(int i = 0; i < m; i++) {
		int x, y;
		cin >> x >> y;
		--x;
		--y;
		if(x != n - 1) {
			a[x + 1] += a[x] - y - 1;
		}
		if(x != 0) {
			a[x - 1] += y;
		}
		a[x] = 0;
	}
	for(const auto& el : a) {
		cout << el << '\n';
	}
}