#include<bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;
typedef long long ll;
typedef long double ld;
const int mn = 1e5+10;
ll a[mn];
int main() {
	int n,i;
	ll k, m,sum=0;
	scanf("%d%lld%lld", &n, &k, &m);
	for (i = 0; i < n; i++)scanf("%lld", a + i),sum+=a[i];
	sort(a, a + n);
	ld ans = 0;
	for (i = 0; i < n; i++) {
	    if(m-i<0)break;
		ans = max(ans, 1.0L*(sum+min(m-i,k*(n-i)))/ (n - i));
		sum -= a[i];
	}
	printf("%.20Lf", ans);
}