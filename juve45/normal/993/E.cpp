#include <bits/stdc++.h>

#define dbg(x) cerr<<#x": "<<x<<"\n"
#define dbg_p(x) cerr<<#x": "<<x.first<<","<<x.second<<"\n"
#define dbg_v(x, n) do{cerr<<#x"[]: ";for(int _=0;_<n;++_)cerr<<x[_]<<" ";cerr<<'\n';}while(0)
#define dbg_ok cerr<<"OK!\n"

#define st first
#define nd second

using namespace std;

const int N = 100;
int n, k, x, a;
vector <long long> v, s, r;

template<class T>
ostream& operator<<(ostream& out, vector<T> v) {
	for(auto e : v) out << e << ' ';
	return out;
}

 
namespace convolution {
typedef long long int64;
 
class Complex {
public:
    static constexpr double pi = acos(-1);
    double a, b;
 
    Complex(double a=0, double b=0) : a(a), b(b) {}
 
    Complex operator + (const Complex& other) const {
        return Complex(a + other.a, b + other.b);
    }
 
    Complex operator - (const Complex& other) const {
        return Complex(a - other.a, b - other.b);
    }
 
    Complex operator * (const Complex& other) const {
        return Complex(a * other.a - b * other.b, a * other.b + b * other.a);
    }
 
    Complex inverse() const {
        double len = a*a + b*b;
        return Complex(a / len, -b / len);
    }
 
    static Complex root(int lgsz) {
        return Complex(cos(2*pi / (1<<lgsz)), sin(2*pi / (1<<lgsz)));
    }
};
 
ostream& operator << (ostream& out, const Complex& c) {
    out << c.a << " + " << c.b << "i";
    return out;
}
 
class Modular {
public:
    static const int64 mod = 2013265921;
    static const int64 r = 137;
    static int64 lgpow(int64 x, int64 pw) {
        if (pw == 0)
            return 1;
        auto x2 = lgpow(x, pw>>1);
        if (pw&1)
            return x2*x2%mod*x%mod;
        return x2*x2%mod;
    }
    int64 x;
 
    Modular(int64 x=0) {
        if (x >= mod || x <= -mod)
            x %= mod;
        this->x = x;
    }
 
    Modular operator + (const Modular& other) const {
        int64 s = x + other.x;
        if (s >= mod)
            s -= mod;
        return Modular(s);
    }
 
    Modular operator - (const Modular& other) const {
        int64 d = x - other.x;
        if (d <= -mod)
            d += mod;
        return Modular(d);
    }
 
    Modular operator * (const Modular& other) const {
        return Modular(x * other.x % mod);
    }
 
    Modular inverse() {
        return Modular(lgpow(x, mod-2));
    }
 
    static Modular root(int lgsz) {
        auto ans = root;
        return Modular(lgpow(r, 1<<(27-lgsz)));
    }
};
 
ostream& operator << (ostream& out, const Modular& m) {
    out << m.x;
    return out;
}
 
template<typename C>
class Convolution {
    int sz, lgsz;
    vector<C> roots, invRoots, lhs, rhs, res;
    vector<int> rev;
 
    static void assign(double& d, const Complex& c) {
        d = c.a;
    }
 
    static int64 myRound(const double& d) {
        return d + (d < 0 ? -0.5 : 0.5);
    }
 
    static void assign(int64& i, const Complex& c) {
        i = myRound(c.a);
    }
 
    static void assign(int& i, const Complex& c) {
        i = myRound(c.a);
    }
 
    static void assign(int64& i, const Modular& m) {
        auto t = m.x;
        if (t < 0)
            t += Modular::mod;
        i = t;
        if (t >= (Modular::mod>>1))
            i = -(Modular::mod - t);
    }
 
    static void assign(int& i, const Modular& m) {
        auto t = m.x;
        if (t < 0)
            t += Modular::mod;
        i = t;
        if (t >= (Modular::mod>>1))
            i = -(Modular::mod - t);
    }
 
    static int nextPower2(int sz) {
        int i = 0;
        while ((1<<i) < sz)
            ++i;
        return i;
    }
 
