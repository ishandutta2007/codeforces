#include <algorithm>
#include <cstdio>
#include <queue>
using namespace std;
typedef long long ll;
priority_queue< ll, vector<ll>, greater<ll> > q;
int main() {
	int n; scanf("%d", &n);
	for(int x, i = 1; i <= n; i ++) { scanf("%d", &x); q.push(x); }
	ll ans = 0;
	if(n % 2 == 0) {
		int x = q.top(); q.pop();
		int y = q.top(); q.pop();
		q.push(x + y); ans += x + y;
	}
	while(q.size() > 1) {
		ll x = q.top(); q.pop();
		ll y = q.top(); q.pop();
		ll z = q.top(); q.pop();
		ans += x + y + z; q.push(x + y + z);
	}
	printf("%I64d\n", ans);
	return 0;
}