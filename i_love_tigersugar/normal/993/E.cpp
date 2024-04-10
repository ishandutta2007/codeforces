#include<bits/stdc++.h>
#define FOR(i, a, b) for (int i = (a), _b = (b); i <= _b; i++)
#define FORD(i, b, a) for (int i = (b), _a = (a); i >= _a; i--)
#define REP(i, n) for (int i = 0, _n = (n); i < _n; i++)
#define FORE(i, v) for (__typeof((v).begin()) i = (v).begin(); i != (v).end(); i++)
#define ALL(v) (v).begin(), (v).end()
#define fi   first
#define se   second
#define MASK(i) (1LL << (i))
#define BIT(x, i) (((x) >> (i)) & 1)
#define div   ___div
#define next   ___next
#define prev   ___prev
#define left   ___left
#define right   ___right
#define __builtin_popcount __builtin_popcountll
using namespace std;
template<class X, class Y>
    bool minimize(X &x, const Y &y) {
        X eps = 1e-9;
        if (x > y + eps) {
            x = y;
            return true;
        } else return false;
    }
template<class X, class Y>
    bool maximize(X &x, const Y &y) {
        X eps = 1e-9;
        if (x + eps < y) {
            x = y;
            return true;
        } else return false;
    }
template<class T>
    T Abs(const T &x) {
        return (x < 0 ? -x : x);
    }

/* Author: Van Hanh Pham */

/** END OF TEMPLATE - ACTUAL SOLUTION COMES HERE **/

const double PI = acos(-1.0);

typedef complex<double> Complex;

template<class T> int size(const T &a) {
	return a.size();
}

unsigned roundUp(unsigned v) {
	--v;
	v |= v >> 1;
	v |= v >> 2;
	v |= v >> 4;
	v |= v >> 8;
	v |= v >> 16;
	return v + 1;
}

int reverse(int num, int lg) {
	int res = 0;
	for(int i = 0; i < lg; ++i) if(num & 1 << i)
		res |= 1 << (lg - i - 1);
	return res;
}

template<class T> ostream& operator << (ostream& out, const vector<T> &a) {
	for(int i = 0; i < size(a); ++i) {
		if(i > 0) out << ' ';
		out << a[i];
	}
	return out;
}

vector<Complex> fft(vector<Complex> a, bool invert) {
	int n = size(a), lg = 0;
	while(1 << lg < n) ++lg;
	vector<Complex> roots (n);
	for(int i = 0; i < n; ++i) {
		double alpha = 2 * PI / n * i * (invert ? -1 : 1);
		roots[i] = Complex(cos(alpha), sin(alpha));
	}
	for(int i = 0; i < n; ++i) {
		int rev = reverse(i, lg);
		if(i < rev) swap(a[i], a[rev]);
	}
	for(int len = 2; len <= n; len <<= 1)
		for(int i = 0; i < n; i += len)
			for(int j = 0; j < len >> 1; ++j) {
				Complex u = a[i + j], v = a[i + j + (len >> 1)] * roots[n / len * j];
				a[i + j] = u + v;
				a[i + j + (len >> 1)] = u - v;
			}
	if(invert) for(int i = 0; i < n; ++i) a[i] /= n;
	return a;
}

vector<long long> multiply(const vector<int> &a, const vector<int> &b) {
	int n = roundUp(size(a) + size(b) - 1);
	vector<Complex> pa (n), pb (n);
	for(int i = 0; i < size(a); ++i) pa[i] = a[i];
	for(int i = 0; i < size(b); ++i) pb[i] = b[i];
	pa = fft(pa, false); pb = fft(pb, false);
	for(int i = 0; i < n; ++i) pa[i] *= pb[i];
	pa = fft(pa, true);
	vector<long long> res (n);
	for(int i = 0; i < n; ++i) res[i] = round(real(pa[i]));
	return res;
}

#define MAX   500500
int a[MAX], n, x;
int numPos, pos[MAX], left[MAX], right[MAX];

void init(void) {
    scanf("%d%d", &n, &x);
    FOR(i, 1, n) scanf("%d", &a[i]);
}

void process(void) {
    FOR(i, 1, n) if (a[i] < x) pos[++numPos] = i;
    pos[numPos + 1] = n + 1;
    FOR(i, 1, numPos) left[i] = pos[i] - pos[i - 1];
    FOR(i, 1, numPos) right[i] = pos[i + 1] - pos[i];

    vector<int> vl, vr;
    vl.push_back(0);
    FOR(i, 1, numPos) vl.push_back(left[i]);
    vr.push_back(0);
    FORD(i, numPos, 1) vr.push_back(right[i]);

    vector<long long> res = multiply(vl, vr);
    long long emptySeg = 0;
    FOR(i, 0, numPos) {
        int tmp = pos[i + 1] - pos[i] - 1;
        if (tmp > 0) emptySeg += 1LL * tmp * (tmp + 1) / 2;
    }
    cout << emptySeg;
    FOR(i, 1, numPos) {
        int tmp = numPos - i + 2;
        cout << " " << (tmp < res.size() ? res[tmp] : 0);
    }
    FOR(i, numPos + 1, n) cout << " " << 0;
    cout << endl;
}

int main(void) {
    init();
    process();
    return 0;
}

/*** LOOK AT MY CODE. MY CODE IS AMAZING :D ***/