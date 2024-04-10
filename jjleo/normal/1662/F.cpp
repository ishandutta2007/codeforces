#include <bits/stdc++.h>
#define maxn 200086

using namespace std;

struct Seg{
	pair<int, int> sum[maxn << 2];
	int a[maxn];
	
	#define ls(x) (x << 1)
	#define rs(x) (x << 1 | 1)
	
	inline void up(int x){
		sum[x] = max(sum[ls(x)], sum[rs(x)]); 
	}
	
	void modify(int x, int l, int r, int pos){
		if(l == r){
			sum[x].first = -1e9;
			return;
		}
		int mid = l + r >> 1;
		if(mid >= pos) modify(ls(x), l, mid, pos);
		else modify(rs(x), mid + 1, r, pos);
		up(x);
	}
	
	pair<int, int> query(int x, int l, int r, int ll, int rr){
		if(ll <= l && r <= rr) return sum[x];
		int mid = l + r >> 1;
		if(mid < ll) return query(rs(x), mid + 1, r, ll, rr);
		if(mid >= rr) return query(ls(x), l, mid, ll, rr);
		return max(query(ls(x), l, mid, ll, rr), query(rs(x), mid + 1, r, ll, rr));
	}
	
	void build(int x, int l, int r){
		if(l == r){
			sum[x] = {a[l], l};
			return;
		}
		int mid = l + r >> 1;
		build(ls(x), l, mid), build(rs(x), mid + 1, r);
		up(x);
	}
}t[2];

int T, n, a, b;
int p[maxn];
int d[maxn];

int main(){
	scanf("%d", &T);
	while(T--){
		scanf("%d%d%d", &n, &a, &b);
		for(int i = 1;i <= n;i++) scanf("%d", &p[i]);
		for(int i = 1;i <= n;i++) t[0].a[i] = p[i] - i, t[1].a[i] = p[i] + i;
		t[0].build(1, 1, n), t[1].build(1, 1, n);
		queue<int> q;
		for(int i = 1;i <= n;i++) d[i] = 1e9;
		q.push(a), d[a] = 0;
		t[0].modify(1, 1, n, a);
		t[1].modify(1, 1, n, a);
		while(!q.empty()){
			int x = q.front();q.pop();
			int r = min(n, x + p[x]);
			if(x + 1 <= r){
				while(1){
					pair<int, int> p = t[0].query(1, 1, n, x + 1, r);
					if(p.first < -x) break;
					d[p.second] = d[x] + 1;
					q.push(p.second);
					t[0].modify(1, 1, n, p.second);
					t[1].modify(1, 1, n, p.second);
				}
			}
			int l = max(1, x - p[x]);
			if(l <= x - 1){
				while(1){
					pair<int, int> p = t[1].query(1, 1, n, l, x - 1);
					if(p.first < x) break;
					d[p.second] = d[x] + 1;
					q.push(p.second);
					t[0].modify(1, 1, n, p.second);
					t[1].modify(1, 1, n, p.second);
				}
			}
		}
		printf("%d\n", d[b]);
	}
}