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
	map<string, int> mp;
	while (n--) {
		string s;
		cin >> s;
		mp[s]++;
	}
	if (mp.size() == 1) {
		cout << mp.begin()->first << '\n';
	} else {
		if (mp.begin()->second > mp.rbegin()->second) {
			cout << mp.begin()->first << '\n';
		} else {
			cout << mp.rbegin()->first << '\n';
		}
	}
}