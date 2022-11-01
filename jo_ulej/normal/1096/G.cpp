#include <iostream>
#include <iomanip>
#include <random>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <cmath>
#include <numeric>
#include <cstdlib>
#include <cstring>
#include <deque>
#include <sstream>
#include <bitset>
#include <cassert>
#include <fstream>
#include <queue>

#define len(X) ((int)(X).size())

#ifdef __LOCAL
	#define DBG(X) cout << #X << "=" << (X) << '\n';
	#define SAY(X) cout << (X) << '\n';
#else
	#define DBG(X)
	#define SAY(X)
#endif
 
using namespace std;

using ll = long long int;
using ull = unsigned long long int;
using ld  = long double;
using pii = pair<int, int>;
using pll = pair<ll, ll>;

const int INT_INF = (int)(2e9);
const ll  LL_INF  = (ll)(2e18);

const int NIL = -1;
static mt19937 _g(time(nullptr));

inline ll randint(ll a, ll b) { ll w = (_g() << 31LL) ^ _g(); return a + w % (b - a + 1); }
inline void fast_io() { ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr); };
template<typename T> inline T sign(T x) { return T(x > 0) - T(x < 0); }
template<typename T, typename S> inline ostream& operator<<(ostream& os, const pair<T, S> p) { cout << "[" << p.first << ";" << p.second << "]"; return os; }
template<typename T> inline ostream& operator<<(ostream& os, const vector<T>& v) { for(auto el: v) cout << el << " "; return os; }
template<typename T> inline T fetch() { T ret; cin >> ret; return ret; }
template<typename T> inline vector<T> fetch_vec(int sz) { vector<T> ret(sz); for(auto& elem: ret) cin >> elem; return ret; }

struct FFT {
	private:
		int mod, K, C, root, rootC;
		vector<int> mem, invmem, inv_pw2;

		inline int add(int x, int y) {
			return (x + y >= mod ? x + y - mod : x + y);
		}

		inline int sub(int x, int y) {
			return (x - y < 0 ? x - y + mod : x - y);
		}

		inline int mult(int x, int y) {
			return (x * 1LL * y) % mod;
		}

		inline int binpow(int x, int y) {
			if(x == 1 || y == 0) return 1;
			if(x == 0) return 0;

			int rez = binpow(x, y >> 1);
			rez = mult(rez, rez);

			if(y & 1) rez = mult(rez, x);

			return rez;
		}

		inline int divide(int x, int y) {
			return mult(x, binpow(y, mod - 2));
		}

		vector<int> factor(int num) {
			vector<int> rez;

			for(int i = 2; i * i <= num; ++i) {
				if(num % i == 0) {
					rez.push_back(i);

					while(num % i == 0) {
						num /= i;
					}
				}
			}

			if(num > 1) {
				rez.push_back(num);
			}

			return rez;
		}

		inline int get_w(int k) {
			if(mem[k] == NIL) {
				mem[k] = binpow(rootC, 1 << (K - k));
			}

			return mem[k];
		}

		inline int get_inv_w(int k) {
			if(invmem[k] == NIL) {
				invmem[k] = divide(1, get_w(k));
			}

			return invmem[k];
		}
	public:

		FFT(int _mod): mod(_mod), K(0), C(0) {
			int cur = mod - 1;
			int phi = mod - 1;
			vector<int> to_check = factor(phi);

			while((cur & 1) == 0) {
				++K;
				cur >>= 1;
			}

			C = cur;
			root = 2;

			while(true) {
				bool good = true;

				for(auto& elem: to_check) {
					if(binpow(root, phi / elem) == 1) {
						good = false;
						break;
					}
				}

				if(good) {
					break;
				} else {
					++root;
				}
			}

			rootC = binpow(root, C);
			mem.resize(K + 1, NIL);
			invmem.resize(K + 1, NIL);
			inv_pw2.resize(K + 1, NIL);

			for(int i = 0; i <= K; ++i) {
				inv_pw2[i] = divide(1, binpow(2, i));
			}

			DBG(K); DBG(C); DBG(root);
		}

		void transform(vector<int>& p, int level) {
			if(level == 0) return;
	
			int sz = 1 << level;
			vector<int> even(sz >> 1, 0), odd(sz >> 1, 0);

			for(int i = 0; i < sz; ++i) {
				if(i & 1) {
					odd[i >> 1] = p[i];
				} else {
					even[i >> 1] = p[i];
				}
			}

			transform(even, level - 1);
			transform(odd,  level - 1);
			int cur = 1;
			int w = get_w(level);

			for(int i = 0; i < (sz >> 1); ++i) {
				p[i] = add(even[i], mult(cur, odd[i]));
				p[i + (sz >> 1)] = sub(even[i], mult(cur, odd[i]));

				cur = mult(cur, w);
			}
		}

		void inverse_transform(vector<int>& p, int level) {
			if(level == 0) return;

			int sz = 1 << level;
			vector<int> even(sz >> 1, 0), odd(sz >> 1, 0);

			for(int i = 0; i < sz; ++i) {
				if(i & 1) {
					odd[i >> 1] = p[i];
				} else {
					even[i >> 1] = p[i];
				}
			}

			inverse_transform(even, level - 1);
			inverse_transform(odd,  level - 1);
			int cur = 1;
			int w = get_inv_w(level);

			for(int i = 0; i < (sz >> 1); ++i) {
				p[i] = add(even[i], mult(cur, odd[i]));
				p[i + (sz >> 1)] = sub(even[i], mult(cur, odd[i]));

				cur = mult(cur, w);
			}
		}

		void product(vector<int>& p, vector<int>& q) {
			int level = 0;

			while((1 << level) < len(p) + len(q)) {
				++level;
			}

			int sz = 1 << level;
			p.resize(sz);
			q.resize(sz);

			transform(p, level);
			transform(q, level);

			for(int i = 0; i < sz; ++i) {
				p[i] = mult(p[i], q[i]);
			}

			inverse_transform(p, level);

			for(auto& val: p) {
				val = mult(val, inv_pw2[level]);
			}

			int head = sz;

			while(head > 0 && p[head - 1] == 0) {
				--head;
			}

			p.resize(head);
		}
};

inline vector<int> binpow(FFT& fft, vector<int>& x, int y) {
	if(y == 1) {
		return x;
	} else {
		auto rez = binpow(fft, x, y >> 1);
		auto cpy = rez;
		fft.product(rez, cpy);

		if(y & 1) {
			cpy = x;
			fft.product(rez, cpy);
		}

		return rez;
	}
}

void solve() {
	int n = fetch<int>();
	int k = fetch<int>();
	vector<int> p(10, 0);

	for(int i = 0; i < k; ++i) {
		int d = fetch<int>();
		p[d] = 1;
	}

	const int MOD = 998244353;
	FFT fft(MOD);
	p = binpow(fft, p, n >> 1);
	int answ = 0;

	for(int i = 0; i < len(p); ++i) {
		answ += (p[i] * 1LL * p[i]) % MOD;

		if(answ >= MOD) {
			answ -= MOD;
		}
	}

	cout << answ << '\n';
}

int main() {
	fast_io();
	solve();

	return 0;
}