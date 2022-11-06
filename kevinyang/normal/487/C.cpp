#include <bits/stdc++.h>
using namespace std;
#define int long long
int mod = 0;
int modpow(int x, int y) {
	return !y?1:((y % 2 ? x : 1) * modpow((x * x) % mod, y / 2)) % mod;
}
signed main(){
	cin.tie(nullptr)->sync_with_stdio(false);
	int n;
	cin >> n;
	mod = n;
	if(n==1){
		cout << "YES\n1\n";
		return 0;
	}
	int prod = 1;
	for(int i = 1; i<n; i++){
		prod*=i; prod%=n;
	}
	if(prod==0){
		cout << "NO\n";
		return 0;
	}
	if(n==4){
		cout << "YES\n1\n3\n2\n4\n";
		return 0;
	}
	cout << "YES\n";
	cout << "1\n";
	for(int i = 2; i<n; i++){
		cout << i*modpow(i-1,mod-2)%mod << "\n";
	}
	cout << n << "\n";
	return 0;
}