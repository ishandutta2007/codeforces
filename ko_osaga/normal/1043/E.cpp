#include <bits/stdc++.h>
using namespace std;
const int MAXN = 300005;
using pi = pair<int, int>;
using lint = long long;

struct ppl{
	int x, y, i;
	bool operator<(const ppl &p)const{
		return x - y < p.x - p.y;
	}
}a[MAXN];

int n, m, rev[MAXN];
lint ans[MAXN], xsum[MAXN], ysum[MAXN];

int main(){
	scanf("%d %d",&n,&m);
	for(int i=1; i<=n; i++){
		scanf("%d %d",&a[i].x,&a[i].y);
		a[i].i = i;
	}
	sort(a + 1, a + n + 1);
	for(int i=1; i<=n; i++){
		xsum[i] = xsum[i-1] + a[i].x;
		ysum[i] = ysum[i-1] + a[i].y;
	}
	for(int i=1; i<=n; i++){
		rev[a[i].i] = i;
		ans[a[i].i] = 1ll * a[i].x * (n - i);
		ans[a[i].i] += ysum[n] - ysum[i];
		ans[a[i].i] += 1ll * a[i].y * (i - 1);
		ans[a[i].i] += xsum[i - 1];
	}
	while(m--){
		int x, y; scanf("%d %d",&x,&y);
		x = rev[x]; y = rev[y];
		if(x > y) swap(x, y);
		ans[a[x].i] -= a[x].x + a[y].y;
		ans[a[y].i] -= a[x].x + a[y].y;
	}
	for(int i=1; i<=n; i++) printf("%lld ", ans[i]);
}