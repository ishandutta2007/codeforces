#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
#include <bits/stdc++.h>
// #include <ext/pb_ds/assoc_container.hpp> //required
// #include <ext/pb_ds/tree_policy.hpp> //required

#define dbg(x) cerr<<#x": "<<x<<"\n"
#define dbg_v(x, n) do{cerr<<#x"[]: ";for(int _=0;_<n;++_)cerr<<x[_]<<" ";cerr<<'\n';}while(0)
#define dbg_ok cerr<<"OK!\n"

#define st first
#define nd second

// using namespace __gnu_pbds; 
using namespace std;

// template <typename T> using ordered_set =  tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>; // ordered_set <int> s;
template<class T> ostream& prnt(ostream& out, T v) { out << v.size() << '\n'; for(auto e : v) out << e << ' '; return out;}
template<class T> ostream& operator<<(ostream& out, vector <T> v) { return prnt(out, v); }
template<class T> ostream& operator<<(ostream& out, set <T> v) { return prnt(out, v); }
template<class T1, class T2> ostream& operator<<(ostream& out, map <T1, T2> v) { return prnt(out, v); }
template<class T1, class T2> ostream& operator<<(ostream& out, pair<T1, T2> p) { return out << '(' << p.st << ' ' << p.nd << ')'; }

using namespace std;

const int N = 400100;
const int MOD = 1e9 + 7;
int n, x, ans, k, m, q, dbgg = 0;
template<class T> 
class SegTree {
private:
	int n;
	T st[4 * N], lazy[4 * N];

public:
	T en = 0;
	SegTree() {
		memset(st, 0, sizeof st);
		memset(lazy, 0, sizeof lazy);
	}
	SegTree(int n) {
		memset(st, 0, sizeof st);
		memset(lazy, 0, sizeof lazy);
	}

	void push(int nod, int l, int r) {
		// complete this
		if(lazy[nod]) {
			st[nod] |= lazy[nod];
			if(l < r) {
				st[2 * nod] 			|= lazy[nod];
				st[2 * nod + 1] 	|= lazy[nod];
				lazy[2 * nod] 		|= lazy[nod];
				lazy[2 * nod + 1] |= lazy[nod];
			}
			lazy[nod] = 0;
		}
	}

	void upd(int nod, int l, int r, int x, int y, T val) {
		push(nod, l, r);
		if(l == r) {
			st[nod] |= val;
			return ;
		}

		int mid = (l + r) / 2;
		if(x <= l && r <= y)
			lazy[nod] = val;
		else{
			if(x <= mid) upd(2 * nod, l, mid, x, y, val);
			if(y > mid) upd(2 * nod + 1, mid + 1, r, x, y, val);
		}
		// push(nod, l, r);
		st[nod] = (st[2 * nod] | st[2 * nod + 1] | lazy[nod]);
	}

	T que(int nod, int l, int r, int x, int y) {
		push(nod, l, r);

		if(x <= l && r <= y)
			return st[nod];

		int mid = (l + r) / 2;
		T ans = 0;//

		if(x <= mid) ans |= que(2 * nod, l, mid, x, y);
		if(y > mid) ans |= que(2 * nod + 1, mid + 1, r, x, y);
		return ans;
	}
};

inline long long powMod(long long b, int e) {
	long long a = 1;
	for (; e; e >>= 1, b = b * b % MOD)
		if (e & 1) a = a * b % MOD;
	return a;
}

template<class T> 
class SegTree2 {
private:
	int n;

public:
	T *st, *lazy;
	T en = 1;
	SegTree2(int n) {
		st = new int[4 * n + 65];
		lazy = new int[4 * n + 65];
		for(int i = 0; i <= 4 * n + 10; i++)
			st[i] = lazy[i] = 1;
		// st.resize(4 * n + 63, 1);
		// lazy.resize(4 * n + 63, 1);
		// lval.resize(4 * n + 63, 1);
	}

