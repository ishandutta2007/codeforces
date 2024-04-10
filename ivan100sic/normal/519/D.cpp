#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

int a[26], n;
string s;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	for (int i=0; i<26; i++)
		cin >> a[i];
	cin >> s;
	n = s.size();

	map<ll, int> mp[26];
	ll z = 0, sol = 0;
	for (int i=0; i<n; i++) {
		int x = s[i] - 'a';
		z += a[x];
		sol += mp[x][z - a[x]];
		mp[x][z]++;
	}
	cout << sol << '\n';
}