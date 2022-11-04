#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
const int mod = 998244353;
int fact[500000];
int rfact[500000];

int bin_pow(int a, int b) {
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

int c(int n, int k) {
	if(n < 0 || k < 0 || k > n) {
		return 0;
	}
	int res = ((ll)fact[n] * rfact[k]) % mod;
	res = ((ll)res * rfact[n - k]) % mod;
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
    fact[0] = 1;
    for(int i = 1; i < 500000; i++) {
    	fact[i] = ((ll)fact[i - 1] * i) % mod;
    	rfact[i] = obr(fact[i]);
    }
    rfact[0] = rfact[1];
    int n, k;
    cin >> n >> k;
    if(k >= n) {
    	cout << 0;
    	return 0;
    }
    if(k == 0) {
    	cout << fact[n];
    	return 0;
    }
    k = n - k;
    int res = 0;
    for(int i = 0; i < k; i++) {
    	int here = ((ll)bin_pow(k - i, n) * c(k, i) % mod * bin_pow(mod - 1, i)) % mod;
    	res = (here + res) % mod;
    }
    res = ((ll)res * c(n, k)) % mod;
    cout << (res + res) % mod;
}