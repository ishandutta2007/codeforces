#include<bits/stdc++.h>
#define FOR(i,a,b) for (int i=(a),_b=(b);i<=_b;i=i+1)
#define FORD(i,b,a) for (int i=(b),_a=(a);i>=_a;i=i-1)
#define REP(i,n) for (int i=0,_n=(n);i<_n;i=i+1)
#define FORE(i,v) for (__typeof((v).begin()) i=(v).begin();i!=(v).end();i++)
#define ALL(v) (v).begin(),(v).end()
#define fi   first
#define se   second
#define MASK(i) (1LL<<(i))
#define BIT(x,i) (((x)>>(i))&1)
#define div   ___div
#define next   ___next
#define prev   ___prev
#define left   ___left
#define right   ___right
#define __builtin_popcount __builtin_popcountll
using namespace std;
template<class X,class Y>
    void minimize(X &x,const Y &y) {
        if (x>y) x=y;
    }
template<class X,class Y>
    void maximize(X &x,const Y &y) {
        if (x<y) x=y;
    }
template<class T>
    T Abs(const T &x) {
        return (x<0?-x:x);
    }

/* Author: Van Hanh Pham */

/*
This code includes fast polynomial multipler. Time complexity: O(NlogN)
*/

typedef complex<double> Complex;
const double M_PI = acos(-1.0);

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
		double alpha = 2 * M_PI / n * i * (invert ? -1 : 1);
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

vector<bool> getMark(int n, const vector<int> &v, const vector<int> &k) {
    vector<long long> mul = multiply(v, k);
    vector<bool> res(n + 1, false);
    FOR(i, 1, n) if (i + n < mul.size() && mul[i + n] > 0) res[i] = true;
    return res;
}

void process(const string &s) {
    int n = s.size();
    vector<int> v, k;
    REP(i, n) {
        if (s[i] == 'V') v.push_back(i + 1);
        if (s[i] == 'K') k.push_back(i + 1);
    }

    vector<int> polyV(n + 1, 0), polyK(n + 1, 0);
    FORE(it, v) polyV[*it] = 1;
    FORE(it, k) polyK[n - *it] = 1;
    vector<bool> markVK = getMark(n, polyV, polyK);

    polyV.assign(n + 1, 0);
    polyK.assign(n + 1, 0);
    FORE(it, v) polyV[n - *it] = 1;
    FORE(it, k) polyK[*it] = 1;
    vector<bool> markKV = getMark(n, polyV, polyK);

    vector<bool> mark(n + 1, false);
    FOR(i, 1, n) mark[i] = markVK[i] || markKV[i];
    FOR(i, 1, n) for (int j = 2 * i; j <= n; j += i)
        if (mark[j]) mark[i] = true;

    vector<int> res;
    FOR(i, 1, n) if (!mark[i]) res.push_back(i);
    printf("%d\n", (int)res.size());
    FORE(it, res) printf("%d ", *it); printf("\n");
}

int main(void) {
    ios::sync_with_stdio(false);
    int t; cin >> t;
    REP(pmp, t) {
        string s; cin >> s >> s;
        process(s);
    }
    return 0;
}


/** END OF TEMPLATE - ACTUAL SOLUTION COMES HERE **/

/*** LOOK AT MY CODE. MY CODE IS AMAZING :D ***/