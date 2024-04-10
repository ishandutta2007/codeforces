#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

map<string, int> skor;
map<pair<string, int>, int> prviPut;

int bar(string s, int x) {
	auto it = prviPut.find({s, x});
	// smor
	int rez = it->second;
	while (it != prviPut.end() && it->first.first == s) {
		rez = min(rez, it->second);
		++it;
	}
	return rez;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	int n;
	cin >> n;
	for (int i=1; i<=n; i++) {
		string s;
		int x;
		cin >> s >> x;
		skor[s] += x;

		if (prviPut.count({s, skor[s]}) == 0)
			prviPut[{s, skor[s]}] = i;
	}

	string s;
	int opt = -123123123, kd = 0;
	for (auto p : skor) {
		string q = p.first;

		cerr << q << ' ' << skor[q] << ' ' << bar(q, skor[q]) << '\n';

		if (skor[q] > opt || (skor[q] == opt && bar(q, skor[q]) < kd)) {
			kd = bar(q, skor[q]);
			opt = skor[q];
			s = q;
		}
	}

	cout << s;
}