#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

map<int, int> logg;
int br[33];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	int n, q;
	for (int i=0; i<=30; i++)
		logg[1 << i] = i;
	
	cin >> n >> q;
	for (int i=0; i<n; i++) {
		int x;
		cin >> x;
		br[logg[x]]++;
	}

	while (q--) {
		int x;
		cin >> x;
		int a = 0;

		for (int i=30; i>=0; i--) {
			int c = min(br[i], x >> i);
			x -= c << i;
			a += c;
		}

		if (x)
			a = -1;

		cout << a << '\n';
	}
}