#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

const int MAXV = 7040;

int n, q;
int meb[MAXV];
bitset<MAXV> init[MAXV], mat[MAXV], a[100005];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	for (int i=1; i<MAXV; i++)
		for (int j=i; j<MAXV; j+=i)
			init[j][i] = 1;
	meb[1] = 1;
	for (int i=1; i<MAXV; i++)
		for (int j=2*i; j<MAXV; j+=i)
			meb[j] -= meb[i];
	for (int i=1; i<MAXV; i++)
		for (int j=1; i*j<MAXV; j++)
			mat[i][i*j] = abs(meb[j]);

	cin >> n >> q;
	string sol;
	while (q--) {
		int t;
		cin >> t;
		if (t == 1) {
			int x, v;
			cin >> x >> v;
			a[x] = init[v];
		} else if (t == 2) {
			int x, y, z;
			cin >> x >> y >> z;
			a[x] = a[y] ^ a[z];
		} else if (t == 3) {
			int x, y, z;
			cin >> x >> y >> z;
			a[x] = a[y] & a[z];
		} else {
			int x, v;
			cin >> x >> v;
			sol += (char)((a[x] & mat[v]).count() % 2 + '0');
		}
	}
	cout << sol << '\n';
}