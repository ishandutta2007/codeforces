#include <bits/stdc++.h>
#define m(x,y) (a[x]>a[y]?x:y)
using namespace std;
typedef long long ll;
typedef pair<int, int> pii; 
typedef pair<ll, ll> pll;
#define mn (1<<17)
pii p[300000];
int main() {
	int n,a,b,i,x=0x3f3f3f3f,xx = -0x3f3f3f3f,y = 0x3f3f3f3f,yy = -0x3f3f3f3f;
	scanf("%d", &n);
	for (i = 0; i < n; i++)scanf("%d%d", &a, &b),p[i] = { a,b };
	for (i = 0; i < n; i++)x = min(x, p[i].first), xx = max(xx, p[i].first), y = min(y, p[i].second), yy = max(yy, p[i].second);
	int ans = 0;
	for (i = 0; i < n; i++) {
		ans = max(ans, p[i].first - x + p[i].second - y);
		ans = max(ans, p[i].first - x + yy-p[i].second );
		ans = max(ans, xx-p[i].first  + p[i].second - y);
		ans = max(ans, xx-p[i].first + yy-p[i].second);
	}
	printf("%d", ans * 2);
	for (i = 4; i <= n; i++)printf(" %d", (yy - y + xx - x) * 2);
	getchar(); getchar();
}