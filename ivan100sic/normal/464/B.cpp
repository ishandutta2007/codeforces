#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

ll a[8][3];

ll kv(ll x) { return x*x; }

void probaj() {
	set<ll> q;
	for (int i=0; i<8; i++) {
		for (int j=i+1; j<8; j++) {
			ll d = 0;
			for (int k=0; k<3; k++)
				d += kv(a[i][k] - a[j][k]);
			q.insert(d);
		}
	}
	if (q.size() == 3) {
		cout << "YES\n";
		for (int i=0; i<8; i++)
			for (int j=0; j<3; j++)
				cout << a[i][j] << " \n"[j == 2];
		exit(0);
	}
}

void rek(int x) {
	if (x == 8) {
		probaj();
		return;
	}
	sort(a[x], a[x]+3);
	do rek(x+1); while (next_permutation(a[x], a[x]+3));
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	for (int i=0; i<8; i++)
		for (int j=0; j<3; j++)
			cin >> a[i][j];
	rek(1);
	cout << "NO\n";
}