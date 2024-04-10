#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

int n, m;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	cin >> n >> m;
	map<string, string> mp;
	for (int i=1; i<=n; i++) {
		string a, b;
		cin >> a >> b;
		mp[b] = a;
	}
	while (m--) {
		string a, b;
		cin >> a >> b;
		cout << a << ' ' << b << " #" << mp[b.substr(0, b.size()-1)] << '\n';
	}
}