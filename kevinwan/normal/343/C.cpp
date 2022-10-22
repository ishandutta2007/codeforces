#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define mn 100005
ll h[mn], p[mn];
int n, m;
bool poss(ll x) {
	ll i,cur=0,d;
	for (i = 0; i < n; i++) {
		d = h[i] - p[cur];
		if (d <= 0) {
			for (; cur<m; cur++) {
				if (p[cur ] - h[i] > x)break;
			}
		}
		else {
			for (; cur<m; cur++) {
				if (d > x)break;
				if (p[cur ] - h[i] > x-2*d&&2*(p[cur]-h[i])>x-d)break;
			}
		}
	}
	if (cur == m)return 1;
	return 0;
}
int main() {
	ll i,cur=-1;
	scanf("%d%d", &n, &m);
	for (i = 0; i < n; i++)scanf("%lld", h + i);
	for (i = 0; i < m; i++)scanf("%lld", p + i);
	for (i = 1LL << 35; i; i >>= 1)if (!poss(cur + i))cur += i;
	printf("%lld", cur+1);
	getchar(); getchar();
}