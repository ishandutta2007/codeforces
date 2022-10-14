//#pragma GCC optimize("trapv")
#pragma GCC optimize("Ofast")
#pragma GCC target("avx,avx2,fma")
#pragma GCC optimize("unroll-loops")
#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
#define pb push_back
#define all(x) x.begin(), x.end()
using namespace std;
using ll = long long;
using vi = vector<ll>;
using pi = pair<ll, ll>;
using vpi = vector<pi>;
ll n, m, hv[100100];
vector<vi> e;
bool go(int s) {
	if (s == n)
		return false;
	memset(hv, 0, sizeof hv);
	for (int i = 0; i < n; i++) {
		for (auto j : e[i]) {
			hv[(j + s) % n]--;
		}
		for (auto j : e[(i+s)%n]) {
			hv[j]++;
		}
		for (auto j : e[i]) {
			if(hv[(j + s) % n]) return false;
		}
		for (auto j : e[(i+s)%n]) {
			if(hv[j]) return false;
		}
	}
	return true;
}
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> n >> m;
	e.resize(n);
	for (int f, t, i = 0; i < m; i++) {
		cin >> f >> t;
		f--, t--;
		if (f > t)
			swap(f, t);
		e[f].pb(t);
		e[t].pb(f);
	}
	bool ok = false;
	for (int d = 1; !ok && d * d <= n; d++) {
		if (n % d)
			continue;
		ok |= go(d) | go(n / d);
	}
	cout << (ok ? "Yes" : "No");
}