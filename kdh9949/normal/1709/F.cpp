#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;
using pii = pair<int, int>;
using pil = pair<int, ll>;
using pli = pair<ll, int>;
using pll = pair<ll, ll>;

using vint = vector<int>;
using vll = vector<ll>;
using vld = vector<ld>;
using vpii = vector<pii>;
using vpil = vector<pil>;
using vpli = vector<pli>;
using vpll = vector<pll>;

#define x first
#define y second
#define all(v) (v).begin(),(v).end()
#define ints(args...) int args; readln(args);
#define lls(args...) ll args; readln(args);
#define strs(args...) string args; readln(args);

template<typename... Args>
void readln(Args&... args) { ((cin >> args), ...); }
template<typename... Args>
void writeln(Args... args) { ((cout << args << " "), ...); cout << '\n'; }

typedef ll base;
const ll mod = 998244353;
base ipow(base x, base k) {
  base r = 1;
  for(; k; k /= 2, x = x * x % mod)
    if(k & 1) r = r * x % mod;
  return r;
}
void ntt(vector<base> &a, bool inv){
	int n = a.size(), j = 0;
	vector<base> roots(n/2);
	for(int i=1; i<n; i++){
		int bit = (n >> 1);
		while(j >= bit){
			j -= bit;
			bit >>= 1;
		}
		j += bit;
		if(i < j) swap(a[i], a[j]);
	}
	int ang = ipow(3, (mod - 1) / n);
	if(inv) ang = ipow(ang, mod - 2);
	for(int i=0; i<n/2; i++){
		roots[i] = (i ? (1ll * roots[i-1] * ang % mod) : 1);
	}
	for(int i=2; i<=n; i<<=1){
		int step = n / i;
		for(int j=0; j<n; j+=i){
			for(int k=0; k<i/2; k++){
				base u = a[j+k], v = a[j+k+i/2] * roots[step * k] % mod;
				a[j+k] = (u+v) % mod;
				a[j+k+i/2] = (u-v+mod) % mod;
			}
		}
	}
	if(inv) for(int i=0; i<n; i++) a[i] = a[i] * ipow(n, mod - 2) % mod;
}

vector<ll> multiply(vector<ll> &v, vector<ll> &w){
	vector<base> fv(v.begin(), v.end()), fw(w.begin(), w.end());
	int n = 2; while(n < v.size() + w.size()) n <<= 1;
	fv.resize(n); fw.resize(n);
	ntt(fv, 0); ntt(fw, 0);
	for(int i=0; i<n; i++) fv[i] *= fw[i];
	ntt(fv, 1);
  return fv;
}

int main() {
  ios::sync_with_stdio(false); cin.tie(nullptr);

  ints(n, k, f);
  vector<vll> D(n + 1), E(n + 1);
  D[n] = vll(k + 1, 1);
  E[n] = multiply(D[n], D[n]);
  for(int i = n - 1; i >= 1; i--) {
    D[i] = vll(k + 1);
    ll sum = 0;
    for(ll x : E[i + 1]) sum += x;
    for(int j = 0; j <= k; j++) {
      D[i][j] = (E[i + 1][j] * (k - j) + sum) % mod;
      sum -= E[i + 1][j];
    }
    E[i] = multiply(D[i], D[i]);
  }
  cout << (E[1].size() >= f + 1 ? E[1][f] : 0LL) << '\n';
  return 0;
}