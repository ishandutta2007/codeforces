#include <bits/stdc++.h>
using namespace std;
using lint = long long;
using pi = pair<lint, int>;
const int MAXN = 100005;
const int mod = 1e9 + 7;

int main(){
	lint n, k;
	cin >> n >> k;
	if(k <= 2){
		puts("0");
		return 0;
	}
	lint lo, hi;
	if(k & 1){
		lo = k / 2;
		hi = k / 2 + 1;
	}
	else{
		lo = k / 2 - 1;
		hi = k / 2 + 1;
	}
	lint fuck = 1e18;
	fuck = min(fuck, n + 1 - hi);
	fuck = min(fuck, lo);
	printf("%lld\n", max(0ll, fuck));
}