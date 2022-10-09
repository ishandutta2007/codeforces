// I've decided to retire from ALL contests
// It's been a nice ride... but I need to move on
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

int n;
int a[505];
int val[505][505];
bool d[505][505];
int p[505];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	cin >> n;
	for (int i=1; i<=n; i++)
		cin >> a[i];

	for (int l=1; l<=n; l++) {
		set<int> s;
		d[l][l] = 1;
		for (int r=l; r<=n; r++) {
			int x = a[r];
			while (s.count(x)) {
				s.erase(x);
				x++;
			}
			s.insert(x);
			if (s.size() == 1)
				val[l][r] = *s.begin();
		}
	}

	for (int l=n-1; l>=1; l--) {
		for (int r=l+1; r<=n; r++) {
			for (int x=l; x<r; x++) {
				if (val[l][x] == val[x+1][r] && val[l][x] > 0) {
					d[l][r] |= d[l][x] && d[x+1][r];
				}
			}
		}
	}

	memset(p, 63, sizeof p);
	p[0] = 0;
	for (int i=1; i<=n; i++) {
		for (int j=0; j<i; j++) {
			if (d[j+1][i]) {
				p[i] = min(p[i], p[j] + 1);
			}
		}
	}

	cout << p[n] << '\n';
}

// I will still practice daily...