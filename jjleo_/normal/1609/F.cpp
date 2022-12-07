#include <bits/stdc++.h>
#define maxn 1000086

using namespace std;

typedef long long LL;

inline LL read(){
    LL x = 0, f = 1;char ch = getchar();
    while(ch > '9' || ch < '0'){if(ch == '-') f = -1;ch = getchar();}
    while(ch >= '0' && ch <= '9'){x = x * 10 + ch -'0';ch = getchar();}
    return x * f;
}

struct Node{
	int mx, tag, cnt;
}t[maxn << 2];

#define ls(x) (x << 1)
#define rs(x) (x << 1 | 1)

inline void up(int x){
	t[x].mx = max(t[ls(x)].mx, t[rs(x)].mx);
	if(t[ls(x)].mx == t[rs(x)].mx) t[x].cnt = t[ls(x)].cnt + t[rs(x)].cnt;
	else if(t[ls(x)].mx > t[rs(x)].mx) t[x].cnt = t[ls(x)].cnt;
	else t[x].cnt = t[rs(x)].cnt;
}

inline void add(int x, int y){
	t[x].mx += y, t[x].tag += y;
}

inline void down(int x){
	if(!t[x].tag) return;
	add(ls(x), t[x].tag), add(rs(x), t[x].tag);
	t[x].tag = 0;
}

void modify(int x, int l, int r, int ll, int rr, int d){
	//printf("%d %d %d--\n", x, ll, rr);
	if(ll <= l && r <= rr){
		add(x, d);
		return;
	}
	int mid = l + r >> 1;
	down(x);
	if(mid >= ll) modify(ls(x), l, mid, ll, rr, d);
	if(mid < rr) modify(rs(x), mid + 1, r, ll, rr, d);
	up(x);
}

void build(int x, int l, int r){
	if(l == r){
		t[x].cnt = 1;
		return;
	}
	int mid = l + r >> 1;
	build(ls(x), l, mid), build(rs(x), mid + 1, r);
	up(x);
}

int n;
LL a[maxn];
int sk[maxn], top;
int l[maxn], r[maxn], L[maxn], R[maxn];
vector<int> v[60];
int head[maxn], nxt[maxn << 2];
pair<int, int> w[maxn << 2];
int cnt;

inline void addE(int x, pair<int, int> p){
	w[++cnt] = p, nxt[cnt] = head[x], head[x] = cnt;
}

int main(){
	n = read();
	build(1, 1, n);
	for(int i = 1;i <= n;i++) a[i] = read(), v[__builtin_popcountll(a[i])].push_back(i);
	for(int i = 1;i <= n;i++){
		while(top && a[sk[top]] >= a[i]) top--;
		if(top) l[i] = sk[top] + 1;
		else l[i] = 1;
		sk[++top] = i;
	}
	top = 0;
	for(int i = n;i;i--){
		while(top && a[sk[top]] > a[i]) top--;
		if(top) r[i] = sk[top] - 1;
		else r[i] = n;
		sk[++top] = i;
	}
	top = 0;
	for(int i = 1;i <= n;i++){
		while(top && a[sk[top]] <= a[i]) top--;
		if(top) L[i] = sk[top] + 1;
		else L[i] = 1;
		sk[++top] = i;
	}
	top = 0;
	for(int i = n;i;i--){
		while(top && a[sk[top]] < a[i]) top--;
		if(top) R[i] = sk[top] - 1;
		else R[i] = n;
		sk[++top] = i;
	}
	//for(int i = 1;i <= n;i++) printf("%d %d %d %d---\n", l[i], r[i], L[i], R[i]);
	LL ans = 0;
	for(int i = 0;i < 60;i++){
		for(int j = 1;j <= n + 1;j++) head[j] = 0;cnt = 0;
		for(int j = 0;j < v[i].size();j++){
			int x = v[i][j];
			addE(l[x], {x, r[x]});
			addE(x + 1, {-x, -r[x]});
			addE(L[x], {x, R[x]});
			addE(x + 1, {-x, -R[x]});
		}
		for(int j = 1;j <= n + 1;j++){
			for(int k = head[j];k;k = nxt[k]){
				int x = w[k].first, y = w[k].second;
				if(x > 0) modify(1, 1, n, x, y, 1);
				else modify(1, 1, n, -x, -y, -1);
				//printf("%d %d %d--\n", j, x, y);
			}
			if(t[1].mx == 2) ans += t[1].cnt;
		}
	}
	printf("%lld", ans);
}