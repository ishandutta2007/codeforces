#include <bits/stdc++.h>
#define maxn 200086
using namespace std;

typedef long long LL;

struct Node{
	int son[2];
	pair<LL, LL> p;
}t[maxn << 6];

inline pair<LL, LL> operator + (pair<LL, LL> a, pair<LL, LL> b){
	return {a.first + b.first, a.second + b.second};
}

inline pair<LL, LL> operator - (pair<LL, LL> a, pair<LL, LL> b){
	return {a.first - b.first, a.second - b.second};
}

int cnt;

#define ls(x) (t[x].son[0])
#define rs(x) (t[x].son[1])

inline void up(int x){
	t[x].p = t[ls(x)].p + t[rs(x)].p;
}

inline void modify(int x, int l, int r, int pos, pair<LL, LL> d){
	if(l == r){
		t[x].p = t[x].p + d;
		return;
	}
	int mid = l + r >> 1, y = ++cnt;
	if(mid >= pos){
		t[y] = t[ls(x)], modify(ls(x) = y, l, mid, pos, d);
	}else{
		t[y] = t[rs(x)], modify(rs(x) = y, mid + 1, r, pos, d);
	}
	up(x);
}

inline pair<LL, LL> query(int x, int y, int l, int r, int ll, int rr){
	if(ll <= l && r <= rr){
		return t[y].p - t[x].p;
	}
	int mid = l + r >> 1;
	pair<LL, LL> p = {0, 0};
	if(mid >= ll) p = p + query(ls(x), ls(y), l, mid, ll, rr);
	if(mid < rr) p = p + query(rs(x), rs(y), mid + 1, r, ll, rr);
	return p;
}

int n, m;
LL sum[maxn], lastans;
int l, r, x;

const int p = 1e9;

int main(){
	scanf("%d", &n), cnt = n;
	int x1, x2, y1, a, b, y2;
	for(int i = 1;i <= n;i++){
		scanf("%d%d%d%d%d%d", &x1, &x2, &y1, &a, &b, &y2);
		t[i] = t[i - 1];
		modify(i, 0, 2e5, 0, {0, y1});
		modify(i, 0, 2e5, x1 + 1, {a, b - y1});
		modify(i, 0, 2e5, x2 + 1, {-a, -b + y2});
		sum[i] = y2 + sum[i - 1];
	}
	scanf("%d", &m);
	while(m--){
		scanf("%d%d%d", &l, &r, &x);
		x = (x + lastans) % p;
		if(x > 2e5) lastans = sum[r] - sum[l - 1];
		else{
			pair<LL, LL> p = query(l - 1, r, 0, 2e5, 0, x);
			lastans = p.first * x + p.second;
		}
		printf("%lld\n", lastans);
	}
}