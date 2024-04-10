#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

map<char, char> beats;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	beats['R'] = 'S';
	beats['P'] = 'R';
	beats['S'] = 'P';

	int t;
	cin >> t;
	while (t--) {
		int n, a, b, c;
		cin >> n >> a >> b >> c;
		string s;
		cin >> s;

		map<char, int> ima;
		ima['R'] = a;
		ima['P'] = b;
		ima['S'] = c;
		string p(n, 0);
		int w = 0, j = 0;

		for (char x : s) {
			if (ima[beats[beats[x]]] > 0) {
				ima[beats[beats[x]]]--;
				w++;
				p[j] = beats[beats[x]];
			}
			j++;
		}

		for (int i=0; i<n; i++) {
			if (!p[i]) {
				for (char x : string("RPS")) {
					if (ima[x]) {
						p[i] = x;
						ima[x]--;
						break;
					}
				}
			}
		}

		if (w >= (n+1)/2) {
			cout << "YES\n" << p << '\n';
		} else {
			cout << "NO\n";
		}
	}
}