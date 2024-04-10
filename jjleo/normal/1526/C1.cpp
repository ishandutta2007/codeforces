#include <bits/stdc++.h>
#define maxn 200086

using namespace std;

typedef long long LL;

struct Node{
	LL sum, tag;
}t[maxn << 2];

#define ls(x) (x << 1)
#define rs(x) (x << 1 | 1)

inline void up(int x){
	t[x].sum = min(t[ls(x)].sum, t[rs(x)].sum);
}

inline void add(int x, LL y){
	t[x].sum += y, t[x].tag += y;
}

inline void down(int x){
	if(!t[x].tag) return;
	add(ls(x), t[x].tag), add(rs(x), t[x].tag);
	t[x].tag = 0;
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
	LL sum = 1e18;
	if(mid >= ll) sum = min(sum, query(ls(x), l, mid, ll, rr));
	if(mid < rr) sum = min(sum, query(rs(x), mid + 1, r, ll, rr));
	return sum;
}

int n;
LL a[maxn];
int x;
vector<pair<int, int> > v;

void build(int x, int l, int r){
	if(l == r){
		t[x].sum = a[l];
		return;
	}
	int mid = l + r >> 1;
	build(ls(x), l, mid), build(rs(x), mid + 1, r);
	up(x);
}

int main(){
	scanf("%d", &n);
	int ans = 0;
	for(int i = 1;i <= n;i++){
		scanf("%d", &x);
		a[i] = a[i - 1];
		if(x >= 0) a[i] += x, ans++;
		else v.push_back({-x, i});
	}
	build(1, 1, n);
	sort(v.begin(), v.end());
	for(int i = 0;i < v.size();i++){
		if(query(1, 1, n, v[i].second, n) >= v[i].first){
			ans++;
			modify(1, 1, n, v[i].second, n, -v[i].first);
		}
	}
	printf("%d", ans);
}