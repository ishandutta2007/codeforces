#include <bits/stdc++.h>
#define maxn 1000086
using namespace std;

typedef long long ll;

struct Node{
	int x, y;
	ll a;
}a[maxn];

inline bool cmp(Node x, Node y){
	return x.x < y.x;
}

int n;

int q[maxn], l, r;
ll f[maxn], ans;

inline double k(int i, int j){
	return 1.0 * (f[i] - f[j]) / (a[i].x - a[j].x);
}

int main(){
	scanf("%d", &n);
	for(int i = 1;i <= n;i++) scanf("%d%d%lld", &a[i].x, &a[i].y, &a[i].a);
	sort(a + 1, a + 1 + n, cmp);
	for(int i = 1;i <= n;i++){
		while(l < r && k(q[l], q[l + 1]) >= a[i].y) l++;
		ans = max(ans, f[i] = f[q[l]] + 1ll * (a[i].x - a[q[l]].x) * a[i].y - a[i].a);
		while(l < r && k(q[r - 1], q[r]) < k(q[r], i)) r--;
		q[++r] = i;
	}
	printf("%lld", ans);
}