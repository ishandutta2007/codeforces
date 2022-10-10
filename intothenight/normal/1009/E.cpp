#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	const ll MOD = 998244353;
	int n;
	cin >> n;
	vector<ll> a(n);
	for(auto &x: a){
		cin >> x;
	}
	ll A = 0, B = 0, S = a[0], P = a[0];
	for(int i = 1; i < n; i ++){
		A = (2 * A + S) % MOD;
		B = (B + P) % MOD;
		S = (S + a[i]) % MOD;
		P = (A + B + S) % MOD;
	}
	cout << P;
	return 0;
}