	void push(int nod, int l, int r) {
		if(lazy[nod] != 1) {
			// st[nod] = (1LL* st[nod] * powMod(lazy[nod], r - l + 1)) % MOD;
			if(l < r) {
				int mid = (l + r) / 2;
				// aici e de schimbat
				lazy[2 * nod] 		= (1LL * lazy[2 * nod] 		* lazy[nod]) % MOD;
				lazy[2 * nod + 1] = (1LL * lazy[2 * nod + 1] * lazy[nod]) % MOD;
				st[2 * nod] 		= (1LL * st[2 * nod] * powMod(lazy[nod], mid - l + 1)) % MOD;
				st[2 * nod + 1] = (1LL * st[2 * nod + 1] * powMod(lazy[nod], r - mid)) % MOD;
			}
			lazy[nod] = 1;
		}
	}

	void upd(int nod, int l, int r, int x, int y, T val) {
		push(nod, l, r);
		if(l == r) {
			st[nod] = (1LL * st[nod] * val) % MOD;
			return ;
		}

		int mid = (l + r) / 2;
		if(x <= l && r <= y) {
			lazy[nod] = val % MOD;
		}
		else{
			if(x <= mid) upd(2 * nod, l, mid, x, y, val);
			if(y > mid) upd(2 * nod + 1, mid + 1, r, x, y, val);
		}
		// push(nod, l, r);
		st[nod] = (1LL * st[2 * nod] * st[2 * nod + 1]) % MOD;
		if(lazy[nod] != 1)
			st[nod] = (1LL * st[nod] * powMod(lazy[nod], r - l + 1)) % MOD;
	}

	T que(int nod, int l, int r, int x, int y) {
		push(nod, l, r);

		if(x <= l && r <= y)
			return st[nod];

		int mid = (l + r) / 2;
		T ans = 1;//

		if(x <= mid) ans = (1LL * ans * que(2 * nod, l, mid, x, y)) % MOD;
		if(y > mid) ans = (1LL * ans * que(2 * nod + 1, mid + 1, r, x, y)) % MOD;
		return ans;
	}
};

// vector <SegTree<bool>> st;
SegTree<long long> st;
vector<int> primes({2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53, 59, 61, 67, 71, 73, 79, 83, 89, 97, 101, 103, 107, 109, 113, 127, 131, 137, 139, 149, 151, 157, 163 ,167, 173, 179, 181, 191, 193, 197, 199, 211, 223, 227, 229, 233, 239, 241, 251, 257, 263, 269, 271, 277, 281, 283, 293});
int which[303], a, l, r, inv[333];
string s;

int main() {
	ios_base::sync_with_stdio(false);

	for(int i = 0; i < primes.size(); i++)
		which[primes[i]] = i;

	cin >> n >> q;
	SegTree2<int> st2(n);

	for(int i = 1; i <= n; i++) {
		cin >> a;
		st2.upd(1, 1, n, i, i, a);
		long long msk = 0;
		for(auto p : primes) {
			int cnt = 0;
			while(a % p == 0)
				a /= p, cnt++;
			if(cnt)
				msk |= (1LL << which[p]);
		}
		st.upd(1, 1, n, i, i, msk);
	}

	for(auto p : primes)
		inv[p] = powMod(p, MOD - 2);

	for(int i = 1; i <= q; i++) {
		
		cin >> s >> l >> r;
		
		if(s[0] == 'M') {
		
			cin >> x;
			st2.upd(1, 1, n, l, r, x);
			long long msk = 0;

			for(auto p : primes)
				if(x % p == 0)
					msk |= (1LL << which[p]);

			st.upd(1, 1, n, l, r, msk);

		} else {
			int ans = st2.que(1, 1, n, l, r);

			long long who = st.que(1, 1, n, l, r);

			for(auto p : primes)
				if(who & (1LL << which[p])) 
					ans = (1LL * ((1LL * ans * (p - 1)) % MOD) * inv[p]) % MOD;
			
			cout << ans << '\n';
		}
	}
}