#include <bits/stdc++.h>
#define maxn 100086

using namespace std;

typedef long long LL;

struct SegmentTree{
	LL sum[maxn << 2];
	#define ls(x) (x << 1)
	#define rs(x) (x << 1 | 1)
	
	void modify(int x, int l, int r, int pos, LL d){
		sum[x] = min(sum[x], d);
		if(l == r) return;
		int mid = l + r >> 1;
		if(mid >= pos) modify(ls(x), l, mid, pos, d);
		else modify(rs(x), mid + 1, r, pos, d);
	}
	
	LL query(int x, int l, int r, int ll, int rr){
		if(ll <= l && r <= rr) return sum[x];
		int mid = l + r >> 1;
		LL ans = 1e18;
		if(mid >= ll) ans = min(ans, query(ls(x), l, mid, ll, rr));
		if(mid < rr) ans = min(ans, query(rs(x), mid + 1, r, ll, rr));
		return ans;
	}
	
	void build(int x, int l, int r){
		sum[x] = 1e18;
		if(l == r) return;
		int mid = l + r >> 1;
		build(ls(x), l, mid), build(rs(x), mid + 1, r);
	}
}t[2];

int n;
pair<int, int> a[maxn];
int A, C, x;
LL f[maxn], g[maxn], ans;

int main(){
	scanf("%d", &n);
	for(int i = 1;i <= n;i++) scanf("%d%d", &a[i].first, &a[i].second), ans += a[i].second;
	A = a[1].first, C = a[1].second;
	sort(a + 1, a + 1 + n);
	for(int i = 1;i <= n;i++){
		if(a[i].first == A && a[i].second == C){
			x = i;
			break;
		}
	}
	t[0].build(1, 1, x), t[1].build(1, 1, x);
	t[0].modify(1, 1, x, x, f[x]), t[1].modify(1, 1, x, x, f[x] + a[x].first);
	for(int i = x - 1;i;i--){
		f[i] = 1e18;
		int l = i + 1, r = x, mid;
		while(l < r){
			mid = l + r >> 1;
			if(a[mid].first - a[i].first >= a[i].second) r = mid;
			else l = mid + 1;
		}
		if(a[l].first - a[i].first >= a[i].second){
			f[i] = min(f[i], t[1].query(1, 1, x, l, x) - a[i].first - a[i].second);
		}else{
			l++;
		}
		if(i + 1 <= l - 1){
			f[i] = min(f[i], t[0].query(1, 1, x, i + 1, l - 1));
		}
		t[0].modify(1, 1, x, i, f[i]), t[1].modify(1, 1, x, i, f[i] + a[i].first);
	}
	t[0].build(1, 1, n), t[1].build(1, 1, n);
	t[0].modify(1, 1, n, n, g[n]), t[1].modify(1, 1, n, n, g[n] + a[n].first);
	for(int i = n - 1;i;i--){
		g[i] = 1e18;
		int l = i + 1, r = n, mid;
		while(l < r){
			mid = l + r >> 1;
			if(a[mid].first - a[i].first >= a[i].second) r = mid;
			else l = mid + 1;
		}
		if(a[l].first - a[i].first >= a[i].second){
			g[i] = min(g[i], t[1].query(1, 1, n, l, n) - a[i].first - a[i].second);
		}else{
			l++;
		}
		if(i + 1 <= l - 1){
			g[i] = min(g[i], t[0].query(1, 1, n, i + 1, l - 1));
		}
		if(i == x) continue;
		t[0].modify(1, 1, n, i, g[i]), t[1].modify(1, 1, n, i, g[i] + a[i].first);
	}
	printf("%lld", min(g[1], f[1] + g[x]) + ans);
}