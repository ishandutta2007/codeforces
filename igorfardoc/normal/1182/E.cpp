#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
const int mod = 1000000007;
const int mod1 = mod - 1;

int bin_pow(int a, ll b) {
	if(b == 0) return 1;
	int res = bin_pow(a, b >> 1);
	res = ((ll)res * res) % mod;
	if(b & 1) {
		res = ((ll)res * a) % mod;
	}
	return res;
}

vvi multiply(vvi a, vvi b) {
	vvi res(a.size(), vi(b[0].size()));
	for(int i = 0; i < a.size(); i++) {
		for(int j = 0; j < b[0].size(); j++) {
			int here = 0;
			for(int k = 0; k < a[0].size(); k++) {
				here = (here + (ll)a[i][k] * b[k][j]) % mod1;
			}
			res[i][j] = here;
		}
	}
	return res;
}

vvi bin_pow_matrix(vvi a, ll b) {
	if(b == 0) {
		vvi res(a.size(), vi(a.size(), 0));
		for(int i = 0; i < a.size(); i++) {
			res[i][i] = 1;
		}
		return res;
	}
	vvi res = bin_pow_matrix(a, b >> 1);
	res = multiply(res, res);
	if(b & 1) {
		res = multiply(a, res);
	}
	return res;
}


int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	#ifdef _FILE
    	freopen("input.txt", "r", stdin);
    	freopen("output.txt", "w", stdout);
	#endif
    ll n;
    vi f(3);
    int c;
    cin >> n >> f[0] >> f[1] >> f[2] >> c;
    int ans = 1;
    for(int i = 0; i < 3; i++) {
    	vvi st = {{1, 1, 0}, {1, 0, 1}, {1, 0, 0}};
    	vvi need = {{0, 0, 0}};
    	need[0][2 - i] = 1;
    	vvi res = multiply(need, bin_pow_matrix(st, n - 3));
    	ans = ((ll)ans * bin_pow(f[i], res[0][0])) % mod;
    }
    vvi st = {{1, 1, 0, 0, 0}, {1, 0, 1, 0, 0}, {1, 0, 0, 0, 0}, {1, 0, 0, 1, 0}, {0, 0, 0, 2, 1}};
    vvi need = {{0, 0, 0, 2, 1}};
    vvi res = multiply(need, bin_pow_matrix(st, n - 3));
    ans = ((ll)ans * bin_pow(c, res[0][0])) % mod;
    cout << ans;
}