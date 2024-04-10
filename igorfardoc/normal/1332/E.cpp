#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
const int mod = 998244353;

vvi mult_matrix(vvi a, vvi b) {
	vvi res(a.size(), vi(b[0].size()));
	for(int i = 0; i < a.size(); i++) {
		for(int j = 0; j < b[0].size(); j++) {
			int here = 0;
			for(int k = 0; k < a[0].size(); k++) {
				here = ((ll)a[i][k] * b[k][j] + here) % mod;
			}
			res[i][j] = here;
		}
	}
	return res;
}

vvi matrix_pow(vvi a, ll st) {
	if(st == 0) {
		return {{1, 0}, {0, 1}};
	}
	vvi res = matrix_pow(a, st >> 1);
	res = mult_matrix(res, res);
	if(st & 1) {
		res = mult_matrix(res, a);
	}
	return res;
}
int bin_pow(int a, ll b) {
	if(b == 0) {
		return 1;
	}
	int res = bin_pow(a, b >> 1);
	res = ((ll)res * res) % mod;
	if(b & 1) {
		res = ((ll)res * a) % mod;
	}
	return res;
}

int obr(int a) {
	return bin_pow(a, mod - 2);
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
    int n, m, l, r;
    cin >> n >> m >> l >> r;
    ll sz = (ll)n * m;
    if(sz % 2 == 1) {
    	cout << bin_pow(r - l + 1, sz);
    	return 0;
    }
    int am1 = (r - l + 1) / 2;
    int am0 = (r - l + 1) / 2;
    if((r - l + 1) % 2 == 1) {
    	if(l % 2 == 0) {
    		++am0;
    	} else {
    		++am1;
    	}
    }
    vvi matrix = {{am0, am1}, {am1, am0}};
    vvi matrix1 = {{am1, am0}};
    vvi res = mult_matrix(matrix1, matrix_pow(matrix, sz - 1));
    cout << res[0][1];
}