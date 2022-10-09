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

	int n;
	cin >> n;
	map<int, int> mp;
	for (int i=0; i<n; i++) {
		int x;
		cin >> x;
		mp[x]++;
	}
	int sol = 0;
	for (auto p : mp) {
		sol += p.second / 2;
	}
	cout << sol / 2;
}