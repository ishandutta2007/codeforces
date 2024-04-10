#include <bits/stdc++.h>
#define maxn 1086
using namespace std;

int a[maxn], n0;

struct Node{
	int l, r, lm, rm;
	int cov;
}t[maxn << 2];

#define ls(x) (x << 1)
#define rs(x) (x << 1 | 1)

inline void up(int x){
	if(t[x].cov){
		t[x].lm = n0, t[x].rm = 0;
	}else{
		if(t[x].l == t[x].r){
			t[x].lm = t[x].rm = t[x].l;
		}else{
			t[x].lm = min(t[ls(x)].lm, t[rs(x)].lm);
			t[x].rm = max(t[ls(x)].rm, t[rs(x)].rm);
		}
		
	}
}


void build(int x, int l, int r){
	t[x].l = l, t[x].r = r;
	t[x].cov = 0;
	if(l < r){
		int mid = l + r >> 1;
		build(ls(x), l, mid), build(rs(x), mid + 1, r);
	}
	up(x);
}

void modify(int x, int l, int r, int ll, int rr, int d){
	if(ll <= l && r <= rr){
		t[x].cov += d;
		up(x);
		return;
	}
	int mid = l + r >> 1;
	if(mid >= ll) modify(ls(x), l, mid, ll, rr, d);
	if(mid < rr) modify(rs(x), mid + 1, r, ll, rr, d);
	up(x);
}

int n, m, k;
int x[maxn], y[maxn];

struct Line{
	int l, r, y, i;
};

inline bool cmp(Line a, Line b){
	return a.y < b.y;
}

vector<Line> v;

inline bool check(int mid){
	n0 = 0, v.clear();
	for(int i = 1;i <= k;i++){
		int l = max(1, y[i] - mid), r = min(m, y[i] + mid) + 1;
		int d = max(1, x[i] - mid), u = min(n, x[i] + mid) + 1;
		v.push_back((Line){l, r, d, 1}), v.push_back((Line){l, r, u, -1});
		a[++n0] = l, a[++n0] = r;
	}
	a[++n0] = 1, a[++n0] = m + 1;
	sort(v.begin(), v.end(), cmp);
	sort(a + 1, a + 1 + n0);
	n0 = unique(a + 1, a + 1 + n0) - (a + 1);
	build(1, 1, n0 - 1);
	int l = m + 1, r = 0, u = 0, d = n + 1;
	if(v[0].y > 1) u = max(u, v[0].y - 1), d = min(d, 1), l = 1, r = m;
	if(v.back().y < n) u = max(u, n), d = min(d, v.back().y), l = 1, r = m;
	for(int i = 0;i < v.size();i++){
		Line L = v[i];
		//printf("%d %d %d %d--\n", L.l, L.r, L.y, L.i);
		modify(1, 1, n0 - 1, lower_bound(a, a + 1 + n0, L.l) - a, lower_bound(a, a + 1 + n0, L.r) - a - 1, L.i);
		if(i != v.size() - 1 && v[i + 1].y != L.y){
			if(t[1].rm){
				u = max(u, v[i + 1].y - 1), d = min(d, L.y);
				l = min(l, a[t[1].lm]), r = max(r, a[t[1].rm + 1] - 1);
			}
		}
	}
	//printf("%d %d %d %d %d--\n", mid, l, r, u, d);
	return r - l <= 2 * mid && u - d <= 2 * mid;
}

int main(){
	scanf("%d%d%d", &n, &m, &k);
	for(int i = 1;i <= k;i++) scanf("%d%d", &x[i], &y[i]);
	int l = 0, r = max(n, m), mid;
	while(l < r){
		mid = l + r >> 1;
		if(check(mid)) r = mid;
		else l = mid + 1;
	}
	printf("%d", l);
}