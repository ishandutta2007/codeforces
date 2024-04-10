#include <bits/stdc++.h>

using namespace std;

const int p = 998244353;

int k, A, h;
int pw[50];
int rk[50], bit, cnt;
map<int, int> mp[2];

int build(int x, int l, int r){
	if(l == r) return l;
	int mid = l + r >> 1;
	int L = build(x << 1, l, mid), R = build(x << 1, mid + 1, r);
	if(bit & (1 << (cnt++))) swap(L, R);
	rk[L] = x + 1;
	return R;
}

int main(){
	scanf("%d%d%d", &k, &A, &h);
	if(k == 1){
		if((A + 2ll * A * A) % p == h) printf("1 2");
		else if((2 * A + 1ll * A * A) % p == h) printf("2 1");
		else printf("-1");
		return 0;
	}
	pw[0] = 1;for(int i = 1;i <= (1 << k);i++) pw[i] = 1ll * pw[i - 1] * A % p;
	for(bit = 0;bit < (1 << ((1 << (k - 1)) - 1));bit++){
		cnt = 0;
		int x = build(2, 1, 1 << (k - 1)), sum = 0;
		for(int i = 1;i <= (1 << (k - 1));i++) if(i ^ x) sum = (sum + 1ll * i * pw[rk[i]]) % p;
		mp[0][(sum + 1ll * x * pw[2]) % p] = bit;
		mp[1][(sum + 1ll * x * pw[1]) % p] = bit;
	}
	for(bit = 0;bit < (1 << ((1 << (k - 1)) - 1));bit++){
		cnt = 0;
		int x = build(2, (1 << (k - 1)) + 1, 1 << k), sum = 0;
		for(int i = (1 << (k - 1)) + 1;i <= (1 << k);i++) if(i ^ x) sum = (sum + 1ll * i * pw[rk[i]]) % p;
		if(mp[0].find((h + p - (sum + 1ll * x * pw[1]) % p) % p) != mp[0].end()){
			bit = mp[0][(h + p - (sum + 1ll * x * pw[1]) % p) % p], cnt = 0;
			int y = build(2, 1, 1 << (k - 1));
			rk[x] = 1, rk[y] = 2;
			for(int i = 1;i <= (1 << k);i++) printf("%d ", rk[i]);
			return 0;
		}
		if(mp[1].find((h + p - (sum + 1ll * x * pw[2]) % p) % p) != mp[1].end()){
			bit = mp[1][(h + p - (sum + 1ll * x * pw[2]) % p) % p], cnt = 0;
			int y = build(2, 1, 1 << (k - 1));
			rk[x] = 2, rk[y] = 1;
			for(int i = 1;i <= (1 << k);i++) printf("%d ", rk[i]);
			return 0;
		}
	}
	printf("-1");
}