// Problem: D. Rainbow Rectangles
// Contest: Codeforces - Codeforces Round #666 (Div. 1)
// URL: https://codeforces.com/contest/1396/problem/D
// Memory Limit: 512 MB
// Time Limit: 4000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

#pragma GCC optimize("Ofast,unroll-loops")
#pragma GCC target("avx,avx2,sse,sse2")
#include<bits/stdc++.h>
#define int long long
#define all(x) begin(x), end(x)
using namespace std;
using ll = long long;

template<typename F>
void multitest(F func) {
	int t;
	cin >> t;
	while(t--) func();
}
void report(int ok) {
	cout << (ok?"YES":"NO") << '\n';
}
const int mod = 1e9 + 7;
namespace math {
const int A = 1<<20;

#define INLINE inline __attribute__ (( always_inline ))
struct mint {
	uint32_t v;
	template<class T = int>
	mint(T x = 0) {
		x %= mod;
		if(x < 0) x += mod;
		v = x;
	}
	mint operator-() const {
		return mint(v ? mod-v : 0);
	}
	mint &operator*=(const mint &r) {
		v = v*1ll*r.v%mod;
		return *this;
	}
	mint &operator+=(const mint &r) {
		v = v+r.v>=mod ? (v+r.v-mod) : (v+r.v);
		return *this;
	}
	mint &operator-=(const mint &r) { 
		return *this += -r;
	}
	mint &operator/=(const mint &r) {
		return *this *= r.inv();
	}
	friend mint operator+(mint a, const mint &b) {
		return a += b;
	}
	friend mint operator-(mint a, const mint &b) {
		return a -= b;
	}
	friend mint operator*(mint a, const mint &b) {
		return a *= b;
	}
	friend mint operator/(mint a, const mint &b) {
		return a /= b;
	}
	
	template<class T = int>
	mint pow(T p) const {
		mint res = 1, cur = *this;
		while(p) {
			if(p&1) res = res*cur;
			cur = cur*cur, p>>=1;
		}
		return res;
	}
	mint inv() const {
		return mint(*this).pow(mod-2);
	}
	
	friend bool operator==(const mint &a, const mint &b) {
		return a.v == b.v;
	}
	friend bool operator!=(const mint &a, const mint &b) {
		return !(a == b);
	}
	
	friend istream& operator>>(istream &is, mint &m) {
		is >> m.v;
		m = mint(m.v);
		return is;
	}
	friend ostream& operator<<(ostream &os, const mint &m) {
		os << m.v; 
		return os;
	}
};

mint fact[A], inum[A], ifact[A];
void calc_inum() {
	inum[1] = 1;
	for(int i = 2; i < A; i++) inum[i] = -inum[mod%i]*(mod/i);
}
void calc_combi() {
	if(0 == inum[1]) calc_inum();
	fact[0] = ifact[0] = 1;
	for(int i = 1; i < A; i++) fact[i] = fact[i-1]*i;
	for(int i = 1; i < A; i++) ifact[i] = ifact[i-1]*inum[i];
}

mint nck(int n, int k) {
	if(0 == fact[0]) calc_combi();
	if(k > n || k < 0) return 0;
	return fact[n]*ifact[k]*ifact[n-k];
}
}
using math::mint;
struct Ranges {
	mint sm = 0;
	set<array<int, 3>> vals;
	Ranges(vector<array<int, 3>> A) {
		for(auto [val, l, r] : A) {
			vals.insert({val, l, r});
			sm += (val+1ll)*(r-l);
		}
	}
	void replace(int l, int m, int r) {//L in [l; m] R-1 in [l; r)
		int L = -2, R  = 0;
		// cout << "Cut " << l << " " << m << " " << r << endl;
		while(true) {
			auto it = vals.lower_bound({l, -1, -1});
			if(it == vals.end() || it->at(0) > m || it->at(1)>=r)
				break;
			if(it->at(2) <= r) {
				sm -= (it->at(0)+1ll)*(it->at(2)-it->at(1));
				if(L == -2) {
					L = it->at(1);
				}
				R = it->at(2);
				vals.erase(it); 
			} else {
				array<int, 3> nw = {it->at(0), r, it->at(2)};
				sm -= (it->at(0)+1ll)*(r-it->at(1));
				if(L == -2)
					L = it->at(1);
				R = r;
				vals.erase(it);
				vals.insert(nw);
			}
		}
		if(L == -2) {
			return;
		}
		vals.insert(array<int, 3>{l, L, R});
		sm += (l+1ll)*(R-L);
	}
	mint get() {
		// for(auto [val, l, r] : vals)
			// cout << l << " " << r << " " << val << " -- " << (val+1)*(r-l) << endl;
		// cout << sm << endl;
		return sm;
	}
};

signed main() {
	cin.tie(0)->sync_with_stdio(0);
	int n, k, l;
	cin >> n >> k >> l;
	vector<array<int, 3>> Balls(n);
	for(auto &[x, y, c] : Balls) {
		cin >> x >> y >> c;
	} 
	sort(all(Balls), [&](auto a, auto b) {
		return a[0] < b[0];
	});
	auto Border = [&](int i, int co) {
		if(i == -1)
			return Balls[0][co]+1;
		if(i+1 == n)
			return l-Balls[i][co];
		return Balls[i+1][co]-Balls[i][co];
	};
	mint ans = 0;
	for(int i = 0; i < n; i++) {
		if(i && !Border(i-1, 0))
			continue;
		vector<array<int, 3>> balls;
		for(int j = i; j < n; j++) {
			balls.push_back(Balls[j]);
		}
		sort(all(balls), [&](auto a, auto b) {
			return a[1] < b[1];
		});
		vector<multiset<int>> cpos(k+1);
		vector<array<int, 3>> A;
		{
			vector<int> rcnt(k+1);
			int have = 0;
			for(int i = 0, j = 0; i < balls.size(); i++){
				cpos[balls[i][2]].insert(balls[i][1]);
				have += rcnt[balls[i][2]] == 0;
				rcnt[balls[i][2]]++;
				while(rcnt[balls[j][2]]>1) {
					rcnt[balls[j][2]]--;
					j++;
				}
				if(have == k) {
					A.push_back(array<int, 3>{balls[j][1],
						balls[i][1], i+1==balls.size()?l:balls[i+1][1]});
				}
			}
		}
		sort(all(balls), [&](auto a, auto b) {
			return a[0] < b[0];
		});
		Ranges d(A);
		for(int j = balls.size(); j--;) {
			if(Border(i+j, 0)) {
				// cout << Balls[i][0] << " " << Balls[i+j][0] << " __ " << Border(i-1, 0)*Border(i+j, 0) << endl;
				ans += d.get()*Border(i-1, 0)*Border(i+j, 0);
				// cout << "N"<<ans<<endl;
			}
			auto it = cpos[balls[j][2]].find(balls[j][1]);
			if(next(it) == cpos[balls[j][2]].end() || *next(it) != *it) {
				int L = -1, R = l;
				if(it != cpos[balls[j][2]].begin())
					L = *prev(it);
				if(next(it) != cpos[balls[j][2]].end())
					R = *next(it);
				else
					R = l;
				d.replace(L, *it, R);
			}
			cpos[balls[j][2]].erase(it);
		}
	}
	cout << ans << '\n';
}