    void precalc() {
        if (2*sz != roots.size()) {
            roots.resize(2*sz);
            invRoots.resize(2*sz);
            C unit = C::root(lgsz);
            C invUnit = unit.inverse();
            roots[1<<lgsz] = invRoots[1<<lgsz] = 1;
            for (int j = (1<<lgsz) + 1; j < (1<<(lgsz+1)); ++j) {
                roots[j] = roots[j-1] * unit;
                invRoots[j] = invRoots[j-1] * invUnit;
            }
            for (int j = (1<<lgsz) - 1; j >= 1; --j) {
                roots[j] = roots[j<<1];
                invRoots[j] = invRoots[j<<1];
            }        
        }
 
        if (sz != rev.size()) {
            rev.resize(sz);
            rev[0] = 0;
            for (int i = 1; i < sz; ++i) {
                rev[i] = (rev[i >> 1] >> 1) | ((i & 1) << (lgsz - 1));
            }
        }
    }
 
    void prepInverse() {
        res.resize(sz);
        for (int i = 0; i < sz; ++i) {
            res[i] = lhs[i] * rhs[i];
        }
    }
 
    void fft(vector<C>& c, bool invert) {
        for (int i = 0; i < sz; ++i) {
            if (i < rev[i])
                swap(c[i], c[rev[i]]);
        }
 
        auto& r = (invert ? invRoots : roots);
 
        for (int halfStep = 1; halfStep < sz; halfStep <<= 1) {
            for (int start = 0; start < sz; start += (halfStep<<1)) {
                for (int i = 0; i < halfStep; ++i) {
                    C w = r[i + (halfStep<<1)] * c[start + i + halfStep];
                    c[start + i + halfStep] = c[start + i] - w;
                    c[start + i] = c[start + i] + w;
                }
            }
        }
 
        if (invert) {
            C mult = C(sz).inverse();
            for (int i = 0; i < sz; ++i) {
                c[i] = c[i] * mult;
            }
        }
    }
 
    template<typename T>
    void toField(vector<C>& c, const vector<T>& a) {
        c.resize(sz);
        for (int i = 0; i < a.size(); ++i)
            c[i] = a[i];
        for (int i = a.size(); i < sz; ++i)
            c[i] = 0;
    }
 
    template<typename T>
    void fromField(vector<T>& a, const vector<C>& c) {
        a.resize(sz);
        for (int i = 0; i < sz; ++i) {
            assign(a[i], c[i]);
        }
    }
 
public:
    template<typename T>
    vector<T> convolute(const vector<T>& lhs, const vector<T>& rhs) {
        lgsz = 1 + nextPower2(max(lhs.size(), rhs.size()));
        sz = (1<<lgsz);
        precalc();
        toField(this->lhs, lhs);
        toField(this->rhs, rhs);
        fft(this->lhs, false);
        fft(this->rhs, false);
        prepInverse();
        fft(this->res, true);
        vector<T> res;
        fromField(res, this->res);
        return res;
    }
};
 
typedef Convolution<Complex> FFT;
typedef Convolution<Modular> NTT;
};
 

int main() {
	ios_base::sync_with_stdio(false);
	cin >> n >> x;
	v.push_back(0);
	for(int i = 1; i <= n; i++) {
		cin >> a;
		if(a < x) v.push_back(i);
	}
	v.push_back(n + 1);
	long long c0 = 0;
	// dbg(v);
	for(int i = 1; i + 1 < v.size(); i++) {
		long long nr = (v[i] - v[i - 1] - 1);
		// dbg(nr);
		c0 += nr * (nr + 1) / 2;
		if(i + 1 < v.size())
			s.push_back(v[i + 1] - v[i]);
		if(i > 0)
			r.push_back(v[i] - v[i - 1]);
	}	

	long long nr = (v[v.size() - 1] - v[v.size() - 2] - 1);
	// dbg(nr);
	c0 += nr * (nr + 1) / 2;
	int nn = s.size();
	reverse(r.begin(), r.end());
	// dbg(s);
	// dbg(r);
	convolution::FFT fft;
  auto c = fft.convolute(s, r);
  // dbg(c);
  cout << c0 << ' ';
  for(int i = 0; i < n; i++) {
  	if(i + nn - 1 < c.size())
  		cout << c[i + nn - 1] << ' ';
  	else cout << "0 ";
  }
}