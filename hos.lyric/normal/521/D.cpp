#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <cassert>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <queue>
#include <deque>
#include <set>
#include <map>
#include <utility>
#include <numeric>
#include <algorithm>
#include <bitset>
#include <complex>
#include <cstdint>
#include <unordered_set>
#include <unordered_map>

using namespace std;

typedef long long Int;
typedef vector<int> vint;
typedef pair<int, int> pint;
#define mp make_pair

template <typename T1, typename T2> ostream &operator<<(ostream &os, const pair<T1, T2> &a) { return os << "(" << a.first << ", " << a.second << ")"; };
template <typename T> void pv(T a, T b) { for (T i = a; i != b; ++i) cout << *i << " "; cout << endl; }
template <typename T> void chmin(T &t, const T &f) { if (t > f) t = f; }
template <typename T> void chmax(T &t, const T &f) { if (t < f) t = f; }
int in() { int x; scanf("%d", &x); return x; }

struct Rat {
	Int p, q;
	Rat() {}
	Rat(Int p, Int q = 1) : p(p), q(q) { reduce(); }
	void reduce() { Int g = __gcd(p, q); p /= g; q /= g; if (q < 0 || (q == 0 && p < 0)) { p = -p; q = -q; } }
	Rat operator+(const Rat &a) const { return Rat(p * a.q + q * a.p, q * a.q); }
	Rat operator-(const Rat &a) const { return Rat(p * a.q - q * a.p, q * a.q); }
	Rat operator*(const Rat &a) const { return Rat(p * a.p, q * a.q); }
	Rat operator/(const Rat &a) const { return Rat(p * a.q, q * a.p); }
	Rat &operator+=(const Rat &a) { return *this = *this + a; }
	Rat &operator-=(const Rat &a) { return *this = *this - a; }
	Rat &operator*=(const Rat &a) { return *this = *this * a; }
	Rat &operator/=(const Rat &a) { return *this = *this / a; }
	Rat operator+() const { return *this; }
	Rat operator-() const { return Rat(-p, q); }
	bool operator< (const Rat &a) const { return (p * a.q <  q * a.p); }
	bool operator<=(const Rat &a) const { return (p * a.q <= q * a.p); }
	bool operator> (const Rat &a) const { return (p * a.q >  q * a.p); }
	bool operator>=(const Rat &a) const { return (p * a.q >= q * a.p); }
	bool operator==(const Rat &a) const { return  (p == a.p && q == a.q); }
	bool operator!=(const Rat &a) const { return !(p == a.p && q == a.q); }
	explicit operator double() const { return (double)p / (double)q; }
	explicit operator long double() const { return (long double)p / (long double)q; }
	friend ostream &operator<<(ostream &os, const Rat &a) { os << a.p << "/" << a.q; return os; }
};

int K, N, M;
Int A[100010];
int T[100010], I[100010];
Int B[100010];

Int as[100010];
pair<Int, int> b1[100010];
vector<pair<Int, int>> b2[100010];
vector<pair<Int, int>> b3;

multiset<pair<Rat, int>> q;

void addThem(int k) {
	/*
	if (b1[k].second != -1) {
		q.emplace(Rat(b1[k].first, as[k]), b1[k].second);
	}
	*/
	if (b2[k].back().second != -1) {
		q.emplace(Rat(as[k] + b2[k].back().first, as[k]), b2[k].back().second);
	}
}
void removeThem(int k) {
	/*
	{
		auto it = q.find(mp(Rat(b1[k].first, as[k]), b1[k].second));
		if (it != q.end()) {
			q.erase(it);
		}
	}
	*/
	{
		auto it = q.find(mp(Rat(as[k] + b2[k].back().first, as[k]), b2[k].back().second));
		if (it != q.end()) {
			q.erase(it);
		}
	}
}

int ansLen;
int ans[100010];
int ans1Len;
int ans1[100010];

int main() {
	
	
	for (; ~scanf("%d%d%d", &K, &N, &M); ) {
		for (int k = 0; k < K; ++k) {
			A[k] = in();
		}
		for (int n = 0; n < N; ++n) {
			T[n] = in();
			I[n] = in() - 1;
			B[n] = in();
		}
		for (int k = 0; k < K; ++k) {
			as[k] = A[k];
			b1[k] = mp(0, -1);
			b2[k] = { mp(0, -1) };
		}
		b3.clear();
		for (int n = 0; n < N; ++n) {
			const int k = I[n];
			switch (T[n]) {
				case 1: {
					chmax(b1[k], mp(B[n], n));
				} break;
				case 2: {
					b2[k].emplace_back(B[n], n);
				} break;
				case 3: {
					b3.emplace_back(B[n], n);
				} break;
				default: assert(false);
			}
		}
		for (; (int)b3.size() < N + 1; ) {
			b3.emplace_back(1, -1);
		}
		for (int k = 0; k < K; ++k) {
			if (b1[k].first > A[k]) {
				b2[k].emplace_back(b1[k].first - A[k], b1[k].second);
			}
			sort(b2[k].begin(), b2[k].end());
		}
		sort(b3.begin(), b3.end());
/*
for(int k=0;k<K;++k){
 cout<<"b1["<<k<<"] = "<<b1[k]<<endl;
 cout<<"b2["<<k<<"] : ";pv(b2[k].begin(),b2[k].end());
}
cout<<"b3 : ";pv(b3.begin(),b3.end());
*/
		q = { mp(1, -1) };
		for (int k = 0; k < K; ++k) {
			addThem(k);
		}
		ansLen = 0;
		for (int m = 0; m < M; ++m) {
// cout<<"q : ";pv(q.begin(),q.end());
			auto best = --q.end();
// cout<<"  "<<*best<<" vs "<<b3[(int)b3.size() - (M - m)]<<endl;
			if (best->first > b3[(int)b3.size() - (M - m)].first) {
				const int n = best->second;
				assert(n != -1);
				q.erase(best);
				ans[ansLen++] = n;
				const int k = I[n];
				removeThem(k);
				/*
				switch (T[n]) {
					case 1: {
						assert(b1[k].second == n);
						b1[k] = mp(0, -1);
						as[k] = B[k];
					} break;
					case 2: {
						assert(b2[k].back().second == n);
						b2[k].pop_back();
						as[k] += B[k];
					} break;
					default: assert(false);
				}
				*/
				
				assert(b2[k].back().second == n);
				as[k] += b2[k].back().first;
				b2[k].pop_back();
				
				addThem(k);
			} else {
				for (; m < M; ++m) {
					const int n = b3.back().second;
					if (n == -1) {
						break;
					}
					b3.pop_back();
					ans[ansLen++] = n;
				}
				break;
			}
		}
		
		ans1Len = 0;
		for (int i = 0; i < ansLen; ++i) {
			if (T[ans[i]] == 1) {
				ans1[ans1Len++] = ans[i];
			}
		}
		for (int i = 0; i < ansLen; ++i) {
			if (T[ans[i]] != 1) {
				ans1[ans1Len++] = ans[i];
			}
		}
		
		printf("%d\n", ans1Len);
		for (int i = 0; i < ans1Len; ++i) {
			if (i > 0) printf(" ");
			printf("%d", ans1[i] + 1);
		}
		puts("");
	}
	
	return 0;
}