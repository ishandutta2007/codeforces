#include <bits/stdc++.h>
using namespace std;
#define int long long
int MOD = 998244353;
int fact(int n){
	int res = 1;
	for(int i = 2;i <= n;i++){
		res = (res * i) % MOD;
	}
	return res;
}
signed main() {
	int n;
	cin >> n;
	vector<int> a(n);
	for(int i = 0;i < n - 1;i++){
		int x, y;
		cin >> x >> y;
		a[x - 1]++;
		a[y - 1]++;
	}
	int ans = 1;
	for(int i = 0;i < n;i++){
		//cout << a[i] << " " << fact[a[i]] << endl;
		ans = (ans * fact(a[i])) % MOD;
	}
	cout << (ans * n) % MOD;
}