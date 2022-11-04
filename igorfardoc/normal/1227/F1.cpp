#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
const int mod = 998244353;
int fact[300000], rfact[300000];

int bin_pow(int a, int b) {
	if(b == 0) return 1;
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
    for(int i = 1; i < 300000; i++) {
    	fact[i] = ((ll)fact[i - 1] * i) % mod;
    	rfact[i] = obr(fact[i]);
    }
    rfact[0] = rfact[1];
    int n, k;
    cin >> n >> k;
    vi h(n);
    for(int i = 0; i < n; i++) {
    	cin >> h[i];
    }
    int ameq = 0;
    for(int i = 0; i < n; i++) {
    	if(h[i] == h[(i + 1) % n]) {
    		++ameq;
    	}
    }
    int ans = 0;
    int am = n - ameq;
    for(int i = 0; i <= am; i++) {
    	for(int j = 0; j < i && (i + j) <= am; j++) {
    		ans = (ans + (ll)c(am, i + j) * c(i + j, i) % mod * bin_pow(k - 2, am - i - j) % mod) % mod;
    	}
    }
    ans = (ll)ans * bin_pow(k, ameq) % mod;
    cout << ans;
}