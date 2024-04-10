#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

const ll LMAX = 1'000'000'000'000'000'000ll;
mt19937 eng(chrono::high_resolution_clock::now().time_since_epoch().count());

map<ll, ll> cache[1005];

ll ask(int i, ll x) {
	if (cache[i].count(x))
		return cache[i][x];
	cout << "? " << i << ' ' << x << '\n' << flush;
	ll y;
	cin >> y;
	return cache[i][x] = y;
}

int n;
ll L;
pair<ll, ll> ans[1005];

ll find_exact(int i, ll xu, ll xv, ll Lm) {
	ll xo = -1;
	while (xu <= xv) {
		ll xm = (xu + xv) >> 1;
		if (ask(i, xm) >= Lm) {
			xo = xm;
			xv = xm - 1;
		} else {
			xu = xm + 1;
		}
	}
	return xo;
}

int find_kth(basic_string<int> f, int k, ll xu, ll xv, ll Lm) {
	if (f.size() == 1)
		return f[0];

	shuffle(f.begin(), f.end(), eng);
	int ref = f[0];
	ll xm = find_exact(ref, xu, xv, Lm);

	basic_string<int> manji, veci, jednaki;
	for (int i : f) {
		if (ask(i, xm) < Lm) {
			manji += i;
		} else if (ask(i, xm) == Lm) {
			jednaki += i;
		} else {
			veci += i;
		}
	}

	if (k >= (int)manji.size() && k < int(manji.size() + jednaki.size()))
		return jednaki[0];

	if (k < (int)manji.size())
		return find_kth(manji, k, xu, xv, Lm);
	else
		return find_kth(veci, k - jednaki.size() - manji.size(), xu, xv, Lm);
}

void resi(ll xu, ll xv, ll Lu, ll Lv, basic_string<int> f) {
	int m = f.size();
	if (m == 1) {
		ans[f[0]] = {xu, xv};
		return;
	}

	shuffle(f.begin(), f.end(), eng);

	int mid = m/2;
	ll Lm = Lu + mid*(L/n);
	int j = find_kth(f, m-mid, xu, xv, Lm);
	ll xj = find_exact(j, xu, xv, Lm);

	basic_string<int> veci, manji, jednaki;
	for (int i : f) {
		if (ask(i, xj) < Lm)
			manji += i;
		else if (ask(i, xj) == Lm)
			jednaki += i;
		else
			veci += i;
	}

	while (jednaki.size() && (int)veci.size() < mid) {
		veci += jednaki.back();
		jednaki.pop_back();
	}

	manji += jednaki;
	resi(xu, xj, Lu, Lm, veci);
	resi(xj, xv, Lm, Lv, manji);
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	cin >> n >> L;

	basic_string<int> a;
	for (int i=1; i<=n; i++)
		a += i;
	resi(0, LMAX, 0, L, a);
	cout << "!\n";
	for (int i=1; i<=n; i++)
		cout << ans[i].first << ' ' << ans[i].second << '\n';
	cout << flush;
}