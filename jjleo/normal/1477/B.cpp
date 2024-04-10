#include <bits/stdc++.h>
#define maxn 200086

using namespace std;

int T;
int n, q;
char s[maxn], f[maxn];
int l[maxn], r[maxn];

struct Node{
	int sum, tag;
}t[maxn << 2];

#define ls(x) (x << 1)
#define rs(x) (x << 1 | 1)

inline void up(int x){
	t[x].sum = t[ls(x)].sum + t[rs(x)].sum;
} 

inline void cover(int x, int l, int r, int d){
	t[x].tag = d;
	t[x].sum = d * (r - l + 1); 
}

inline void down(int x, int l, int r){
	if(t[x].tag ^ -1){
		int mid = l + r >> 1;
		cover(ls(x), l, mid, t[x].tag);
		cover(rs(x), mid + 1, r, t[x].tag);
		t[x].tag = -1;
	}
}

void modify(int x, int l, int r, int ll, int rr, int d){
	if(ll <= l && r <= rr){
		cover(x, l, r, d);
		return;
	}
	down(x, l, r);
	int mid = l + r >> 1;
	if(mid >= ll) modify(ls(x), l, mid, ll, rr, d);
	if(mid < rr) modify(rs(x), mid + 1, r, ll, rr, d);
	up(x);
}

int query(int x, int l, int r, int ll, int rr){
	if(ll <= l && r <= rr) return t[x].sum;
	down(x, l, r);
	int mid = l + r >> 1, sum = 0;
	if(mid >= ll) sum += query(ls(x), l, mid, ll, rr);
	if(mid < rr) sum += query(rs(x), mid + 1, r, ll, rr);
	return sum;
}

void build(int x, int l, int r){
	t[x].tag = -1;
	if(l == r){
		t[x].sum = f[l] - '0';
		return;
	}
	int mid = l + r >> 1;
	build(ls(x), l, mid), build(rs(x), mid + 1, r);
	up(x);
}

int main(){
	scanf("%d", &T);
	while(T--){
		scanf("%d%d%s%s", &n, &q, s + 1, f + 1);
		build(1, 1, n);
		for(int i = 1;i <= q;i++) scanf("%d%d", &l[i], &r[i]);
		bool tag = false;
		for(int i = q;i;i--){
			int cnt = query(1, 1, n, l[i], r[i]);
			if(cnt * 2 == r[i] - l[i] + 1){
				tag = true;
				break;
			}
			if(cnt * 2 < r[i] - l[i] + 1) modify(1, 1, n, l[i], r[i], 0);
			else modify(1, 1, n, l[i], r[i], 1);
		}
		for(int i = 1;i <= n && !tag;i++) if(query(1, 1, n, i, i) != s[i] - '0') tag = true;
		puts(!tag ? "YES" : "NO");
	}
}