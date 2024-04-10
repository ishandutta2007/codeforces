#include <bits/stdc++.h>
#define maxn 200086

using namespace std;

typedef long long ll;

struct Frac{
	ll a, b;
	Frac(){}
	Frac(ll _a, ll _b){
		ll gcd = __gcd(_a, _b);
		a = _a / gcd, b = _b / gcd;
	}
	inline bool operator < (const Frac &f) const {
		return a * f.b < b * f.a;
	}
};

int t, n, m, k[maxn];
Frac a[maxn];
int b[maxn];
int id[maxn];
ll val[maxn];
pair<Frac, int> sum[maxn];
int st[maxn][25];
int lg[maxn];
int p[maxn];

inline int query(int l, int r){
	if(l > r) return 998244353;
	int len = lg[r - l + 1];
	return min(st[l][len], st[r - (1 << len) + 1][len]);
}

int main(){
	for(int i = 2;i < maxn;i++) lg[i] = lg[i >> 1] + 1;
	scanf("%d", &t);
	while(t--){
		scanf("%d%d", &n, &m);
		for(int i = 1;i <= n;i++) scanf("%lld", &a[i].a), a[i].b = 1;
		int cnt = 0;
		for(int i = 1;i <= m;i++){
			scanf("%d", &k[i]);
			val[i] = 0;
			for(int j = 1;j <= k[i];j++){
				++cnt, scanf("%d", &b[cnt]);
				id[cnt] = i, val[i] += b[cnt];
			}
			sum[i] = {Frac(val[i], k[i]), i};
		}
		sort(sum + 1, sum + 1 + m), sort(a + 1, a + 1 + n);
		for(int i = 1;i <= m;i++) p[sum[i].second] = i;
		for(int i = m, x = n + 1;i;i--){
			while(x > 1 && !(a[x - 1] < sum[i].first)) x--;
			st[i][0] = n - x + 1 - (m - i);
		}
		for(int j = 1;j <= 20;j++){
			for(int i = 1;i + (1 << j) - 1 <= m;i++){
				st[i][j] = min(st[i][j - 1], st[i + (1 << (j - 1))][j - 1]);
			}
		}
		for(int i = 1;i <= cnt;i++){
			int x = id[i];
			Frac f(val[x] - b[i], k[x] - 1);
			int pos = upper_bound(sum + 1, sum + m + 1, (pair<Frac, int>){f, m + 1}) - sum;
			int ok = 1;
			if(f < Frac(val[x], k[x])){
				ok &= n - (lower_bound(a + 1, a + 1 + n, f) - a) + 1 - (m - pos) > 0;
				ok &= query(pos, p[x] - 1) + 1 > 0;
				ok &= query(1, pos - 1) > 0;
				ok &= query(p[x] + 1, m) > 0;
			}else{
				ok &= n - (lower_bound(a + 1, a + 1 + n, f) - a) + 1 - (m - (pos - 1)) > 0;
				ok &= query(p[x] + 1, pos - 1) - 1 > 0;
				ok &= query(1, p[x] - 1) > 0;
				ok &= query(pos, m) > 0;
			}
			printf("%d", ok);
		}
		puts("");
	}
}