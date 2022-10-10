#include <bits/stdc++.h>
using namespace std;

struct number_theory{
	int SZ;
	vector<int> lpf, prime, mu, phi; // least prime factor, primes, mobius function, totient function, number of multiples
	number_theory(int SZ): SZ(SZ), lpf(SZ + 1), mu(SZ + 1, 1), phi(SZ + 1, 1){ // O(SZ)
		lpf[0] = lpf[1] = numeric_limits<int>::max() / 2;
		for(int i = 2; i <= SZ; ++ i){
			if(!lpf[i]) lpf[i] = i, prime.push_back(i);
			if(i / lpf[i] % lpf[i]) mu[i] = -mu[i / lpf[i]], phi[i] = phi[i / lpf[i]] * (lpf[i] - 1);
			else mu[i] = 0, phi[i] = phi[i / lpf[i]] * lpf[i];
			for(int j = 0; j < (int)prime.size() && prime[j] <= lpf[i] && prime[j] * i <= SZ; ++ j) lpf[prime[j] * i] = prime[j];
		}
	}
	bool is_prime(int x){
		assert(0 <= x && x <= SZ);
		return lpf[x] == x;
	}
	int mu_large(long long x){ // O(sqrt(x))
		int res = 1;
		for(long long i = 2; i * i <= x; ++ i) if(x % i == 0){
			if(x / i % i) return 0;
			x /= i, res = -res;
		}
		if(x > 1) res = -res;
		return res;
	}
	long long phi_large(long long x){ // O(sqrt(x))
		long long res = x;
		for(long long i = 2; i * i <= x; ++ i) if(x % i == 0){
			while(x % i == 0) x /= i;
			res -= res / i;
		}
		if(x > 1) res -= res / x;
		return res;
	}
	template<class T> // O(n log n)
	vector<T> convolute(const vector<T> &a, const vector<T> &b){
		int n = (int)a.size();
		assert(n == (int)b.size());
		vector<T> res(n);
		for(int x = 1; x < n; ++ x) for(int y = 1; x * y < n; ++ y) res[x * y] += a[x] * b[y];
		return res;
	}
	template<class T> // O(n log n log k)
	vector<T> conv_exp(const vector<T> &a, long long e){
		int n = (int)a.size();
		vector<T> res(n), p(a.begin(), a.end());
		res[1] = 1;
		for(; e; e >>= 1, p = convolute(a, a)) if(e & 1) res = convolute(res, p);
		return res;
	}
	template<class T> // O(n log n)
	vector<T> mobius_transform(const vector<T> &a){
		int n = (int)a.size();
		vector<T> res(n);
		for(int x = 1; x < n; ++ x) for(int mx = x; mx < n; mx += x) res[mx] += a[x];
		return res;
	}
	template<class T> // O(n log n)
	vector<T> inverse_transform(const vector<T> &a){
		int n = (int)a.size();
		vector<T> res(n);
		for(int x = 1; x < n; ++ x) for(int y = 1; x * y < n; ++ y) res[x * y] += a[x] * mu[y];
		return res;
	}
	vector<int> mul_cnt;
	bool mul_cnt_ready = false;
	template<class T> // O(SZ log SZ)
	void init_mul_cnt(const vector<int> &a){
		mul_cnt_ready = true;
		vector<int> cnt(SZ + 1);
		mul_cnt.assign(SZ + 1, 0);
		for(auto x: a) ++ cnt[x];
		for(int x = 1; x <= SZ; ++ x) for(int mx = x; mx <= SZ; mx += x) mul_cnt[x] += cnt[mx];
	}
	template<class T> // Requires Z_p, O((SZ / g) log k)
	T count_tuples_with_gcd(int k, int g = 1){
		assert(mul_cnt_ready);
		T res = 0;
		for(int x = SZ / g; x >= 1; -- x) res += mu[x] * (T(mul_cnt[x * g]) ^ k);
		return res;
	}
};

