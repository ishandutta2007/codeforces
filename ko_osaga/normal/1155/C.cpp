#include <bits/stdc++.h>
using namespace std;
typedef long long lint;
typedef pair<int, int> pi;
const int mod = 1e6 + 3;
const int MAXN = 300005;

lint gcd(lint x, lint y){ return y ? gcd(y, x%y):x ; }

int n, m;
lint a[MAXN], b[MAXN];

int main(){
	cin >> n >> m;
	for(int i=1; i<=n; i++) scanf("%lld",&a[i]);
	lint g = 0;
	for(int i=2; i<=n; i++) g = gcd(a[i] - a[i-1], g);
	for(int i=1; i<=m; i++) scanf("%lld",&b[i]);
	pair<lint, lint> ret(2e18, 2e18);
	for(int i=1; i<=m; i++){
		if(g % b[i] != 0) continue;
		lint modv = a[1] % b[i];
		if(modv == 0) modv += b[i];
		ret = min(ret, make_pair(modv, 1ll * i));
	}
	if(ret.first > 1.1e18){
		puts("NO");
		return 0;
	}
	cout << "YES" << endl;
	cout << ret.first << " " << ret.second;
}