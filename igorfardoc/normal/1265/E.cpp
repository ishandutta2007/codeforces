#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
const int mod = 998244353;

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


int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	#ifdef _FILE
    	freopen("input.txt", "r", stdin);
    	freopen("output.txt", "w", stdout);
	#endif
    int n;
    cin >> n;
    vi a(n);
    for(int i = 0; i < n; i++) {
    	cin >> a[i];
    }
    int ans = 0;
    for(int i = 0; i < n; i++) {
    	int p = ((ll)a[i] * obr(100)) % mod;
    	ans = (ans + 1) % mod;
    	ans = ((ll)ans * obr(p)) % mod;
    }
    cout << ans << '\n';
}