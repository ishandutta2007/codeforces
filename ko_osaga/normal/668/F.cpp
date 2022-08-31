#include <bits/stdc++.h>
using namespace std;
using pi = pair<int, int>;
using lint = long long;
const int MAXN = 10005;
const int mod = 1e9 + 7;

inline void fasterLLDivMod(unsigned long long x, unsigned y, unsigned &out_d, unsigned &out_m) {
	unsigned xh = (unsigned)(x >> 32), xl = (unsigned)x, d, m;
#ifdef __GNUC__
	asm(
		"divl %4; \n\t"
		: "=a" (d), "=d" (m)
		: "d" (xh), "a" (xl), "r" (y)
	);
#else
	__asm {
		mov edx, dword ptr[xh];
		mov eax, dword ptr[xl];
		div dword ptr[y];
		mov dword ptr[d], eax;
		mov dword ptr[m], edx;
	};
#endif
	out_d = d; out_m = m;
}

//x < 2^32 * MOD !
inline unsigned Mod(unsigned long long x){
	unsigned y = mod;
//	return x % y;
	unsigned dummy, r;
	fasterLLDivMod(x, y, dummy, r);
	return r;
}

lint ipow(lint x, lint p){
	lint ret = 1, piv = x % mod;
	while(p){
		if(p & 1) ret = ret * piv % mod;
		piv = piv * piv % mod;
		p >>= 1;
	}
	return ret;
}

namespace BBLA{
	vector<int> berlekamp_massey(vector<int> x){
		vector<int> ls, cur;
		int lf, ld;
		for(int i=0; i<x.size(); i++){
			lint t = 0;
			for(int j=0; j<cur.size(); j++){
				t = (t + 1ll * x[i-j-1] * cur[j]) % mod;
			}
			if((t - x[i]) % mod == 0) continue;
			if(cur.empty()){
				cur.resize(i+1);
				lf = i;
				ld = (t - x[i]) % mod;
				continue;
			}
			lint k = -(x[i] - t) * ipow(ld, mod - 2) % mod;
			vector<int> c(i-lf-1);
			c.push_back(k);
			for(auto &j : ls) c.push_back(-j * k % mod);
			if(c.size() < cur.size()) c.resize(cur.size());
			for(int j=0; j<cur.size(); j++){
				c[j] = (c[j] + cur[j]) % mod;
			}
			if(i-lf+(int)ls.size()>=(int)cur.size()){
				tie(ls, lf, ld) = make_tuple(cur, i, (t - x[i]) % mod);
			}
			cur = c;
		}
		for(auto &i : cur) i = (i % mod + mod) % mod;
		return cur;
	}
	int get_nth(vector<int> rec, vector<int> dp, lint n){
		int m = rec.size();
		vector<int> s(m), t(m);
		s[0] = 1;
		if(m != 1) t[1] = 1;
		else t[0] = rec[0];
		auto mul = [&rec](vector<int> v, vector<int> w){
			int m = v.size();
			vector<int> t(2 * m);
			for(int j=0; j<m; j++){
				for(int k=0; k<m; k++){
					t[j+k] += 1ll * v[j] * w[k] % mod;
					if(t[j+k] >= mod) t[j+k] -= mod;
				}
			}
			for(int j=2*m-1; j>=m; j--){
				for(int k=1; k<=m; k++){
					t[j-k] += 1ll * t[j] * rec[k-1] % mod;
					if(t[j-k] >= mod) t[j-k] -= mod;
				}
			}
			t.resize(m);
			return t;
		};
		while(n){
			if(n & 1) s = mul(s, t);
			t = mul(t, t);
			n >>= 1;
		}
		lint ret = 0;
		for(int i=0; i<m; i++) ret += 1ll * s[i] * dp[i] % mod;
		return ret % mod;
	}
	int guess_nth_term(vector<int> x, lint n){
		if(n < x.size()) return x[n];
		vector<int> v = berlekamp_massey(x);
		if(v.empty()) return 0;
		return get_nth(v, x, n);
	}
	struct elem{int x, y, v;}; // A_(x, y) <- v, 0-based. no duplicate please..
	vector<int> get_min_poly(int n, vector<elem> M){ 
		// A^i = sum_{j < i} {A^j \times ans_j} 
		int* rnd1 = (int*) calloc(n, sizeof(int));
		int* rnd2 = (int*) calloc(n, sizeof(int));
		int* nxt = (int*) calloc(n, sizeof(int));
		mt19937 rng(0x14004);
		auto randint = [&rng](int lb, int ub){
			return uniform_int_distribution<int>(lb, ub)(rng);
		};
		for(int i=0; i<n; i++){
			rnd1[i] = randint(1, mod - 1);
			rnd2[i] = randint(1, mod - 1);
		}
		vector<int> gobs;
		for(int i=0; i<2*n+2; i++){
			int tmp = 0;
			for(int j=0; j<n; j++){
				tmp = Mod(tmp + 1ll * rnd1[j] * rnd2[j]);
				if(tmp >= mod) tmp -= mod;
			}
			gobs.push_back(tmp);
			memset(nxt, 0, sizeof(int) * n);
			for(auto &i : M){
				nxt[i.x] = Mod(nxt[i.x] + 1ll * i.v * rnd1[i.y]);
			}
			memcpy(rnd1, nxt, sizeof(int) * n);
		}
		auto sol = berlekamp_massey(gobs);
		reverse(sol.begin(), sol.end());
		return sol;
	}
	lint det(int n, vector<elem> M){ 
		vector<int> rnd;
		mt19937 rng(0x14004);
		auto randint = [&rng](int lb, int ub){
			return uniform_int_distribution<int>(lb, ub)(rng);
		};
		for(int i=0; i<n; i++) rnd.push_back(randint(1, mod - 1));
		for(auto &i : M){
			i.v = 1ll * i.v * rnd[i.y] % mod;
		}
		auto sol = get_min_poly(n, M)[0];
		if(n % 2 == 0) sol = mod - sol;
		for(auto &i : rnd) sol = 1ll * sol * ipow(i, mod - 2) % mod;
		return sol;
	}
}

int main(){
	vector<BBLA::elem> tab;
	int n, k, deg[MAXN] = {};
	scanf("%d %d",&n,&k);
	if(n == 1){
		puts("1");
		return 0;
	}
	auto add_edge = [&](int s, int e){
		if(s < n - 1) deg[s]++;
		if(e < n - 1) deg[e]++;
		if(s == n - 1 || e == n - 1) return;
		tab.push_back({s, e, mod-1});
		tab.push_back({e, s, mod-1});
	};
	for(int i=0; i<k; i++){
		for(int j=0; j<i; j++) add_edge(i, j);
	}
	for(int i=k; i<n; i++){
		for(int j=0; j<k; j++){
			int x = rand() % i + 1;
			scanf("%d",&x);
			add_edge(i, x - 1);
		}
	}
	for(int i=0; i<n-1; i++) tab.push_back({i, i, deg[i]});
	cout << BBLA::det(n - 1, tab) << endl;
}