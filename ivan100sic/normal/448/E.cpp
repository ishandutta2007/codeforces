#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

ll b[100005];
const int hi = 100000;
int s;
vector<ll> a;
basic_string<int> e[7777];

void rek(int x, int k) {
	if (s == hi)
		return;

	if (k == 0 || x == 0) {
		b[s++] = a[x];
		return;
	}

	for (int y : e[x]) {
		rek(y, k-1);
		if (s == hi)
			return;
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	ll x, k;
	cin >> x >> k;
	k = min(k, 100005ll);

	set<ll> d;
	for (ll y=1; y*y<=x; y++) {
		if (x % y == 0) {
			d.insert(y);
			d.insert(x/y);
		}
	}

	a = vector<ll>(d.begin(), d.end());
	int m = a.size();
	for (int i=0; i<m; i++) {
		for (int j=i; j<m; j++) {
			if (a[j] % a[i] == 0) {
				e[j] += i;
			}
		}
	}

	rek(m-1, k);
	for (int i=0; i<s; i++)
		cout << b[i] << " \n"[i == s-1];
}