#include <bits/stdc++.h>
#define maxn 200086

using namespace std;

struct Node{
	int tag, mx, mn;
}t[maxn << 2];

#define ls(x) (x << 1)
#define rs(x) (x << 1 | 1)

inline void up(int x){
	t[x].mx = max(t[ls(x)].mx, t[rs(x)].mx);
	t[x].mn = min(t[ls(x)].mn, t[rs(x)].mn);
} 

inline void add(int x, int y){
	t[x].tag += y, t[x].mx += y, t[x].mn += y;
}

inline void down(int x){
	if(!t[x].tag) return;
	add(ls(x), t[x].tag), add(rs(x), t[x].tag);
	t[x].tag = 0;
}

void modify(int x, int l, int r, int ll, int rr, int d){
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

int queryMax(int x, int l, int r, int ll, int rr){
	if(ll <= l && r <= rr) return t[x].mx;
	int mid = l + r >> 1, sum = -1e9;
	down(x);
	if(mid >= ll) sum = max(sum, queryMax(ls(x), l, mid, ll, rr));
	if(mid < rr) sum = max(sum, queryMax(rs(x), mid + 1, r, ll, rr));
	return sum; 
}

int queryMin(int x, int l, int r, int ll, int rr){
	if(ll <= l && r <= rr) return t[x].mn;
	int mid = l + r >> 1, sum = 1e9;
	down(x);
	if(mid >= ll) sum = min(sum, queryMin(ls(x), l, mid, ll, rr));
	if(mid < rr) sum = min(sum, queryMin(rs(x), mid + 1, r, ll, rr));
	return sum; 
}

void build(int x, int l, int r){
	t[x].tag = 0;
	if(l == r){
		t[x].mx = t[x].mn = l;
		return;
	}
	int mid = l + r >> 1;
	build(ls(x), l, mid), build(rs(x), mid + 1, r);
	up(x); 
}

int n;
vector<int> v[maxn];
int x;
int ans[maxn];

int main(){
	scanf("%d", &n);
	for(int i = 1;i <= n;i++) scanf("%d", &x), v[x].push_back(i);
	build(1, 0, n);
	for(int i = n;i;i--){
		for(int j = 0;j < v[i].size();j++){
			int x = v[i][j];
			ans[x] = max(ans[x], (queryMax(1, 0, n, x, n) - queryMin(1, 0, n, 0, x - 1) - 1) / 2);
		}
		for(int j = 0;j < v[i].size();j++) modify(1, 0, n, v[i][j], n, -2);
	}
	build(1, 0, n);
	for(int i = 1;i <= n;i++){
		for(int j = 0;j < v[i].size();j++){
			int x = v[i][j];
			ans[x] = max(ans[x], (queryMax(1, 0, n, x, n) - queryMin(1, 0, n, 0, x - 1)) / 2);
		}
		for(int j = 0;j < v[i].size();j++) modify(1, 0, n, v[i][j], n, -2);
	}
	for(int i = 1;i <= n;i++) printf("%d ", ans[i]);
}