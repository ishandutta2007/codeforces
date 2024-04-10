#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <set>
#include <map>
#include <numeric>
#include <iterator>
#include <cstring>
using namespace std;

int c[100005];
bool forbidden[1000005];
int cnt[1000005];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	int n, a, ap = 0;
	cin >> n >> a;
	for (int i=1; i<=n; i++) {
		cin >> c[i];
	}
	set<pair<int, int>> s;

	for (int i=1; i<=1000000; i++) {
		if (i != a) {
			s.insert({0, i});
		}
	}

	for (int i=1; i<=n; i++) {
		int x = c[i];
		if (x == a) {
			ap++;
			// brisi sve iz s sto je manje od ap
			while (s.size() && s.begin()->first < ap) {
				forbidden[s.begin()->second] = true;
				s.erase(s.begin());
			}
		} else {
			if (!forbidden[x]) {
				s.erase({cnt[x], x});
				cnt[x]++;
				s.insert({cnt[x], x});
			}
		}
	}

	for (auto p : s) {
		int x = p.second;
		if (!forbidden[x]) {
			cout << x;
			return 0;
		}
	}
	cout << -1;
}