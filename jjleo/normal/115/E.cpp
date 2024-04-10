#include <bits/stdc++.h>
#define maxn 200086
using namespace std;

typedef long long LL;

struct Node{
	LL sum, pl;
}t[maxn << 2];

#define ls(x) (x << 1)
#define rs(x) (x << 1 | 1)

inline void up(int x){
	t[x].sum = max(t[ls(x)].sum, t[rs(x)].sum);
}

inline void add(int x, LL y){
	t[x].sum += y, t[x].pl += y;
}

inline void down(int x){
	if(t[x].pl){
		add(ls(x), t[x].pl), add(rs(x), t[x].pl);
		t[x].pl = 0;
	}
}

void modify(int x, int l, int r, int ll, int rr, LL d){
	if(ll <= l && r <= rr){
		add(x, d);
		return;
	}
	down(x);
	int mid = l + r >> 1;
	if(mid >= ll) modify(ls(x), l, mid, ll, rr, d);
	if(mid < rr) modify(rs(x), mid + 1, r, ll, rr, d);
	up(x);
}

LL query(int x, int l, int r, int ll, int rr){
	if(ll <= l && r <= rr) return t[x].sum;
	down(x);
	int mid = l + r >> 1;
	LL sum = 1ll << 63;
	if(mid >= ll) sum = max(sum, query(ls(x), l, mid, ll, rr));
	if(mid < rr) sum = max(sum, query(rs(x), mid + 1, r, ll, rr));
	return sum;
}

int n, m;
int c[maxn];
int x, y, z;

vector<pair<int, int> > v[maxn];

int main(){
	scanf("%d%d", &n, &m);
	for(int i = 1;i <= n;i++) scanf("%d", &c[i]);
	for(int i = 1;i <= m;i++) scanf("%d%d%d", &x, &y, &z), v[y].push_back({x, z});
	for(int i = 1;i <= n;i++){
		modify(1, 0, n, i, i, query(1, 0, n, 0, i) - query(1, 0, n, i, i));
		for(int j = 0;j < v[i].size();j++){
			modify(1, 0, n, 0, v[i][j].first - 1, v[i][j].second);
		}
		modify(1, 0, n, 0, i - 1, -c[i]);
	} 
	printf("%lld", t[1].sum);
}