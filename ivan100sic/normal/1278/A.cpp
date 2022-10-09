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

	int t;
	cin >> t;
	while (t--) {
		string p, h;
		int f = 0;
		cin >> p >> h;
		multiset<char> hs(p.begin(), p.end());
		for (int i=0; i<=int(h.size()-p.size()); i++) {
			if (multiset<char>(h.begin()+i, h.begin()+i+p.size()) == hs) {
				cout << "YES\n";
				f = 1;
				break;
			}
		}
		if (!f)
			cout << "NO\n";
	}
}