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

	map<int, int> mp;

	for (int i=0; i<6; i++) {
		int x;
		cin >> x;
		mp[x]++;
	}

	int i = -1;
	for (auto p : mp) {
		if (p.second >= 4) {
			i = p.first;
		}
	}

	if (i == -1) {
		cout << "Alien\n";
		return 0;
	}

	mp[i] -= 4;

	for (auto p : mp) {
		if (p.second == 2) {
			cout << "Elephant\n";
			return 0;
		}
	}

	cout << "Bear\n";
}