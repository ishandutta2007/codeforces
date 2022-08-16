#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pii pair<int, int>
#define all(c) ((c).begin()), ((c).end())
#define sz(x) ((int)(x).size())

#ifdef LOCAL
#include <print.h>
#else
#define trace(...)
#endif

const int N = 1e5 + 10, mod = 1e9 + 7;
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

int main(){
	ios_base::sync_with_stdio(false); 
	cin.tie(NULL); // Remove in interactive problems
	pre();
	int n; cin >> n;
	vector<int> a(n);
	ll s = 0;
	map<int, int> freq;
	for(int & x : a){
		cin >> x, s += x;
		freq[x]++;
	}
	int total = fact[n];
	for(auto it : freq) total = mul(total, invfact[it.second]);

	if(s % n != 0){
		cout << 0 << endl;
		return 0;
	}
	int src = 0, snk = 0;
	ll t = s / n;
	map<int, int> F1, F2;
	for(int i = 0; i < n; i++){
		if(a[i] < t){
			snk++;
			F1[a[i]]++;
		}
		else if(a[i] > t){
			src++;
			F2[a[i]]++;
		}
	}
	if(min(src, snk) <= 1){
		cout << total << endl;
		return 0;
	}
	// all sources before all sinks * 2
	int ans = mul(2, mul(fact[src], fact[snk]));
	for(auto it : F1) ans = mul(ans, invfact[it.second]);
	for(auto it : F2) ans = mul(ans, invfact[it.second]);
	ans = mul(ans, C(n, src + snk));
	cout << ans << endl;
}