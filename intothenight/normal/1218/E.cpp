#include <iostream>
#include <vector>
#include <chrono>
#include <random>
#include <map>
#include <algorithm>
#include <queue>

std::mt19937 rng((int) std::chrono::steady_clock::now().time_since_epoch().count());

#define int long long
typedef long long ll;

const int MOD = 998244353;
const int me = 22;
const int ms = 1 << me;
ll fexp(ll x, ll e, ll mod = MOD) {
	ll ans = 1;
	x %= mod;
	for(; e > 0; e /= 2) {
		if(e & 1) {
			ans = ans * x % mod;
		}
		x = x * x % mod;
	}
	return ans;
}
//is n primitive root of p ?
bool test(ll x, ll p) {
	ll m = p - 1;
	for(int i = 2; i * i <= m; ++i) if(!(m % i)) {
		if(fexp(x, i, p) == 1) return false;
		if(fexp(x, m / i, p) == 1) return false;
	}
	return true;
}
//find the largest primitive root for p
int search(int p) {
	for(int i = p - 1; i >= 2; --i) if(test(i, p)) return i;
	return -1;
}
std::map<int, int> roots;
int get_root(int p) {
	if(roots[p]) {
		return roots[p];
	} else {
		roots[p]=search(p);
		return roots[p];
	}
}

#define add(x, y) x+y>=MOD?x+y-MOD:x+y

const int gen = search(MOD);
int bits[ms], root[ms];

void initFFT() {
	root[1] = 1;
	for(int len = 2; len < ms; len += len) {
		int z = fexp(gen, (MOD - 1) / len / 2);
		for(int i = len / 2; i < len; i++) {
			root[2 * i] = root[i];
			root[2 * i + 1] = (long long) root[i] * z % MOD;
		}
	}
}
 
void pre(int n) {
	int LOG = 0;
	while(1 << (LOG + 1) < n) {
		LOG++;
	}
	for(int i = 1; i < n; i++) {
		bits[i] = (bits[i >> 1] >> 1) | ((i & 1) << LOG);
	}
}

std::vector<int> fft(std::vector<int> a, bool inv = false) {
	int n = (int) a.size();
	pre(n);
	if(inv) {
		std::reverse(a.begin() + 1, a.end());
	}
	for(int i = 0; i < n; i++) {
		int to = bits[i];
		if(i < to) { std::swap(a[i], a[to]); }
	}
	for(int len = 1; len < n; len *= 2) {
		for(int i = 0; i < n; i += len * 2) {
			for(int j = 0; j < len; j++) {
				int u = a[i + j], v = (ll) a[i + j + len] * root[len + j] % MOD;
				a[i + j] = (u + v) % MOD;
				a[i + j + len] = (u - v) % MOD;
			}
		}
	}
	if(inv) {
		int rev = fexp(n, MOD-2);
		for(int i = 0; i < n; i++)
			a[i] = (ll) a[i] * rev % MOD;
	}
	return a;
}

std::vector<int> mul(std::vector<int> a, std::vector<int> b) {
	int n = 1;
	while(n < a.size() + b.size()) n += n;
	a.resize(n, 0);
	b.resize(n, 0);
	a = fft(a);
	b = fft(b);
	for(int i = 0; i < n; i++) {
		a[i] = (ll) a[i] * b[i] % MOD;
	}
	a = fft(a, true);
	while(!a.empty() && a.back() == 0) {
		a.pop_back();
	}
	return a;
}
 
struct Comp {
	bool operator ()(const std::vector<int> &a, const std::vector<int> &b) { return a.size() > b.size(); }
};

std::vector<int> solve(const std::vector<int> &coef) {
	std::priority_queue<std::vector<int>, std::vector<std::vector<int>>, Comp> hp;
	for(int i = 0; i < (int) coef.size(); i++) {
		std::vector<int> cur(2);
		cur[0] = 1;
		cur[1] = (coef[i] % MOD + MOD) % MOD;
		hp.push(cur);
	}
	while(hp.size() > 1) {
		auto a = hp.top();
		hp.pop();
		a = mul(a, hp.top());
		hp.pop();
		hp.push(a);
	}
	auto ans = hp.top();
	ans.resize(100100, 0);
	return ans;
}

int32_t main() {
	std::ios_base::sync_with_stdio(false); std::cin.tie(NULL);
	initFFT();
	int n, k;
	std::cin >> n >> k;
	std::vector<int> a(n);
	for(int i = 0; i < n; i++) {
		std::cin >> a[i];
		a[i] %= MOD;
	}
	int q;
	std::cin >> q;
	//std::cout << "got here!" << std::endl;
	while(q--) {
		int t;
		std::cin >> t;
		std::vector<int> b(n);
		if(t == 1) {
			int q, pos, d;
			std::cin >> q >> pos >> d;
			pos--;
			for(int i = 0; i < n; i++) {
				int x = a[i];
				if(i == pos) {
					x = d;
				}
				b[i] = (q - x + MOD) % MOD;
			}
		} else {
			int q, l, r, d;
			std::cin >> q >> l >> r >> d;
			l--;
			for(int i = 0; i < n; i++) {
				int x = a[i];
				if(l <= i && i < r) {
					x = (x + d) % MOD;
				}
				b[i] = (q - x + MOD) % MOD;
			}
		}
		std::cout << (solve(b)[k] % MOD + MOD) % MOD << '\n';
	}
}