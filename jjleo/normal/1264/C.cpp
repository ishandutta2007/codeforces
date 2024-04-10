#include <bits/stdc++.h>
#define maxn 200086

using namespace std;

const int p = 998244353;

inline int fpow(int x, int y){
	int ans = 1;
	while(y){
		if(y & 1) ans = 1ll * ans * x % p;
		x = 1ll * x * x % p;
		y >>= 1;
	}
	return ans;
}

const int inv100 = fpow(100, p - 2);

int n, q, x;
int a[maxn], sum[maxn], inv[maxn];

set<int> st;
int ans;

inline int cal(int l, int r){
	return 1ll * (inv[r] + p - inv[l - 1]) * sum[r + 1] % p;
}

int main(){
	scanf("%d%d", &n, &q);
	for(int i = 1;i <= n;i++){
		scanf("%d", &a[i]);
		a[i] = 1ll * a[i] * inv100 % p;
	}
	sum[n + 1] = 1; 
	for(int i = n;i;i--) sum[i] = 1ll * a[i] * sum[i + 1] % p;
	inv[1] = fpow(sum[1], p - 2);
	for(int i = 2;i <= n;i++) inv[i] = 1ll * inv[i - 1] * a[i - 1] % p;
	for(int i = 2;i <= n;i++) inv[i] = (inv[i - 1] + inv[i]) % p; 
	ans = inv[n];
	st.insert(1), st.insert(n + 1); 
	while(q--){
		scanf("%d", &x);
		set<int>::iterator it = st.lower_bound(x);
		if(*it != x){
			int l = *prev(it), r = *it - 1;
			ans = (ans + p - cal(l, r)) % p;
			ans = (1ll * ans + cal(l, x - 1) + cal(x, r)) % p;
			st.insert(x);
		}else{
			int l = *prev(it), r = *next(it) - 1;
			ans = (1ll * ans + 2 * p - cal(l, x - 1) - cal(x, r)) % p;
			ans = (ans + cal(l, r)) % p;
			st.erase(x);
		}
		printf("%d\n", ans);
	}
}