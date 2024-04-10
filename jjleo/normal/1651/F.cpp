#include <bits/stdc++.h>
#define maxn 200086

using namespace std;

typedef long long LL;

struct Node{
	LL sum;
	int son[2];
}t[maxn * 120];

#define ls(x) (t[x].son[0])
#define rs(x) (t[x].son[1])

int cnt;

inline void up(int x){
	t[x].sum = t[ls(x)].sum + t[rs(x)].sum;
}

void modify(int x, int l, int r, int pos, int d){
	if(l == r){
		t[x].sum += d;
		return;
	}
	int mid = l + r >> 1;
	if(mid >= pos) t[++cnt] = t[ls(x)], modify(ls(x) = cnt, l, mid, pos, d);
	else t[++cnt] = t[rs(x)], modify(rs(x) = cnt, mid + 1, r, pos, d);
	up(x); 
}

LL h;

int query(int x, int y, int l, int r, int ll, int rr, int d){
	if(ll <= l && r <= rr){
		LL val = t[x].sum * d + t[y].sum;
		if(h > val){
			h -= val;
			return 0;
		}
		if(l == r){
			h -= val;
			return l;
		}
	}
	int mid = l + r >> 1;
	int ans = 0;
	if(mid >= ll) ans = query(ls(x), ls(y), l, mid, ll, rr, d);
	if(!ans && mid < rr) ans = query(rs(x), rs(y), mid + 1, r, ll, rr, d);
	return ans;
}

int n, q;
int c[maxn], r[maxn];
vector<int> v[maxn];
struct P{
	int l, r, t, x;
};

const int m = 2e5;

int main(){
	scanf("%d", &n), cnt = m * 2;
	for(int i = 1;i <= n;i++){
		scanf("%d%d", &c[i], &r[i]);
		int tot = (c[i] + r[i] - 1) / r[i];
		if(tot <= m) v[tot].push_back(i);
	} 
	for(int i = 1;i <= n;i++) modify(1, 1, n, i, r[i]);
	for(int i = 1;i <= m;i++){
		if(i > 1) t[i] = t[i - 1], t[i + m] = t[i + m - 1];
		for(auto x : v[i]){
			modify(i, 1, n, x, -r[x]), modify(i + m, 1, n, x, c[x]);
		}
	}
	vector<P> v;
	for(int i = n;i;i--) v.push_back({i, i, 0, c[i]});
	scanf("%d", &q);
	LL ans = 0;
	while(q--){
		int t;
		scanf("%d%lld", &t, &h);
		while(h && !v.empty()){
			P x = v.back();v.pop_back();
			if(x.x){
				x.x = min(1ll * c[x.l], x.x + 1ll * r[x.l] * (t - x.t));
				LL val = min(1ll * x.x, h);
				h -= val, x.x -= val;
				x.t = t;
				if(x.x) v.push_back(x);
			}else{
				int tt = t - x.t;
				int pos = query(tt, tt + m, 1, n, x.l, x.r, tt);
				if(pos){
					if(pos + 1 <= x.r) v.push_back({pos + 1, x.r, x.t, 0});
					v.push_back({pos, pos, t, (int)-h});
					h = 0;
				}
			}
		}
		ans += h;
		if(v.empty()) v.push_back({1, n, t, 0});
		else if(v.back().l > 1) v.push_back({1, v.back().l - 1, t, 0});
//		for(auto x : v) printf("[%d %d %d %d], ", x.l, x.r, x.t, x.x);
//		printf("%lld--\n", h);
	}
	printf("%lld", ans);
}