#include<bits/stdc++.h>
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define pb push_back
using namespace std;
using ll = long long;
using vi = vector<int>;
using pi = pair<int, int>;
using vpi = vector<pi>;
const int maxn = 1<<21, mod = 998244353, inv2 = 499122177, rt = 733596141;
inline int mul(int i, int j) {
	return i*1ll*j%mod;
}
inline int add(int i, int j) {
	i += j;
	return i >= mod ? i - mod : i;
}
int pw[maxn], p2[22];
void setup() {
	pw[0] = p2[0] = 1;
	for(int i = 1; i < maxn; i++) {
		pw[i] = mul(pw[i-1], rt);
	}
	for(int i = 1; i < 22; i++) p2[i] = mul(p2[i-1], inv2);
}
void ntt(int *res, int *a, int n, int k = 1) {
	if(n == 1) {
		*res = *a;
		return;
	}
	int t = maxn/n;
	n >>= 1;
	ntt(res, a, n, k<<1);
	ntt(res+n, a + k, n, k<<1);
	for(int i = 0, j = 0; i < n; i++, j += t) {
		int u = res[i], v = mul(res[i+n], pw[j]);
		res[i] = add(u, v);
		res[i+n] = add(u, mod-v);
	}
}
vector<int> mul(vector<int> a, vector<int> b) {
	int n = a.size()+b.size()-1;
	while(__builtin_popcount(n)!=1) n++;
	while(a.size() < n) a.pb(0);
	while(b.size() < n) b.pb(0);
	vi A(n), B(n);
	ntt(A.data(), a.data(), n);
	ntt(B.data(), b.data(), n);
	for(int i = 0; i < n; i++) A[i] = mul(A[i], B[i]);
	ntt(B.data(), A.data(), n);
	for(auto &i : B) i = mul(i, p2[__lg(n)]);
	reverse(B.begin()+1, B.end());
	return B;
}
int n, m;
vi p, a;
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	setup();
	cin >> n >> m;
	p.resize(m+1);
	for(int t, i = 0; i < n; i++) cin >> t, p[t]++;
	vi a, b, c = p;
	for(int i = 0; i < 2; i++) {
		a = b = c;
		auto t = mul(a, b);
		for(int i = 0; i <= m; i++)
			c[i] = add(c[i], t[i]);
		for(int i = 0; i <= m; i++) {
			if(c[i]>1) c[i] = 2;
		}
	}
	for(int i = 0; i <= m; i++) {
		if(p[i] == 0 && c[i]) return cout << "NO", 0;
		if(c[i] > 1) p[i] = 0;
	}
	cout <<"YES\n" << count(all(p), 1) << '\n';
	for(int i = 0; i <= m; i++) if(p[i]) cout << i << " ";
		
}