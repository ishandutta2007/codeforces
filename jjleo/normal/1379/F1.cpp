#include <bits/stdc++.h>
#define maxn 400086
using namespace std;

struct Node{
	int a, b;
	bool tag;
}t[maxn << 2];

#define ls(x) (x << 1)
#define rs(x) (x << 1 | 1)

inline void up(int x){
	t[x].a = min(t[ls(x)].a, t[rs(x)].a);
	t[x].b = max(t[ls(x)].b, t[rs(x)].b);
	t[x].tag = t[ls(x)].tag | t[rs(x)].tag | (t[ls(x)].a < t[rs(x)].b);
}

void modify(int x, int l, int r, int pos, pair<int, int> p){
	if(l == r){
		if(p.first == 0) t[x].a = p.second;
		else t[x].b = p.second;
		return;
	}
	int mid = l + r >> 1;
	if(mid >= pos) modify(ls(x), l, mid, pos, p);
	else modify(rs(x), mid + 1, r, pos, p);
	up(x);
}

void build(int x, int l, int r){
	t[x].a = 1e9;
	if(l == r) return;
	int mid = l + r >> 1;
	build(ls(x), l, mid), build(rs(x), mid + 1, r);
}

int n, m, q;
int x, y;
set<int> a[maxn], b[maxn];

int main(){
	scanf("%d%d%d", &n, &m, &q);
	build(1, 1, n * 2);
	while(q--){
		scanf("%d%d", &x, &y);
		if(x & 1){
			if(a[x].find(y) == a[x].end()){
				a[x].insert(y);
			}else{
				a[x].erase(y);
			}
			modify(1, 1, n * 2, x, {0, a[x].begin() == a[x].end() ? 1e9 : *a[x].begin()});
		}else{
			if(b[x].find(y) == b[x].end()){
				b[x].insert(y);
			}else{
				b[x].erase(y);
			}
			modify(1, 1, n * 2, x, {1, b[x].begin() == b[x].end() ? 0 : *b[x].rbegin()});
		}
		puts(t[1].tag ? "NO" : "YES");
	}
}