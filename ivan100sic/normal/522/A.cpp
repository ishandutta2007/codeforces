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

	map<string, int> mp;
	mp["polycarp"] = 1;
	int n, sol = 0;
	cin >> n;
	for (int i=0; i<n; i++) {
		string s, r, p;
		cin >> s >> r >> p;

		for (char& x : s)
			x = tolower(x);
		for (char& x : p)
			x = tolower(x);

		sol = max(sol, mp[s] = mp[p] + 1);
	}
	cout << sol;
}