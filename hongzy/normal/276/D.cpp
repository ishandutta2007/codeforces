#include <algorithm>
#include <iostream> 
#include <cstdio>
using namespace std;

typedef long long ll;

int main() {
	ll l, r; cin >> l >> r;
	if(l == r) return (cout << 0 << endl), 0;
	ll ans = 0;
	for(int i = 61; ~ i; i --) {
		if((l & (1ll << i)) != (r & (1ll << i))) {
			ans = (1ll << (i + 1)) - 1; break ;
		}
	}
	cout << ans << endl;
	return 0;
}