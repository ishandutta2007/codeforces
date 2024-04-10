#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
const int mod = 998244353;
int fact[1000001], rfact[1000001];

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
	if(k > n || n < 0 || k < 0) {
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
    int n, k;
    cin >> n >> k;
    fact[0] = 1;
    for(int i = 1; i <= 1000000; i++) {
    	fact[i] = ((ll)fact[i - 1] * i) % mod;
    	rfact[i] = obr(fact[i]);
    }
    rfact[0] = rfact[1];
    int res = 0;
    if(k == 1) {
    	cout << n;
    	return 0;
    }
    if(k > n) {
    	cout << 0;
    	return 0;
    }
    for(int i = 1; i <= n; i++) {
    	if(i * k > n) {
    		break;
    	}
    	int can = n / i - 1;
    	res = (res + c(can, k - 1)) % mod;
    	//cout << res << endl;
    }
    cout << res;

}