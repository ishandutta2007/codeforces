// Retired?
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long unsigned long ull;
typedef double long ld;

map<char, pair<int, int>> m = {{'N', {0, 1}}, {'S', {0, -1}}, {'E', {-1, 0}}, {'W', {1, 0}}};

int main() {
	ios::sync_with_stdio(!cin.tie(0));

	int t;
	cin >> t;
	while (t--) {
		int q = 0;
		pair<int, int> p = {0, 0};
		set<set<pair<int, int>>> s;
		string d;
		cin >> d;
		for (char c : d) {
			auto pp = p;
			p.first += m[c].first;
			p.second += m[c].second;
			q += s.count({p, pp}) ? 1 : 5;
			s.insert({p, pp});
		}
		cout << q << '\n';
	}
}