#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
const int mod = 1000000007;

int bin_pow(int a, int b) { 
	if(b == 0) {
		return 1;
	}
	if(b == 1) {
		return a;
	}
	int res = bin_pow(a, b / 2);
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
    int t;
    cin >> t;
    while(t--) {
    	int n, k;
    	cin >> n >> k;
    	vi a(n);
    	vi am(n + 1);
    	for(int i = 0; i < n; i++) {
    		cin >> a[i];
    		am[a[i]] += 1;
    	}
    	sort(a.begin(), a.end());
    	int prev = n - 1;
    	for(int i = n - 1; i >= n - k; i--) {
    		if(i == n - 1 || a[i] != a[i + 1]) {
    			prev = i;
    			continue;
    		}
    	}
    	int n1 = am[a[n - k]];
    	int k1 = prev - (n - k) + 1;
    	int res = 1;
    	for(int i = 1; i <= n1; i++) {
    		res = ((ll)res * i) % mod;
    	}
    	for(int i = 1; i <= k1; i++) {
    		res = ((ll)res * obr(i)) % mod;
    	}
    	for(int i = 1; i <= n1 - k1; i++) {
    		res = ((ll)res * obr(i)) % mod;
    	}
    	cout << res << '\n';
    }

}