#include <bits/stdc++.h>
using namespace std;
const int MAXN = 100005;
const int mod = 998244353;
const int prr = 3;
using lint = long long;
using ll = long long;
using pi = pair<int, int>;

vector<int> gph[MAXN];
int par[MAXN], sz[MAXN];
lint dp[MAXN], up[MAXN];

lint dfs2(int x, int p){
	lint ans = 0;
	lint tmp = 0;
	for(auto &i : gph[x]){
		if(i == p) continue;
		ans += dfs2(i, x);
		ans += tmp * dp[i];
		tmp += dp[i];
		ans %= mod;
		tmp %= mod;
		dp[x] += dp[i];
		dp[x] %= mod;
	}
	ans += up[x] * dp[x] % mod;
	return ans % mod;
}

void dfs(int x, int p){
	sz[x]++;
	for(auto &i : gph[x]){
		if(i == p) continue;
		par[i] = x;
		dfs(i, x);
		sz[x] += sz[i];
	}
}

lint ipow(int x, int p){
	lint ret = 1, piv = x;
	while(p){
		if(p & 1) ret = ret * piv % mod;
		piv = piv * piv % mod;
		p >>= 1;
	}
	return ret % mod;
}
using vi = vector<lint>;

namespace fft{
	typedef lint base;
	void fft(vector<base> &a, bool inv){
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
		int ang = ipow(prr, (mod - 1) / n);
		if(inv) ang = ipow(ang, mod - 2);
		for(int i=0; i<n/2; i++){
			roots[i] = (i ? (1ll * roots[i-1] * ang % mod) : 1);
		}
		for(int i=2; i<=n; i<<=1){
			int step = n / i;
			for(int j=0; j<n; j+=i){
				for(int k=0; k<i/2; k++){
					base u = a[j+k], v = a[j+k+i/2] * roots[step * k] % mod;
					a[j+k] = (u+v);
					while(a[j+k] >= mod) a[j+k] -= mod;
					a[j+k+i/2] = (u-v+mod);
					while(a[j+k+i/2] >= mod) a[j+k+i/2] -= mod;
				}
			}
		}
		if(inv) for(int i=0; i<n; i++) a[i] = a[i] * ipow(n, mod - 2) % mod;
	}

	vector<lint> multiply(vector<lint> &v, vector<lint> &w){
		int new_size = v.size() + w.size() - 1;
		vector<base> fv(v.begin(), v.end()), fw(w.begin(), w.end());
		int n = 2; while(n < v.size() + w.size()) n <<= 1;
		fv.resize(n); fw.resize(n);
		fft(fv, 0); fft(fw, 0);
		for(int i=0; i<n; i++) fv[i] = fv[i] * fw[i] % mod;
		fft(fv, 1);
		vector<lint> ret(new_size);
		for(int i=0; i<new_size; i++) ret[i] = fv[i];
		return ret;
	}
};

vector<lint> getGF(vector<int> v){
	auto cmp = [&](vi &x, vi &y){
		return x.size() > y.size();
	};
	priority_queue<vi, vector<vi>, decltype(cmp)> pq(cmp);
	for(int i=0; i<v.size(); i++){
		vi x = {1, v[i]};
		pq.push(x);
	}
	while(pq.size() > 1){
		auto l = pq.top();
		pq.pop();
		auto r = pq.top();
		pq.pop();
		pq.push(fft::multiply(l, r));
	}
	return pq.top();
}

int n, K;
lint fact[MAXN], invf[MAXN], prec[MAXN];

int main(){
	fact[0] = invf[0] = 1;
	for(int i=1; i<MAXN; i++){
		fact[i] = fact[i-1] * i % mod;
		invf[i] = ipow(fact[i], mod - 2);
	}
	scanf("%d %d",&n,&K);
	if(n == 1){
		puts("0");
		return 0;
	}
	if(K == 1){
		lint ans = 1ll * n * (n - 1) / 2;
		printf("%lld\n", ans % mod);
		return 0;
	}
	for(int i=0; i<=K; i++) prec[i] = fact[K] * invf[K - i] % mod; 
	for(int i=1; i<n; i++){
		int s, e;
		scanf("%d %d",&s,&e);
		gph[s].push_back(e);
		gph[e].push_back(s);
	}
	dfs(1, 0);
	for(int i=1; i<=n; i++){
		vector<int> v;
		vector<pi> w;
		for(auto &j : gph[i]){
			if(j == par[i]) v.push_back(n - sz[i]);
			else v.push_back(sz[j]);
			w.push_back(pi(v.back(), j));
		}
		sort(w.begin(), w.end());
		auto k = getGF(v);
		int vvv = i;
		for(int i=0; i<w.size(); ){
			int e = i;
			while(e < w.size() && w[i].first == w[e].first) e++;
			lint sinv = ipow(w[i].first, mod - 2);
			lint B = 0, ans = 0;
			for(int j=(int)k.size()-2; j>=0; j--){
				lint nxtB = (k[j+1] + mod - B) * sinv % mod;
				ans += nxtB * prec[j] % mod;
				B = nxtB;
			}
			ans %= mod;
			for(int j=i; j<e; j++){
				if(par[vvv] == w[j].second){
					dp[vvv] = ans;
				}
				else{
					up[w[j].second]  = ans;
				}
			}
			i = e;
		}
	}
	cout << dfs2(1, 0) << endl;
}