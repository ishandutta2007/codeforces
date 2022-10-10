#include <iostream>
#include <vector>
#include <chrono>
#include <random>
#include <cassert>

std::mt19937 rng((int) std::chrono::steady_clock::now().time_since_epoch().count());

const int MOD = 1e9 + 7;
const int ms = 101;

template <class T>
T fexp(T x, long long e) {
	T ans(1);
	for(; e > 0; e /= 2) {
		if(e & 1) ans = ans * x;
		x = x * x;
	}
	return ans;
}

template <int mod = MOD>
struct modBase {
	modBase(int v = 0) : val(v < 0 ? v + mod : v) {}
	int val;
 
	void operator += (modBase<mod> o) { *this = *this + o; }
	void operator -= (modBase<mod> o) { *this = *this - o; }
	void operator *= (modBase<mod> o) { *this = *this * o; }
	//void operator /= (modBase<mod> o) { *this = *this / o; }
	modBase<mod> operator * (modBase<mod> o) { return (int)((long long) val * o.val % mod); }
	modBase<mod> operator / (modBase<mod> o) { return *this * fexp(o, mod - 2); }
	modBase<mod> operator + (modBase<mod> o) { return val + o.val >= mod ? val + o.val - mod : val + o.val; }
	modBase<mod> operator - (modBase<mod> o) { return val - o.val < 0 ? val - o.val + mod : val - o.val; }

	friend std::ostream& operator << (std::ostream &os, const modBase<mod> &p) {
		return os << p.val;
	}
	friend std::istream& operator >> (std::istream &is, modBase<mod> &p) {
		return is >> p.val;
	}
};

long long fat[ms], ifat[ms];

class LagrangePoly {
public:
	LagrangePoly(const std::vector<long long> &_a) {
		//f(i) = _a[i]
		//interpola o vetor em um polinomio de grau y.size() - 1
		y = _a;
		den.resize(y.size());
		int n = (int) y.size();
		for(int i = 0; i < n; i++) {
			y[i] = (y[i] % MOD + MOD) % MOD;
			den[i] = ifat[n - i - 1] * ifat[i] % MOD;
			if((n - i - 1) % 2 == 1) {
				den[i] = (MOD - den[i]) % MOD;
			}
		}
	}
	
	long long getVal(long long x) {
		int n = (int) y.size();
		x %= MOD;
		if(x < n) {
			//return y[(int) x];
		}
		std::vector<long long> l, r;
		l.resize(n);
		l[0] = 1;
		for(int i = 1; i < n; i++) {
			l[i] = l[i - 1] * (x - (i - 1) + MOD) % MOD;
		}
		r.resize(n);
		r[n - 1] = 1;
		for(int i = n - 2; i >= 0; i--) {
			r[i] = r[i + 1] * (x - (i + 1) + MOD) % MOD;
		}
		long long ans = 0;
		for(int i = 0; i < n; i++) {
			long long coef = l[i] * r[i] % MOD;
			ans = (ans + coef * y[i] % MOD * den[i]) % MOD;
		}
		return ans;
	}
	
private:
	std::vector<long long> y, den;
};


int main() {
	std::ios_base::sync_with_stdio(false); std::cin.tie(NULL);
	fat[0] = ifat[0] = 1;
	for(int i = 1; i < ms; i++) {
		fat[i] = fat[i - 1] * i % MOD;
		ifat[i] = fexp(modBase<>((int) fat[i]), MOD - 2).val;
	}
	int n, q;
	std::cin >> n >> q;
	std::vector<int> a(n);
	for(int i = 0; i < n; i++) {
		std::cin >> a[i];
	}
	struct Query {
		int l, r, d;
		bool valid;
	};
	std::vector<Query> qries(q);
	for(int i = 0; i < q; i++) {
		std::cin >> qries[i].l >> qries[i].r >> qries[i].d;
		qries[i].l--;
		qries[i].valid = true;
	}
	std::vector<modBase<>> sum1(n+1, 0), hashSum(n+1, 0);
	for(int i = 1; i <= n; i++) {
		sum1[i] = sum1[i-1] + a[i-1];
	}
	const int MAGIC = 20;
	for(int rep = 0; rep < 3; rep++) {
		std::vector<modBase<>> poly(MAGIC, 0);
		std::uniform_int_distribution<int> dist(0, MOD - 1);
		for(int i = 0; i < MAGIC; i++) {
			poly[i] = dist(rng);
		}
		auto getVal = [&](int x) {
			modBase<> val(0);
			for(int i = 0; i < MAGIC; i++) {
				val = (val + poly[i]) * x;
			}
			return val;
		};
		for(int i = 1; i <= n; i++) {
			hashSum[i] = hashSum[i-1] + getVal(a[i-1]);
		}
		for(auto &qry : qries) if(qry.valid) {
			int l = qry.l, r = qry.r, d = qry.d;
			int sz = r - l;
			auto first = ((sum1[r] - sum1[l]) - modBase<>(sz) * (sz - 1) / 2 * d) / sz;
			std::vector<long long> cur(MAGIC+2, 0);
			modBase<> wtf(0);
			for(int i = 1; i < MAGIC+2; i++) {
				wtf += getVal((int)(((long long) d * (i-1) + first.val) % MOD));
				cur[i] = wtf.val;
			}
			// for(int i = 1; i <= (r-l); i++) {
			// 	std::cout << (int)(((long long) d * (i-1) + first.val) % MOD) << (i == r-l ? '\n' : ' ');
			// }
			// std::cout << "should be:";
			// for(int i = l; i < r; i++) {
			// 	std::cout << getVal(a[i]) << (i + 1 == r ? '\n' : ' ');
			// }
			if(LagrangePoly(cur).getVal(r - l) != (hashSum[r] - hashSum[l]).val) {
				qry.valid = false;
			}
		}
	}
	for(int i = 0; i < q; i++) {
		std::cout << (qries[i].valid ? "Yes\n" : "No\n");
	}
}