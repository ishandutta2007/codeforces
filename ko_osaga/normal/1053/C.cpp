#include <bits/stdc++.h>
using namespace std;
using lint = long long;
const int MAXN = 200005;
const lint mod = 1e9 + 7;

int n, q;
int a[MAXN], w[MAXN];

struct bit{
	lint tree[MAXN];
	void add(int x, int v){
		while(x <= n){
			tree[x] += v;
			x += x&-x;
		}
	}
	lint query(int x){
		lint ret = 0;
		while(x){
			ret += tree[x];
			x -= x & -x;
		}
		return ret;
	}
	int kth(lint x){
		int pos = 0;
		for(int i=17; i>=0; i--){
			if(pos + (1<<i) <= n && tree[pos + (1<<i)] < x){
				pos += (1<<i);
				x -= tree[pos];
			}
		}
		return pos + 1;
	}
}bit, bit2;

void upd(int x, int y){
	bit.add(x, y - w[x]);
	bit2.add(x, 1ll * a[x] * (y - w[x]) % mod);
	w[x] = y;
}

lint query(int l, int r){
	lint lo = bit.query(l - 1);
	lint hi = bit.query(r);
	lint pos = (lo + hi + 1) / 2;
	int v = bit.kth(pos);
	lint mi = bit.query(v);
	lint ret = 1ll * a[v] * ((mi - lo) % mod) - 1ll * a[v] * ((hi - mi) % mod);
	ret -= bit2.query(v) - bit2.query(l - 1);
	ret += bit2.query(r) - bit2.query(v);
	ret %= mod;
	ret += mod;
	ret %= mod;
	return ret;
}

int main(){
	scanf("%d %d",&n,&q);
	for(int i=1; i<=n; i++){
		scanf("%d",&a[i]);
		a[i] += n - i;
	}
	for(int i=1; i<=n; i++){
		scanf("%d",&w[i]);
		bit.add(i, w[i]);
		bit2.add(i, 1ll * w[i] * a[i] % mod);
	}
	while(q--){
		int x, y; scanf("%d %d",&x,&y);
		if(x < 0){
			upd(-x, y);
		}
		else{
			printf("%lld\n", query(x, y) % 1000000007);
		}
	}
}