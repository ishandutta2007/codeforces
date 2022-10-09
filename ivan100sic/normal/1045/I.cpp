#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

map<int, int> mp;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	int t;
	cin >> t;
	ll sol = 0;
	while (t--) {
		string s;
		cin >> s;
		int z = 0;
		for (char c : s)
			z ^= 1 << (c - 'a');
		for (int i=0; i<26; i++)
			sol += mp[z ^ (1 << i)];
		sol += mp[z]++;
	}
	cout << sol << '\n';
}