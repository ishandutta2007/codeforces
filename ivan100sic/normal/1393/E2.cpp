// Retired?
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long unsigned long ull;
typedef double long ld;

template<class T = int, class F = plus<T>>
struct sparse_table {
	vector<vector<T>> d;
	T e;
	F f;

	sparse_table(vector<T> a, T e = T(), F f = F()) : e(e), f(f) {
		d.push_back(a);
		int n = a.size();
		for (int h=1; h*2<=n; h<<=1) {
			int m = a.size() - h;
			vector<T> b(m);
			for (int i=0; i<m; i++)
				b[i] = f(a[i], a[i+h]);
			d.push_back(b);
			swap(a, b);
		}
	}

	T operator() (int l, int r) const {
		if (l >= r) return e;
		int i = 31 - __builtin_clz(r-l);
		return f(d[i][l], d[i][r-(1<<i)]);
	}
};

template<int m>
struct modint {
	unsigned x;

	modint() : x(0) {}
	modint(long long arg) : x((arg %= m) < 0 ? arg + m : arg) {}

	modint operator+ (const modint& b) const {
		auto t = *this; t.x = (t.x += b.x) >= m ? t.x-m : t.x; return t;
	}

	modint operator- (const modint& b) const {
		auto t = *this; t.x = (t.x += m-b.x) >= m ? t.x-m : t.x; return t;
	}

	modint operator* (const modint& b) const {
		auto t = *this; t.x = ll(t.x) * b.x % m; return t;
	}

	template<class T> modint operator^ (T n) const {
		modint t;
		if (n == 0) return t.x = 1, t;
		if (n == 1) return t.x = x, t;
		t = *this ^ (n >> 1); t *= t;
		return n & 1 ? *this * t : t;
	}

	modint& operator+= (const modint& b) { return *this = *this + b; }
	modint& operator-= (const modint& b) { return *this = *this - b; }
	modint& operator*= (const modint& b) { return *this = *this * b; }
	modint& operator++ () { if (++x == m) x = 0; return *this; }
	modint& operator-- () { if (x-- == 0) x = m-1; return *this; }
	modint operator++ (int) { modint tmp = *this; ++*this; return tmp; }
	modint operator-- (int) { modint tmp = *this; --*this; return tmp; }
	bool operator== (const modint& other) const { return x == other.x; }
	bool operator!= (const modint& other) const {	return x != other.x; }
	int operator() () const { return x; }
	template<class T> modint operator^= (T n) { return *this = *this ^ n; }
	modint inv() const { return *this ^ (m-2); }
};

const int mod = 1'000'000'007;
typedef modint<mod> mint;

// begin suffix array
/* http://algo2.iti.kit.edu/documents/jacm05-revised.pdf */
/* Maybe I should rewrite this but it works, so who cares */
#define GetI() (SA12[t] < n0 ? SA12[t] * 3 + 1 : (SA12[t] - n0) * 3 + 2)
inline bool leq(int a1, int a2, int b1, int b2) {
	return a1 < b1 || (a1 == b1 && a2 <= b2);
}
inline bool leq(int a1, int a2, int a3, int b1, int b2, int b3) {
	return a1 < b1 || (a1 == b1 && leq(a2, a3, b2, b3));
}
// stably sort a[0..n-1] to b[0..n-1] with keys in 0..K from r
inline void radixPass(int* a, int* b, int* r, int n, int K) {
	int* c = new int[K + 1];
	for (int i = 0; i <= K; i++)
		c[i] = 0;
	for (int i = 0; i < n; i++) c[r[a[i]]]++;
	for (int i = 0, sum = 0; i <= K; i++) {
		int t = c[i]; c[i] = sum; sum += t;
	}
	for (int i = 0; i < n; i++)
		b[c[r[a[i]]]++] = a[i];
	delete [] c;
}
// find the suffix array SA of T[0..n-1] in {1..K}^n
// require T[n]=T[n+1]=T[n+2]=0, n>=2
void suffixArray(int* T, int* SA, int n, int K) {
	int n0=(n+2)/3, n1=(n+1)/3, n2=n/3, n02=n0+n2;
	int* R = new int[n02 + 3]; R[n02]= R[n02+1]= R[n02+2]=0;
	int* SA12 = new int[n02 + 3]; SA12[n02]=SA12[n02+1]=SA12[n02+2]=0;
	int* R0 = new int[n0];
	int* SA0 = new int[n0];
	for (int i=0, j=0; i < n+(n0-n1); i++)
		if (i%3 != 0)
			R[j++] = i;
	radixPass(R , SA12, T+2, n02, K);
	radixPass(SA12, R , T+1, n02, K);
	radixPass(R , SA12, T , n02, K);
	int name = 0, c0 = -1, c1 = -1, c2 = -1;
	for (int i = 0; i < n02; i++) {
		if (T[SA12[i]] != c0 || T[SA12[i]+1] != c1 || T[SA12[i]+2] != c2) {
			name++;
			c0 = T[SA12[i]];
			c1 = T[SA12[i]+1];
			c2 = T[SA12[i]+2];
		}
		if (SA12[i] % 3 == 1)
			R[SA12[i]/3] = name;
		else
			R[SA12[i]/3 + n0] = name;
	}
// recurse if names are not yet unique
	if (name < n02) {
		suffixArray(R, SA12, n02, name);
		for (int i = 0; i < n02; i++) R[SA12[i]] = i + 1;
	} else {
		for (int i = 0; i < n02; i++)
			SA12[R[i] - 1] = i;
	}
	for (int i=0, j=0; i < n02; i++)
		if (SA12[i] < n0)
			R0[j++] = 3*SA12[i];
	radixPass(R0, SA0, T, n0, K);

	for (int p=0, t=n0-n1, k=0; k < n; k++) {
		int i = GetI();
		int j = SA0[p];
		if (SA12[t] < n0 ?
			leq(T[i], R[SA12[t] + n0], T[j], R[j/3]) :
			leq(T[i],T[i+1],R[SA12[t]-n0+1], T[j],T[j+1],R[j/3+n0])
		) {
			SA[k] = i;
			t++;
			if (t == n02) {
				for (k++; p < n0; p++, k++)
					SA[k] = SA0[p];
			}
		} else { // suffix from SA0 is smaller
			SA[k] = j;
			p++;
			if (p == n0) {
				for (k++; t < n02; t++, k++)
					SA[k] = GetI();
			}
		}
	}
	delete [] R;
	delete [] SA12;
	delete [] SA0;
	delete [] R0;
}
// end suffix array

