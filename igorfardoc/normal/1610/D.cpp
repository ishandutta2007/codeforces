#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
const int mod = 1000000007;

int fact[300000], rfact[300000], p[300000];

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
    for(int i = 1; i < 300000; i++) {
    	fact[i] = ((ll)fact[i - 1] * i) % mod;
    	rfact[i] = obr(fact[i]);
    }
    p[0] = 1;
    for(int i = 1; i < 300000; i++) {
    	p[i] = p[i - 1] * 2 % mod;
    }
    rfact[0] = rfact[1];
    int n;
    cin >> n;
    vi st(40, 0);
    int bigger2 = 0;
    for(int i = 0; i < n; i++) {
    	int a;
    	cin >> a;
    	int here = 0;
    	while(a % 2 == 0) {
    		a /= 2;
    		++here;
    	}
    	++st[here];
    	if(here >= 2) {
    		bigger2++;
    	}
    }
    int ans = (ll)(p[st[0]] - 1) * p[n - st[0]] % mod;
    for(int i = 2; i <= st[1]; i+=2) {
    	ans = (ans + (ll)c(st[1], i) * p[bigger2] % mod + mod) % mod;
    }
    //cout << ans << endl;
    for(int i = 2; i < 40; i++) {
    	bigger2 -= st[i];
    	//cout << i << ' ' << st[i] << endl;
    	if(st[i] == 0) {
    		continue;
    	}
    	for(int j = 2; j <= st[i]; j+=2) {
    		ans = (ans + (ll)c(st[i], j) * p[bigger2]) % mod;
    	}
    }
    cout << ans;

}