#include <bits/stdc++.h>
#define maxn 800086

using namespace std;

int l[maxn], r[maxn], b[maxn];

struct Node{
	bool l, r;
	int sum, cov;
}t[maxn << 2];

#define ls(x) (x << 1)
#define rs(x) (x << 1 | 1)

inline void up(int x){
	if(t[x].cov){
		t[x].l = t[x].r = true, t[x].sum = 1;
	}else{
		t[x].l = t[ls(x)].l, t[x].r = t[rs(x)].r;
		t[x].sum = t[ls(x)].sum + t[rs(x)].sum;
		if(t[ls(x)].r && t[rs(x)].l) t[x].sum--;
	}
}

void modify(int x, int l, int r, int ll, int rr, int d){
	if(ll <= l && r <= rr){
		t[x].cov += d;
		if(l == r){
			if(t[x].cov){
				t[x].l = t[x].r = true, t[x].sum = 1;
			}else{
				t[x].l = t[x].r = false, t[x].sum = 0;
			}
		}
		else up(x);
		return;
	}
	int mid = l + r >> 1;
	if(mid >= ll) modify(ls(x), l, mid, ll, rr, d);
	if(mid < rr) modify(rs(x), mid + 1, r, ll, rr, d);
	up(x);
}

void clear(int x, int l, int r){
	t[x].cov = t[x].l = t[x].r = t[x].sum = 0;
	if(l == r) return;
	int mid = l + r >> 1;
	clear(ls(x), l, mid), clear(rs(x), mid + 1, r);
}


int T;
int n, n0;
int ans;
int main(){
	scanf("%d", &T);
	while(T--){
		scanf("%d", &n), n0 = 0;
		for(int i = 1;i <= n;i++) scanf("%d%d", &l[i], &r[i]), b[++n0] = l[i], b[++n0] = r[i];
		sort(b + 1, b + 1 + n0);
		n0 = unique(b + 1, b + 1 + n0) - (b + 1);
		clear(1, 1, n0 * 2 - 1);
		for(int i = 1;i <= n;i++){
			l[i] = (lower_bound(b + 1, b + 1 + n0, l[i]) - b) * 2 - 1;
			r[i] = (lower_bound(b + 1, b + 1 + n0, r[i]) - b) * 2 - 1;
			modify(1, 1, 2 * n0 - 1, l[i], r[i], 1);
			//printf("%d %d %d %d--\n", i, l[i], r[i], t[1].sum);
		}
		ans = 0;
		for(int i = 1;i <= n;i++){
			modify(1, 1, 2 * n0 - 1, l[i], r[i], -1);
			ans = max(ans, t[1].sum);
			modify(1, 1, 2 * n0 - 1, l[i], r[i], 1);
		}
		printf("%d\n", ans);
	}
}