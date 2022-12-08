#include "bits/stdc++.h"
using namespace std;
#ifdef ONLINE_JUDGE
#define trace(...)
#endif
 
using LL = long long;
 
int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	
	int n, d, e; cin >> n >> d >> e;
	e *= 5;
 
	int ans = n;
	for (int i = 0; i <= n; i += e) {
		ans = min(ans, (n - i) % d);
	}
	cout << ans << endl;
 
	return 0;
}