#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

int n;
int c[200005], a[200005];

int p[2][200005];
bool v[200005];
bool w[200005];

void sq(int* a, int* b) {
	for (int i=1; i<=n; i++)
		b[i] = a[a[i]];
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	cin >> n;
	for (int i=1; i<=n; i++)
		cin >> c[i];
	for (int i=1; i<=n; i++)
		cin >> a[i];
	sq(a, p[0]);
	for (int i=1; i<20; i++)
		sq(p[1-i%2], p[i%2]);

	for (int i=1; i<=n; i++)
		v[p[1][i]] = 1;

	int sol = 0;

	for (int i=1; i<=n; i++) {
		if (v[i] && !w[i]) {
			int j = i;
			int mv = 1123123123;
			while (!w[j]) {
				// cerr << j << ' ';
				mv = min(mv, c[j]);
				w[j] = 1;
				j = a[j];
			}
			cerr << '\n';
			sol += mv;
		}
	}

	cout << sol;
}