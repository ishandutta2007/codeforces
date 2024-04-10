#include <bits/stdc++.h>
#define maxn 1000086

using namespace std;

const int M = 1000000;

int sum[maxn << 2];

#define ls(x) (x << 1)
#define rs(x) (x << 1 | 1)

inline void up(int x){
	sum[x] = sum[ls(x)] + sum[rs(x)];
}

void modify(int x, int l, int r, int pos, int d){
	if(l == r){
		sum[x] += d;
		return;
	}
	int mid = l + r >> 1;
	if(mid >= pos) modify(ls(x), l, mid, pos, d);
	else modify(rs(x), mid + 1, r, pos, d);
	up(x);
}


int query(int x, int l, int r, int ll, int rr){
	if(ll <= l && r <= rr) return sum[x];
	int mid = l + r >> 1, ans = 0;
	if(mid >= ll) ans += query(ls(x), l, mid, ll, rr);
	if(mid < rr) ans += query(rs(x), mid + 1, r, ll, rr);
	return ans;
}

int n, m;
int x, y, l, r;

pair<int, int> a[maxn];

struct Node{
	int x, opt, y;
};

inline bool cmp(Node a, Node b){
	return a.x == b.x ? a.opt < b.opt : a.x < b.x;
}

vector<Node> v;

int main(){
	scanf("%d%d", &n, &m);
	long long ans = 1; 
	for(int i = 1;i <= n;i++){
		scanf("%d%d%d", &y, &l, &r);
		v.push_back((Node){l, 0, y}), v.push_back((Node){r, 2, y});
		if(l == 0 && r == M) ans++;
	}
	for(int i = 1;i <= m;i++){
		scanf("%d%d%d", &x, &l, &r);
		v.push_back((Node){x, 1, 0});
		a[x] = {l, r};
		if(l == 0 && r == M) ans++;
	}
	sort(v.begin(), v.end(), cmp);
	for(int i = 0;i < v.size();i++){
		int opt = v[i].opt, x = v[i].x, y = v[i].y;
		if(opt == 1){
			ans += query(1, 0, M, a[x].first, a[x].second);
		}else if(opt == 0){
			modify(1, 0, M, y, 1);
		}else{
			modify(1, 0, M, y, -1);
		}
		//printf("%d %d %d %d %d--\n", opt, x, a[x].first, y, ans);
	}
	printf("%lld", ans);
}