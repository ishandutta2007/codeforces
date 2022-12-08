#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <math.h>
#include <cmath>
#include <map>
#include <set>
#include <deque>
#include <cassert>
#include <unordered_map>
#include <unordered_set>
#include <queue>
#include <random>

using namespace std;

typedef long long ll;
typedef vector<vector<ll>> vll;

ll INF = 2e18 + 4;
int INFi = 2e9 + 2;
double eps = 1e-6;
ll mod = 1e9 + 7;

vll matrixProd(vll& a, vll& b) {
	if (a.empty() || b.empty()) return {};
	if (a[0].size() != b.size()) return {};
	int n = a.size();
	int m = b[0].size();
	vll res(n, vector<ll>(m, 0));
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			for (int k = 0; k < a[0].size(); k++) {
				res[i][j] += a[i][k] * b[k][j];
				res[i][j] %= (mod - 1);
			}
		}
	}
	return res;
}
vll operator*(vll a, vll b) { return matrixProd(a, b); }

vll matrixPow(vll a, ll k) {
	if (a.empty()) return {};
	int n = a.size();
	int m = a[0].size();
	vll res(n, vector<ll>(m));
	if (k == 0) {
		for (int i = 0; i < n; i++) res[i][i] = 1;
		return res;
	}
	res = a;
	k--;
	while (k) {
		if (k & 1) res = res * a;
		a = a * a;
		k >>= 1;
	}
	return res;
}
vll operator^(vll a, ll k) { return matrixPow(a, k); }

ll binpow(ll a, ll k) {
	ll res = 1;
	while (k) {
		if (k & 1) res *= a;
		a *= a;
		k >>= 1;
		res %= mod;
		a %= mod;
	}
	return res;
}

int main() {
	cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);
	
	ll n, c, f1, f2, f3;
	cin >> n >> f1 >> f2 >> f3 >> c;
	vll gl = (vll{ { 1, 1, 0 },{ 1, 0, 1 },{ 1, 0, 0 } } ^ (n - 3));
	vll ff1 = vll{ {0, 0, 1} } * gl;
	ll ans = binpow(f1, ff1[0][0]);
	vll ff2 = vll{ {0, 1, 0} } * gl;
	ans *= binpow(f2, ff2[0][0]);
	ans %= mod;
	vll ff3 = vll{ {1, 0, 0} } *gl;
	ans *= binpow(f3, ff3[0][0]);
	ans %= mod;
	vll cc = vll{ {0, 0, 0, 0, 2} } * ((vll{ {1, 1, 0, 0, 0},{1,0,1,0,0},{1,0,0,0,0},{1,0,0,1,0},{1,0,0,1,1} }) ^ (n - 3));
	ans *= binpow(c, cc[0][0]);
	ans %= mod;
	cout << ans << endl;
	//system("pause");
	return 0;
}