#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

map<int, int> dub;
int n;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	cin >> n;
	int x;
	cin >> x;
	dub[x] = 0;
	for (int i=2; i<=n; i++) {
		int x;
		cin >> x;
		auto rit = dub.lower_bound(x);
		if (rit == dub.end()) {
			auto lit = prev(rit);
			dub[x] = lit->second + 1;
			cout << lit->first << ' ';
		} else if (rit == dub.begin()) {
			dub[x] = rit->second + 1;
			cout << rit->first << ' ';
		} else {
			auto lit = prev(rit);
			if (lit->second > rit->second) {
				cout << lit->first << ' ';
				dub[x] = lit->second + 1;
			} else {
				cout << rit->first << ' ';
				dub[x] = rit->second + 1;
			}
		}
	}
}