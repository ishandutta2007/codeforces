#include<bits/stdc++.h>
#define MAX   1010
#define FOR(i,a,b) for (int i=(a),_b=(b);i<=_b;i=i+1)
#define FORD(i,b,a) for (int i=(b),_a=(a);i>=_a;i=i-1)
#define REP(i,n) for (int i=0,_n=(n);i<_n;i=i+1)
#define FORE(i,v) for (__typeof((v).begin()) i=(v).begin();i!=(v).end();i++)
#define ALL(v) (v).begin(),(v).end()
#define fi   first
#define se   second
#define MASK(i) (1LL<<(i))
#define BIT(x,i) (((x)>>(i))&1)
#define next   ___next
#define prev   ___prev
#define left   ___left
#define right   ___right
using namespace std;
template<class X,class Y>
    void minimize(X &x,const Y &y) {
        if (x>y) x=y;
    }
template<class X,class Y>
    void maximize(X &x,const Y &y) {
        if (x<y) x=y;
    }
/*
This code includes fast polynomial multipler. Time complexity: O(NlogN)
*/
typedef complex<double> Complex;

#ifdef ONLINE_JUDGE
const double M_PI=acos(-1.0);
#endif // ONLINE_JUDGE

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

vector<int> multiply(const vector<int> &a, const vector<int> &b) {
	int n = roundUp(size(a) + size(b) - 1);
	vector<Complex> pa (n), pb (n);
	for(int i = 0; i < size(a); ++i) pa[i] = a[i];
	for(int i = 0; i < size(b); ++i) pb[i] = b[i];
	pa = fft(pa, false); pb = fft(pb, false);
	for(int i = 0; i < n; ++i) pa[i] *= pb[i];
	pa = fft(pa, true);
	vector<int> res (n);
	for(int i = 0; i < n; ++i) res[i] = round(real(pa[i]));
	return res;
}
vector<int> getResult(const vector<int> &a) {
    vector<int> res;
    REP(i,a.size()) if (a[i]>0) res.push_back(i);
    return (res);
}
vector<int> getPoly(const vector<int> &a) {
    assert(!a.empty());
    vector<int> res(a.back()+1,0);
    FORE(it,a) res[*it]=1;
    return (res);
}
int n,m,a[MAX];
vector<int> res[MAX];
bool solved[MAX];
void init(void) {
    scanf("%d%d",&n,&m);
    FOR(i,1,n) scanf("%d",&a[i]);
    sort(a+1,a+n+1);
}
vector<int> solve(int m) {
    if (solved[m]) return (res[m]);
    solved[m]=true;
    if (m==0) return (res[m]=vector<int>(1,0));
    if (m==1) return (res[m]=vector<int>(a+1,a+n+1));
    return (res[m]=getResult(multiply(getPoly(solve(m/2)),getPoly(solve(m-m/2)))));
}
void process(void) {
    vector<int> res=solve(m);
    FORE(it,res) printf("%d ",*it); printf("\n");
}
int main(void) {
    init();
    process();
    return 0;
}