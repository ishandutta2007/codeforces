#include <bits/stdc++.h>
using namespace std;
const int MAXN = 250005;
using lint = long long;
 
 
using pi = pair<int, int>;
 
int n, mod;
lint fact[MAXN];
 
int main(){
	fact[0] = 1;
	cin >> n >> mod;
	for(int i=1; i<=n; i++) fact[i] = fact[i-1] * i % mod;
	lint ret = 0;
	for(int i=1; i<=n; i++){
		ret += (n - i + 1) * (fact[i] * fact[n - i + 1] % mod);
		ret %= mod;
	}
	cout << ret << endl;
}