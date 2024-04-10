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

/* Author: Van Hanh Pham - skyvn97 */

/** END OF TEMPLATE - ACTUAL SOLUTION COMES HERE **/
class FenwickTree {
    private:
    int n;
    vector<int> cnt;
    vector<long long> sum, sumSqr;

    template<class T>
        void update(vector<T> &v, int x, const T &d) {
            for (; x <= n; x += x & -x) v[x] += d;
        }
    template<class T>
        T get(const vector<T> &v, int x) {
            T res = 0;
            for (; x >= 1; x &= x - 1) res += v[x];
            return res;
        }

    public:
    FenwickTree(int n = 0) {
        this->n = n;
        cnt.assign(n + 7, 0);
        sum.assign(n + 7, 0);
        sumSqr.assign(n + 7, 0);
    }

    void update(int pos, int val) {
        update(cnt, pos, 1);
        update(sum, pos, 1LL * val);
        update(sumSqr, pos, 1LL * val * val);
    }

    void getInfo(int pos, int &num, long long &sumVal, long long &sumValSqr) {
        num = get(cnt, pos);
        sumVal = get(sum, pos);
        sumValSqr = get(sumSqr, pos);
    }
};

#define MAX   100100

int a[MAX], n;

void init(void) {
    scanf("%d", &n);
    FOR(i, 1, n) scanf("%d", &a[i]);
}

double brute(void) {
    double res = 0;
    FOR(i, 1, n) FOR(j, i + 1, n) if (a[i] > a[j])
        res += 1.0 * (j - i) * (n - (j - i - 1) / 2.0) + (i - 1) * i / 2.0 + (n - j) * (n - j + 1) / 2.0;

    FOR(i, 1, n) FOR(j, i, n) res += (j - i + 1) * (j - i) / 4.0;

    return 2.0 * res / n / (n + 1);
}

double solve(void) {
    double res = 0.0;

    FenwickTree bit(n);

    FORD(i, n, 1) {
        int numJ = 0;
        long long sumJ = 0;
        long long sumSqrJ = 0;
        bit.getInfo(a[i] - 1, numJ, sumJ, sumSqrJ);

        long long sum = 0;
        sum += (sumJ - 1LL * numJ * i) * (2 * n + 1);
        sum -= sumSqrJ - 2 * sumJ * i + 1LL * numJ * i * i;
        sum += 1LL * numJ * i * (i - 1);
        res += 1.0 * sum / n / (n + 1);
        bit.update(a[i], i);
    }

    bit = FenwickTree(n);
    FOR(i, 1, n) {
        int numJ;
        long long sumJ;
        long long sumSqrJ;
        bit.getInfo(a[i], numJ, sumJ, sumSqrJ);
        numJ = i - 1 - numJ;
        long long sum = 1LL * numJ *(n - i) * (n - i + 1);
        res += 1.0 * sum / n / (n + 1);
        bit.update(a[i], i);
    }

    FOR(i, 1, n) {
        long long sum = 1LL * i * (i - 1) / 2 * (n - i + 1);
        res += 1.0 * sum / n / (n + 1);
    }

    return res;
}

int randInt(int l, int r) {
    return l + rand() % (r - l + 1);
}

void genTest(void) {
    n = randInt(500, 5000);
    FOR(i, 1, n) a[i] = i;
    random_shuffle(a + 1, a + n + 1);
    double res = solve();
    double ans = brute();
    if (Abs(res - ans) / max(ans, 1.0) > 1e-9) {
        printf("WA: %.13lf %.13lf\n", res, ans);
    } else printf("OK %.13lf\n", res);
}

int main(void) {
#ifdef SKY
    srand(time(NULL));
    REP(love, 200) genTest();
#endif // SKY
    init();
    printf("%.15lf\n", solve());
    return 0;
}

/*** LOOK AT MY CODE. MY CODE IS AMAZING :D ***/