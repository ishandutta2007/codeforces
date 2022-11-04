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
    int n, m;
    cin >> n >> m;
    vi d(n);
    for(int i = 0; i < n; i++) {
    	cin >> d[i];
    }
    sort(d.begin(), d.end());
    vi suff(n + 1, 0), pref(n + 1, 0);
    for(int i = n - 1; i >= 0; i--) {
    	suff[i] = (suff[i + 1] + d[i]) % mod;
    }
    for(int i = 1; i <= n; i++) {
    	pref[i] = (pref[i - 1] + d[i - 1]) % mod;
    }
    for(int i = 0; i < m; i++) {
    	int a, b;
    	cin >> a >> b;
    	int id1 = lower_bound(d.begin(), d.end(), b) - d.begin();
    	int am = n - id1;
    	int can = am - a;
    	int res = 0;
		if(am != 0 && can > 0) {
    		res = ((ll)(suff[id1]) * can % mod * obr(am)) % mod;
    	}
    	if(am + 1 - a >= 0) {
    		res = ((ll)(am + 1 - a) * obr(am + 1) % mod * pref[id1] + res) % mod;
    	}
    	cout << res << '\n';
    }
}