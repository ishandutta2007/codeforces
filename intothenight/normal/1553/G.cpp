#include <bits/stdc++.h>
using namespace std;

struct number_theory{
	int SZ;
	vector<int> lpf, prime; // least prime factor, primes, mobius function, totient function, number of multiples
	number_theory(int SZ): SZ(SZ), lpf(SZ + 1){ // O(SZ)
		lpf[0] = lpf[1] = numeric_limits<int>::max() / 2;
		for(auto i = 2; i <= SZ; ++ i){
			if(!lpf[i]) lpf[i] = i, prime.push_back(i);
			for(auto j = 0; j < (int)prime.size() && prime[j] <= lpf[i] && prime[j] * i <= SZ; ++ j) lpf[prime[j] * i] = prime[j];
		}
	}
	vector<int> precalc_mobius() const{
		vector<int> mobius(SZ + 1, 1);
		for(auto i = 2; i <= SZ; ++ i){
			if(i / lpf[i] % lpf[i]) mobius[i] = -mobius[i / lpf[i]];
			else mobius[i] = 0;
		}
		return mobius;
	}
	vector<int> precalc_phi() const{
		vector<int> phi(SZ + 1, 1);
		for(auto i = 2; i <= SZ; ++ i){
			if(i / lpf[i] % lpf[i]) phi[i] = phi[i / lpf[i]] * (lpf[i] - 1);
			else phi[i] = phi[i / lpf[i]] * (lpf[i] - 1);
		}
		return phi;
	}
	bool is_prime(int x) const{
		assert(0 <= x && x <= SZ);
		return lpf[x] == x;
	}
	int mu_large(long long x) const{ // O(sqrt(x))
		int res = 1;
		for(auto i = 2LL; i * i <= x; ++ i) if(x % i == 0){
			if(x / i % i) return 0;
			x /= i, res = -res;
		}
		if(x > 1) res = -res;
		return res;
	}
	long long phi_large(long long x) const{ // O(sqrt(x))
		long long res = x;
		for(auto i = 2LL; i * i <= x; ++ i) if(x % i == 0){
			while(x % i == 0) x /= i;
			res -= res / i;
		}
		if(x > 1) res -= res / x;
		return res;
	}
	// returns an array is_prime of length high-low where is_prime[i] = [low+i is a prime]
	vector<bool> sieve(long long low, long long high) const{
		assert(high - 1 <= 1LL * SZ * SZ);
		vector<bool> is_prime(high - low, true);
		for(auto p: prime) for(auto x = max(1LL * p, (low + p - 1) / p) * p; x < high; x += p) is_prime[x - low] = false;
		for(auto x = 1; x >= low; -- x) is_prime[x - low] = false;
		return is_prime;
	}
};
/*
Given a set A of n-tuples of postive integers and functions f, g
\sum_{x \in A} f(gcd(x)) g(x)
= \sum_{l=1}^\infty(f conv mu)(l) \sum{x \in A and l | x_i for all i} g(x)
*/

struct disjoint_set{
	vector<int> p;
	disjoint_set(int n): p(n, -1){ }
	bool share(int a, int b){ return root(a) == root(b); }
	int size(int u){ return -p[root(u)]; }
	int root(int u){ return p[u] < 0 ? u : p[u] = root(p[u]); } // O(alpha(n))
	bool merge(int u, int v){
		u = root(u), v = root(v);
		if(u == v) return false;
		if(p[u] > p[v]) swap(u, v);
		p[u] += p[v], p[v] = u;
		return true;
	}
	vector<vector<int>> group_up(){
		vector<vector<int>> g((int)p.size());
		for(auto i = 0; i < (int)p.size(); ++ i) g[root(i)].push_back(i);
		g.erase(remove_if(g.begin(), g.end(), [&](auto &s){ return s.empty(); }), g.end());
		return g;
	}
};

int main(){
	cin.tie(0)->sync_with_stdio(0);
	cin.exceptions(ios::badbit | ios::failbit);
	const int mx = 1e6 + 1;
	number_theory nt(mx);
	disjoint_set dsu(mx + 1);
	int n, qn;
	cin >> n >> qn;
	vector<int> a(n);
	for(auto i = 0; i < n; ++ i){
		int x;
		cin >> x;
		a[i] = x;
		static vector<int> p;
		p.clear();
		while(x > 1){
			int lp = nt.lpf[x];
			p.push_back(lp);
			while(x % lp == 0){
				x /= lp;
			}
		}
		for(auto i = 1; i < (int)p.size(); ++ i){
			dsu.merge(p[i - 1], p[i]);
		}
	}
	vector<int> id(mx + 1, -1);
	auto grps = dsu.group_up();
	for(auto t = 0; t < (int)grps.size(); ++ t){
		for(auto x: grps[t]){
			id[x] = t;
		}
	}
	vector<array<int, 2>> links;
	for(auto i = 0; i < n; ++ i){
		vector<int> gid{id[nt.lpf[a[i]]]};
		for(auto x = a[i] + 1; x > 1; ){
			int p = nt.lpf[x];
			gid.push_back(id[p]);
			while(x % p == 0){
				x /= p;
			}
		}
		sort(gid.begin(), gid.end());
		gid.erase(unique(gid.begin(), gid.end()), gid.end());
		for(auto s = 0; s < (int)gid.size(); ++ s){
			for(auto t = s + 1; t < (int)gid.size(); ++ t){
				links.push_back({gid[s], gid[t]});
				links.push_back({gid[t], gid[s]});
			}
		}
	}
	sort(links.begin(), links.end());
	for(auto qi = 0; qi < qn; ++ qi){
		int i, j;
		cin >> i >> j, -- i, -- j;
		if(dsu.share(nt.lpf[a[i]], nt.lpf[a[j]])){
			cout << "0\n";
		}
		else if(binary_search(links.begin(), links.end(), array{id[nt.lpf[a[i]]], id[nt.lpf[a[j]]]})){
			cout << "1\n";
		}
		else{
			cout << "2\n";
		}
	}
	return 0;
}

/*
5 1
20 11 3 7 9 
4 5
*/

////////////////////////////////////////////////////////////////////////////////////////
//                                                                                    //
//                                   Coded by Aeren                                   //
//                                                                                    //
////////////////////////////////////////////////////////////////////////////////////////