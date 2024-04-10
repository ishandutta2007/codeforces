#include <bits/stdc++.h>
#define maxn 200086

using namespace std;

typedef long long ll;

const int Bit = 20;

ll f[maxn << 2][25], g[maxn << 2][25], h[maxn << 2][25];
#define ls(x) (x << 1)
#define rs(x) (x << 1 | 1)

inline void up(int x){
	for(int i = 0;i <= Bit + 1;i++){
		f[x][i] = f[ls(x)][i] + f[rs(x)][i];
		g[x][i] = g[ls(x)][i] + g[rs(x)][i];
		h[x][i] = min(h[ls(x)][i], f[ls(x)][i] + h[rs(x)][i]);
	}
}

ll a[maxn], w[maxn], v[maxn];
int pos[maxn], rk[maxn];

inline bool cmp(int x, int y){
	return v[x] ^ v[y] ? v[x] > v[y] : w[x] < w[y];
}

inline void init(int x, int l){
	l = pos[l];
	for(int i = 0;i <= Bit + 1;i++){
		f[x][i] = g[x][i] = 0, h[x][i] = 2e18;
		if(!a[l]) continue;
		if(w[l] < (1 << i)) f[x][i] = a[l] * w[l], g[x][i] = a[l] * v[l];
		else if(w[l] < (1 << (i + 1))) h[x][i] = w[l];
	}
}

void build(int x, int l, int r){
	if(l == r){
		init(x, l);
		return;
	}
	int mid = l + r >> 1;
	build(ls(x), l, mid), build(rs(x), mid + 1, r);
	up(x);
}

void modify(int x, int l, int r, int pos){
	if(l == r){
		init(x, l);
		return;
	}
	int mid = l + r >> 1;
	if(mid >= pos) modify(ls(x), l, mid, pos);
	else modify(rs(x), mid + 1, r, pos);
	up(x);
}

ll c;
int bit;

void cal(){
	while(bit && c < (1 << bit)) bit--;
}

ll query(int x, int l, int r){
	if(!c) return 0;
	if(l == r){
		l = pos[l];
		ll cnt = min(a[l], c / w[l]);
		c -= cnt * w[l], cal();
		return cnt * v[l];
	}
	if(c >= f[x][bit + 1]){
		ll ans = g[x][bit + 1];
		c -= f[x][bit + 1], cal();
		return ans;
	}
	if(c >= f[x][bit] && c < h[x][bit]){
		ll ans = g[x][bit];
		c -= f[x][bit], cal();
		return ans;
	}
	int mid = l + r >> 1;
	return query(ls(x), l, mid) + query(rs(x), mid + 1, r);
}

int n, q;
int opt, x, y;

int main(){
	scanf("%d%d", &n, &q);
	for(int i = 1;i <= n;i++) scanf("%lld%lld%lld", &a[i], &w[i], &v[i]), pos[i] = i;
	sort(pos + 1, pos + 1 + n, cmp);
	for(int i = 1;i <= n;i++) rk[pos[i]] = i;
	build(1, 1, n);
	while(q--){
		scanf("%d", &opt);
		if(opt < 3){
			scanf("%d%d", &x, &y);
			a[y] += (opt == 1 ? 1 : -1) * x;
			modify(1, 1, n, rk[y]);
		}else{
			scanf("%lld", &c), bit = Bit, cal();
			printf("%lld\n", query(1, 1, n));
		}
	}
}