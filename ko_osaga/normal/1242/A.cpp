#include <bits/stdc++.h>
using namespace std;
using lint = long long;
using pi = pair<int, int>;
#define sz(v) ((int)(v).size())
const int MAXN = 100005;
const int MAXT = 4200000;
 
int main(){
	lint n;
	cin >> n;
	lint ans = 0;
	for(int i=2; 1ll*i*i<=n; i++){
		if(n % i == 0) ans = gcd(ans, gcd(i, n / i));
	}
	if(!ans) ans = n;
	cout << ans << endl;
}