#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define sd(x) scanf("%d", &(x))
int mod;
inline int add(int x, int y){ x += y; if(x >= mod) x -= mod; return x;}
inline int sub(int x, int y){ x -= y; if(x < 0) x += mod; return x;}
inline int mul(int x, int y){ return (x * 1ll * y) % mod;}
inline int powr(int a, ll b){
	int x = 1 % mod;
	while(b){
		if(b & 1) x = mul(x, a);
		a = mul(a, a);
		b >>= 1;
	}
	return x;
}
inline int inv(int a){ return powr(a, mod - 2);}
inline int addinv(int a){ return sub(0, a);}
const int N = 1e5 +10;
int a[N];
set<int> S;
int main(){
	int m, n, s = 0, s2 = 0;
	sd(m), sd(n); mod = m;
	int invn = inv(n), inv2 = inv(2); int sn = mul(inv2, mul(n, n - 1));
	for(int i = 1; i <= n; i++){
		sd(a[i]); s = add(s, a[i]); S.insert(a[i]); s2 = add(s2, mul(a[i], a[i]));
	}
	if(n == 1){
		printf("%d %d\n", a[1], 0);
		return 0;
	}
	if(n == m){
		printf("%d %d\n", a[1], 1);
		return 0;
	}
	int sr = 0, sr2 = 0;
	for(int r = 0; r < n; r ++) sr = add(sr, r), sr2 = add(sr2, mul(r, r));
	for(int i = 2; i <= n; i++){
		int d = sub(a[i], a[1]);
		int x = mul(invn, sub(s, mul(sn, d)));
		int sm = add(mul(n, mul(x, x)), add(mul(2, mul(d, mul(x, sr))), mul(d, mul(d, sr2))));
		if(sm == s2){
			bool flag = 0;
			int val = x;
			for(int r = 0; r < n; r++){
				if(!S.count(val)){
					flag = 1;
					break;
				}
				val = add(val, d);
			}
			if(!flag){
				printf("%d %d\n", x, d);
				return 0;
			}
		}
	}
	printf("%d\n", -1);
}