// e da vam jebem mamu maminu sa vas retardiran time limit
vector<int> sarray_scs(const string& s) {
	vector<int> t(s.size() + 3), sa(s.size());
	copy(begin(s), end(s), t.begin());
	suffixArray(t.data(), sa.data(), s.size(), 27);
	return sa;
}

pair<vector<int>, vector<int>> lcp_array(const string& s, const vector<int>& p) {
	int n = s.size(), k = 0;
	vector<int> q(n-1), r(n);
	for (int i=0; i<n; i++)
		r[p[i]] = i;
	for (int i=0; i<n; i++) {
		if (r[i] != n-1) {
			int j = p[r[i] + 1];
			while (i+k < n && j+k < n && s[i+k] == s[j+k])
				k++;
			q[r[i]] = k;
			k = max(0, k-1);
		} else {
			k = 0;
		}
	}
	return {q, r};
}

struct hole {
	int f;
	int o;
};

int main() {
	ios::sync_with_stdio(!cin.tie(0));

	int n;
	cin >> n;

	vector<string> a(n);
	for (auto& s : a) {
		cin >> s;
		for (char& c : s) {
			c = c - 'a' + 1;
		}
	}

	vector<mint> ol(a[0].size() + 1, 1);
	for (int i=0; i<n-1; i++) {
		string s = a[i] + a[i+1];
		int m1 = a[i].size(), m2 = a[i+1].size();
		auto p = sarray_scs(s);
		auto [q, r] = lcp_array(s, p);
		sparse_table t(q, int(1e9), [](int x, int y) { return min(x, y); });

		auto lcp = [&](int i, int j) {
			i = r[i];
			j = r[j];
			int l = min(i, j);
			int r = max(i, j);
			return t(l, r);
		};

		auto cmp = [&](hole u, hole v) {
			int useg[2][2], vseg[2][2];
			useg[0][0] = u.f*m1;
			useg[0][1] = useg[0][0] + u.o;
			useg[1][0] = useg[0][1] + 1;
			useg[1][1] = u.f ? m1+m2 : m1;

			// korekcija
			useg[1][0] = min(useg[1][0], useg[1][1]);

			vseg[0][0] = v.f*m1;
			vseg[0][1] = vseg[0][0] + v.o;
			vseg[1][0] = vseg[0][1] + 1;
			vseg[1][1] = v.f ? m1+m2 : m1;

			// korekcija
			vseg[1][0] = min(vseg[1][0], vseg[1][1]);

			int ui = 0, vi = 0, ud = useg[0][0], vd = vseg[0][0];
			while (ui < 2 && vi < 2) {
				int maxlen = min(useg[ui][1] - ud, vseg[vi][1] - vd);
				int len = 0;

				if (maxlen) {
					len = lcp(ud, vd);
				}

				if (len < maxlen) {
					return s[ud + len] < s[vd + len];
				} else {
					ud += maxlen;
					vd += maxlen;
					while (ui < 2 && ud == useg[ui][1]) {
						if (++ui == 1) {
							ud = useg[ui][0];
						}
					}

					while (vi < 2 && vd == vseg[vi][1]) {
						if (++vi == 1) {
							vd = vseg[vi][0];
						}
					}
				}
			}

			if (ui == vi) {
				return u.f < v.f;
			} else {
				return ui > vi;
			}
		};

		vector<hole> vh;
		for (int j=0; j<=m1; j++) vh.push_back({0, j});
		for (int j=0; j<=m2; j++) vh.push_back({1, j});
		sort(begin(vh), end(vh), cmp);

		vector<mint> nu(m2 + 1);

		mint rs = 0;
		for (auto [f, o] : vh) {
			if (f == 0) rs += ol[o];
			else nu[o] += rs;
		}

		swap(ol, nu);
	}

	cout << accumulate(begin(ol), end(ol), mint(0))() << '\n';
}