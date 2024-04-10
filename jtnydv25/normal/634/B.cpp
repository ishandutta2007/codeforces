#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define sd(x) scanf("%d", &(x))

ll solutions(ll s, ll x){
	if((s & 1) ^ (x & 1)) return 0;
	if(s == 0) return x == 0;
	if(s & 1) return 2 * solutions(s >> 1, x >> 1);
	else return solutions(s >> 1, x >> 1) + solutions((s >> 1) - 1, x >> 1);
}
int main(){
	ll s, x;
	cin >> s >> x;
	ll ans = solutions(s, x);
	if(s == x) ans -= 2;
	cout << ans << endl;
}