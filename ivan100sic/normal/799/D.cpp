#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
ll a, b, h, w;
int n, sol = 13123123;

int c[100005];
vector<pair<int, int>> f;

void solve(ll hp, ll wp, int used, size_t idx) {
	if (hp >= a && wp >= b) {
		sol = min(sol, used);
		return;
	}

	if (idx == f.size()) {
		return;
	}

	if (hp > a) {
		hp = a;
	}

	if (wp > b) {
		wp = b;
	}

	ll htemp = hp;
	for (int he=0; he<=min(17, f[idx].second); he++) {

		ll wtemp = wp;
		for (int we=0; we<=min(17, f[idx].second - he); we++) {
			solve(htemp, wtemp, used + he + we, idx+1);

			if (wtemp >= b) {
				break;
			} // ne moras vise da budzis

			wtemp *= f[idx].first;
		}

		if (htemp >= a) {
			break;
		} // nema potrebe da dalje budzimo

		htemp *= f[idx].first;			
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	cin >> a >> b >> h >> w >> n;
	for (int i=0; i<n; i++) {
		ll x;
		cin >> x;
		c[x]++;
	}

	for (int i=100000; i>=0; i--) {
		if (c[i] > 0) {
			f.push_back({i, c[i]});
		}
	}

	solve(h, w, 0, 0);
	swap(a, b);
	solve(h, w, 0, 0);

	if (sol > 123123) {
		sol = -1;
	}

	cout << sol;
}