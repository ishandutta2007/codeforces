#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	int n, k;
	cin >> n >> k;
	map<int, int> mp;
	for (int i=0; i<n; i++) {
		int x;
		cin >> x;
		mp[x] += 1;
	}
	int drinks = (n+1)/2, ok = 0;
	for (auto [x, y] : mp) {
		drinks -= y / 2;
		ok += y / 2 * 2;
	}

	for (auto [x, y] : mp) {
		if (y % 2 && drinks > 0) {
			drinks--;
			ok++;
		}
	}

	cout << ok << '\n';
}