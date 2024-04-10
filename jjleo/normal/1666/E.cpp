#include <bits/stdc++.h>
#define maxn 100086

using namespace std;

int m, n;
int a[maxn], ll[maxn], rr[maxn];

bool check(int L, int R){
	int l = a[1], r = a[1];
	for(int i = 1;i <= n;i++){
		int tmpl = L - r, tmpr = R - l;
		if(tmpr < 0) return false;
		l = max(0, tmpl), r = tmpr;
		if(l > r) return false;
		if(i == n) break;
		swap(l, r);
		l = a[i + 1] - a[i] - l, r = a[i + 1] - a[i] - r;
		l = max(0, l);
		if(l > r) return false;
		ll[i + 1] = l, rr[i + 1] = r;
	}
	if(!(l <= m - a[n] && m - a[n] <= r)) return false;
	return true;
}

int main(){
	scanf("%d%d", &m, &n);
	for(int i = 1;i <= n;i++) scanf("%d", &a[i]);
	int l = 0, r = m, mid;
	while(l < r){
		mid = l + r >> 1;
		if(check(0, mid)) r = mid;
		else l = mid + 1;
	}
	int R = l;
	l = 0, r = R;
	while(l < r){
		mid = (l + r >> 1) + 1;
		if(check(mid, R)) l = mid;
		else r = mid - 1;
	}
	int L = l;
	assert(check(L, R));
	vector<pair<int, int> > v;
	int now = m;
	for(int i = n;i > 1;i--){
		int nxt = max(a[i] - rr[i], now - R);
		assert(L <= now - nxt && now - nxt <= R);
		v.push_back({nxt, now});
		now = nxt;
	}
	assert(L <= now && now <= R);
	v.push_back({0, now});
	for(int i = v.size() - 1;~i;i--) printf("%d %d\n", v[i].first, v[i].second);
}