struct dfs_bipartite_matching{
	int n, m, flow = 0;
	vector<vector<int>> adj;
	vector<int> pu, pv; // u is matched with pu[u] and v with pv[v], -1 if no match
	dfs_bipartite_matching(int n, int m): n(n), m(m), pu(n, -1), pv(m, -1), cur(n), adj(n){ }
	int insert(int from, int to){
		adj[from].push_back(to);
		return (int)adj[from].size() - 1;
	}
	int id = 0;
	vector<int> cur;
	bool dfs(int u){
		cur[u] = id;
		for(auto v: adj[u]) if(!~pv[v]){
			pu[u] = v, pv[v] = u;
			return true;
		}
		for(auto v: adj[u]) if(cur[pv[v]] != id && dfs(pv[v])){
			pu[u] = v, pv[v] = u;
			return true;
		}
		return false;
	}
	int solve(){ // O(VE)
		while(true){
			int augment = 0;
			++ id;
			for(int u = 0; u < n; ++ u) if(pu[u] == -1 && dfs(u)) ++ augment;
			if(!augment) break;
			flow += augment;
		}
		return flow;
	}
	int run_once(int v){
		if(pu[v] != -1) return 0;
		++ id;
		return dfs(v);
	}
	pair<vector<int>, vector<int>> minimum_vertex_cover(){
		solve();
		vector<int> L, R, visL(n), visR(m);
		function<void(int)> dfs = [&](int u){
			visL[u] = true;
			for(auto v: adj[u]) if(v != pu[u] && !visR[v]){
				visR[v] = true, R.push_back(v);
				if(~pv[v]) dfs(pv[v]);
			}
		};
		for(int u = 0; u < n; ++ u) if(!visL[u] && pu[u] == -1) dfs(u);
		for(int u = 0; u < n; ++ u) if(!visL[u]) L.push_back(u);
		return {L, R};
	}
};

int main(){
	cin.tie(0)->sync_with_stdio(0);
	cin.exceptions(ios::badbit | ios::failbit);
	int n;
	cin >> n;
	vector<int> a(n), even, odd;
	for(auto u = 0; u < n; ++ u){
		cin >> a[u];
		(a[u] & 1 ? odd : even).push_back(u);
	}
	if((int)even.size() != (int)odd.size()){
		cout << "Impossible\n";
		return 0;
	}
	number_theory nt(200000);
	dfs_bipartite_matching M((int)even.size(), (int)odd.size());
	for(auto i = 0; i < (int)even.size(); ++ i){
		int u = even[i];
		for(auto j = 0; j < (int)odd.size(); ++ j){
			int v = odd[j];
			if(nt.is_prime(a[u] + a[v])){
				M.insert(i, j);
			}
		}
	}
	if(M.solve() < (int)even.size()){
		cout << "Impossible\n";
		return 0;
	}
	vector<vector<int>> adj(n), bad(n, vector<int>(n));
	for(auto i = 0; i < (int)even.size(); ++ i){
		int u = even[i], v = odd[M.pu[i]];
		adj[u].push_back(v), adj[v].push_back(u);
		bad[i][M.pu[i]] = true;
	}
	M = {(int)even.size(), (int)odd.size()};
	for(auto i = 0; i < (int)even.size(); ++ i){
		int u = even[i];
		for(auto j = 0; j < (int)odd.size(); ++ j){
			int v = odd[j];
			if(!bad[i][j] && nt.is_prime(a[u] + a[v])){
				M.insert(i, j);
			}
		}
	}
	if(M.solve() < (int)even.size()){
		cout << "Impossible\n";
		return 0;
	}
	for(auto i = 0; i < (int)even.size(); ++ i){
		int u = even[i], v = odd[M.pu[i]];
		adj[u].push_back(v), adj[v].push_back(u);
	}
	vector<vector<int>> res;
	vector<bool> vis(n);
	for(auto u = 0; u < n; ++ u){
		if(!vis[u]){
			vector<int> cycle;
			function<void(int)> dfs = [&](int u){
				cycle.push_back(u);
				vis[u] = true;
				for(auto v: adj[u]){
					if(!vis[v]){
						dfs(v);
					}
				}
			};
			dfs(u);
			res.push_back(cycle);
		}
	}
	cout << (int)res.size() << "\n";
	for(auto a: res){
		cout << (int)a.size() << " ";
		for(auto u: a){
			cout << u + 1 << " ";
		}
		cout << "\n";
	}
	return 0;
}

/*

*/

////////////////////////////////////////////////////////////////////////////////////////
//                                                                                    //
//                                   Coded by Aeren                                   //
//                                                                                    //
////////////////////////////////////////////////////////////////////////////////////////