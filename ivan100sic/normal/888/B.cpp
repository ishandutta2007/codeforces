#include <bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	int n;
	cin >> n;
	string s;
	cin >> s;

	map<int, int> mp;

	for (char x : s) {
		mp[x]++;
	}

	cout << 2*min(mp['U'], mp['D']) + 2*min(mp['L'], mp['R']);
}