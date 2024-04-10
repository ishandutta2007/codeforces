#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define F first
#define S second
const int N = 2e5 + 10, mod = 1e9 + 7;
int fact[N], invfact[N];
inline int add(int x, int y){ x += y; if(x >= mod) x -= mod; return x;}
inline int sub(int x, int y){ x -= y; if(x < 0) x += mod; return x;}
inline int mul(int x, int y){ return (((ll) x) * y) % mod;}
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
void pre(){
	fact[0] = invfact[0] = 1;
	for(int i = 1;i < N; i++) fact[i] = mul(i, fact[i - 1]);
	invfact[N - 1] = inv(fact[N - 1]);
	for(int i = N - 2; i >= 1; i--) invfact[i] = mul(invfact[i + 1], i + 1);
	assert(invfact[1] == 1);
}
inline int C(int n, int k){
	if(n < k || k < 0) return 0;
	return mul(fact[n], mul(invfact[k], invfact[n - k]));
}

map<pair<int, int>, int > dp;
set<pair<int, int> > st;
int main(){
	pre();
	int n, h, w, x, y;
	cin >> h >> w >> n;
	for(int i = 1; i <= n; i++){
		cin >> x >> y;
		st.insert({x, y});
	}
	st.insert({h, w});
	dp[{1, 1}] = 1;
	for(auto it : st){
		int x = it.F, y = it.S;
		int ans = C(x - 1 + y - 1, y - 1);
		for(auto it2 : st){
			int x1 = it2.F, y1 = it2.S;
			if(x >= x1 && y >= y1){
				ans = sub(ans, mul(C(x - x1 + y - y1, y - y1), dp[{x1, y1}]));
			}
		}
		dp[it] = ans;
	}
	cout << dp[{h, w}];
}