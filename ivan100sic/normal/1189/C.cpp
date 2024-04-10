#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

int n;
int a[100005];
int w[100005][20], r[100005][20];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	cin >>  n;
	for (int i=0; i<n; i++)
		cin >> a[i];

	for (int i=0; i<n; i++) {
		w[i][0] = 0;
		r[i][0] = a[i];
	}

	for (int b=1; b<20; b++) {
		for (int i=0; i+(1<<b)<=n; i++) {
			r[i][b] = r[i][b-1] + r[i+(1<<(b-1))][b-1];
			w[i][b] = w[i][b-1] + w[i+(1<<(b-1))][b-1];
			if (r[i][b] >= 10) {
				w[i][b]++;
				r[i][b] -= 10;
			}
		}
	}

	int q;
	cin >> q;
	while (q--) {
		int l, r;
		cin >> l >> r;
		l--;
		int k = 31 - __builtin_clz(r-l);
		cout << w[l][k] << '\n';
	}
}