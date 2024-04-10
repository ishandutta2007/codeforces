#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

basic_string<int> e[5005];
int p[5005];
int a[5005], b[5005], n, budzet, sz[5005];

ll bez[5005][5005], svejedno[5005][5005];

struct dpstate {
	ll curr[5005];
	int hi;

	dpstate() {
		hi = 0;
		memset(curr, 31, sizeof(curr));
		curr[0] = 0;
	}

	void dodaj(ll* b, int n) {
		vector<ll> tmp(hi+1+n, 1e18);
		for (int i=0; i<=hi; i++)
			for (int j=0; j<=n; j++)
				tmp[i+j] = min(tmp[i+j], curr[i] + b[j]);
		copy(tmp.begin(), tmp.end(), curr);
		hi += n;
	}

	void dodaj(ll x) {
		for (int i=hi; i>=0; i--) {
			curr[i+1] = min(curr[i+1], curr[i] + x);
		}
		hi++;
	}
};

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	cin >> n >> budzet;
	for (int i=1; i<=n; i++) {
		cin >> a[i] >> b[i];
		b[i] = a[i] - b[i];
		if (i > 1) {
			cin >> p[i];
			e[p[i]] += i;
		}
		sz[i] = 1;
	}
	for (int i=n; i>=1; i--)
		sz[p[i]] += sz[i];

	/*
		sa[x][amt] = minimalna cena da se uzme amt objekata iz podstabla
		u cvoru x, uz obecanje da ce cvor x i svi cvorovi na putu od x do
		korena da budu uzeti sa popustom

		bez[x][amt] = isto kao gore samo bez ikakvih obecanja

	*/

	for (int x=n; x>=1; x--) {

		vector<ll> sa(5005, 1e18);

		{
			dpstate dp;
			for (int y : e[x]) {
				dp.dodaj(svejedno[y], sz[y]);
			}

			sa[0] = 0;
			for (int i=1; i<5005; i++) {
				sa[i] = dp.curr[i-1] + b[x];
			}
		}

		{
			dpstate dp;
			for (int y : e[x]) {
				dp.dodaj(bez[y], sz[y]);
			}
			dp.dodaj(a[x]);

			for (int i=0; i<5005; i++) {
				bez[x][i] = dp.curr[i];
				svejedno[x][i] = min(sa[i], bez[x][i]);
			}
		}
	}
	
	// for (int i=0; i<=n+2; i++)
	// 	cerr << i << " -> " << svejedno[1][i] << '\n';

	cout << upper_bound(svejedno[1], svejedno[1]+5005, budzet) - svejedno[1] - 1 << '\n';
}