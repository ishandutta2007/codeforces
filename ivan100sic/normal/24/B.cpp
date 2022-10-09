#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

const int w[10] = {25, 18, 15, 12, 10, 8, 6, 4, 2, 1};

int t;

int W(int i) {
	if (i < 10)
		return w[i];
	return 0;
}

struct skor {
	basic_string<int> mesta;
	int zbir;

	skor() : mesta(50, 0), zbir(0) {}
};

map<string, skor> mp;

bool poredi1(skor a, skor b) {
	if (a.zbir != b.zbir)
		return a.zbir > b.zbir;
	return a.mesta > b.mesta;
}

bool poredi2(skor a, skor b) {
	if (a.mesta[0] != b.mesta[0])
		return a.mesta[0] > b.mesta[0];
	if (a.zbir != b.zbir)
		return a.zbir > b.zbir;
	return a.mesta.substr(1) > b.mesta.substr(1);
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	cin >> t;
	while (t--) {
		int n;
		cin >> n;
		for (int i=0; i<n; i++) {
			string s;
			cin >> s;
			mp[s].mesta[i]++;
			mp[s].zbir += W(i);
		}
	}

	skor p1, p2;
	string w1, w2;

	for (auto [x, y] : mp) {
		if (poredi1(y, p1)) {
			w1 = x;
			p1 = y;
		}
		if (poredi2(y, p2)) {
			w2 = x;
			p2 = y;
		}
	}
	cout << w1 << '\n' << w2 << '\n';

}