#include <bits/stdc++.h>
#define maxn 500086

using namespace std;

struct Node{
	int a[6];
	int cnt;
}t[maxn << 2];

#define ls(x) (x << 1)
#define rs(x) (x << 1 | 1)

int fa[12];
bool tag[12];
int find(int x){
	return x == fa[x] ? x : fa[x] = find(fa[x]);
}

inline void merge(int x, int y){
	fa[find(x)] = find(y);
}

inline Node up(const Node &l, const Node &r){
	for(int i = 0;i < 12;i++) fa[i] = i, tag[i] = false;
	for(int i = 0;i < 6;i++){
		if(l.a[i] != -1) merge(i, l.a[i]);
		if(r.a[i] != -1) merge(i + 6, r.a[i] + 6);
	}
	for(int i = 0;i < 3;i++){
		if(l.a[i + 3] != -1 && r.a[i] != -1) merge(i + 3, i + 6);
	}
	Node x;
	x.cnt = l.cnt + r.cnt;
	for(int i = 0;i < 3;i++) if(l.a[i] != -1) tag[find(i)] = true;
	for(int i = 3;i < 6;i++) if(r.a[i] != -1) tag[find(i + 6)] = true;
	for(int i = 3;i < 6;i++){
		if(l.a[i] != -1 && find(i) == i && !tag[i]) x.cnt++;
	}
	for(int i = 0;i < 3;i++){
		if(r.a[i] != -1 && find(i + 6) == i + 6 && !tag[i + 6]) x.cnt++;
	}
	for(int i = 0;i < 3;i++){
		if(l.a[i] == -1){
			x.a[i] = -1;
			continue;
		}
		if(find(i) > 3) fa[find(i)] = fa[i] = i;
		x.a[i] = find(i);
	}
	for(int i = 3;i < 6;i++){
		if(r.a[i] == -1){
			x.a[i] = -1;
			continue;
		}
		if(!(find(i + 6) < 3 || find(i + 6) >= 9)) fa[find(i + 6)] = fa[i + 6] = i + 6;
		x.a[i] = find(i + 6);
		if(x.a[i] > 6) x.a[i] -= 6;
	}
	return x;
}

char s[3][maxn];

void build(int x, int l, int r){
	if(l == r){
		for(int i = 0;i < 3;i++){
			if(s[i][l] == '0') t[x].a[i] = t[x].a[i + 3] = -1;
			else if(i && s[i - 1][l] == '1') t[x].a[i] = t[x].a[i + 3] = t[x].a[i - 1];
			else t[x].a[i] = t[x].a[i + 3] = i;
		}
		return;
	}
	int mid = l + r >> 1;
	build(ls(x), l, mid), build(rs(x), mid + 1, r);
	t[x] = up(t[ls(x)], t[rs(x)]);
}

Node query(int x, int l, int r, int ll, int rr){
	if(ll <= l && r <= rr) return t[x];
	int mid = l + r >> 1;
	if(mid < ll) return query(rs(x), mid + 1, r, ll, rr);
	if(mid >= rr) return query(ls(x), l, mid, ll, rr);
	Node L = query(ls(x), l, mid, ll, rr), R = query(rs(x), mid + 1, r, ll, rr);
	return up(L, R);
}


int n, q, l, r;

int main(){
	scanf("%d", &n);
	for(int i = 0;i < 3;i++) scanf("%s", s[i] + 1);
	build(1, 1, n);
	scanf("%d", &q);
	while(q--){
		scanf("%d%d", &l, &r);
		Node x = query(1, 1, n, l, r);
		int ans = x.cnt;
		for(int i = 0;i < 6;i++) ans += x.a[i] == i;
		printf("%d\n", ans);
	}
}
/*
12
100101011101
110110010110
010001011101
1
4 6
*/