#include<bits/stdc++.h>
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define pb push_back
using namespace std;
using ll = long long;
using vi = vector<ll>;
using pi = pair<int, int>;
using vpi = vector<pi>;
const int maxn = 1<<21;
//const ll mod = 20998782977, inv2 = 10499391489, rt = 147624773;
const ll mod = 998244353, inv2 = (mod+1)/2, rt = 733596141;
//const __int128 r = (__int128(1)<<70)/mod, ibig = 1;
inline ll mul(ll x, ll y) {
	return x*y%mod;
	//FOR BIG MODs
	//ll t = __int128(x)*y - ((r*x*y)>>70)*mod;
	//if(t>=mod) t-= mod;
	//return t;
}
inline ll add(ll x, ll y) {
	return (x+y)<mod?x+y:(x+y-mod);
}
ll pw[maxn], p2[22];
void setup() {
	pw[0] = p2[0] = 1;
	for(int i = 1; i < maxn; i++) pw[i] = mul(pw[i-1], rt);
	for(int i = 1; i < 22; i++) p2[i] = mul(p2[i-1], inv2);
}
	
void ntt(ll *res, ll *a, ll n, ll k = 1) {
	if(n == 1) {
		*res = *a;
		return;
	}
	int t = maxn/n;
	n >>= 1;
	ntt(res, a, n, k<<1);
	ntt(res + n, a + k, n, k<<1);
	for(int i = 0, j = 0; i < n; i++, j += t) {
		ll u = res[i], v = mul(res[i+n], pw[j]);
		res[i] = add(u, v);
		res[i+n] = add(u, mod-v);
	}
}
vector<ll> mul(vector<ll> a, vector<ll> b) {
	int n = a.size()+b.size()-1;
	while(n&(n-1)) n++;
	while(a.size() < n) a.pb(0);
	while(b.size() < n) b.pb(0);
	vi A(n), B(n);
	ntt(A.data(), a.data(), n);
	ntt(B.data(), b.data(), n);
	for(int i = 0; i < n; i++) A[i] = mul(A[i], B[i]);
	ntt(B.data(), A.data(), n);
	for(auto &i : B) i = mul(i, p2[__lg(n)]);
	reverse(1 + all(B));
	return B;
}
vector<ll> bp(vector<ll> a, int p) {
	vector<ll> res{1};
	while(p) {
		if(p&1) res = mul(res, a);
		p>>=1, a = mul(a, a);
	}
	return res;
}
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	setup();
	int n, k;
	cin >> n >> k;
	vi a(10);
	for(int t, i = 0; i < k; i++) cin >> t, a[t]++;
	a = bp(a, n/2);
	int ans = 0;
	for(auto &i : a) {
		ans = (ans + i*1ll*i%mod)%mod;
	}
	cout << ans;
}
// 20998782977