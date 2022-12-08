#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <set>
#include <cmath>
#include <algorithm>
#include <deque>
#include <cassert>
#include <math.h>
#include <random>

using namespace std;

#define PI 3.14159265
typedef long long ll;
typedef vector<vector<ll>> matrix;

const ll INF = 4 * 1e18;
const int INFi = 2 * 1e9;
ll mod = 1e9 + 7;
long double eps = 1e-8;

matrix matrixProduct(matrix a, matrix b) {
	if (!a.size() || !b.size()) return {};
	if (a[0].size() != b.size()) return {};
	ll n = a.size();
	ll m = b[0].size();
	matrix res(n, vector<ll>(m, 0));
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			for (int k = 0; k < a[0].size(); k++) {
				res[i][j] += a[i][k] * b[k][j];
				res[i][j] %= mod;
			}
		}
	}
	return res;
}

matrix operator*(const matrix &a, matrix &b) {
	return matrixProduct(a, b);
}

matrix binpow(matrix a, ll k) {
	int n = a.size();
	int m = a[0].size();
	matrix res(n, vector<ll>(m));
	if (k == 0) {
		for (int i = 0; i < n; i++) {
			res[i][i] = 1;
		}
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



int main() {
	cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);
	
	ll n, m;
	cin >> n >> m;
	if (n < m) {
		cout << 1 << endl;
	} else{
		matrix a(m,	vector<ll>(m));
		a[0][0] = 1;
		a[0][m - 1] = 1;
		for (int i = 1; i < m; i++) {
			a[i][i - 1] = 1;
		}
		matrix b(m, vector<ll>(1));
		for (int i = 0; i < m; i++) b[i][0] = 1;
		b = binpow(a, n - m + 1) * b;
		cout << b[0][0] << endl;
	}
	//system("pause");
	return 0;	
}