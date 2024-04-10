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

/** END OF TEMPLATE - ACTUAL SOLUTION COMES HERE **/

#define MAX   200200

vector<int> haveGCD[MAX];
bool banned[MAX];
int mod, f[MAX], trace[MAX];

void init(void) {
    int n; scanf("%d%d", &n, &mod);
    REP(love, n) {
        int x; scanf("%d", &x);
        banned[x] = true;
    }

    REP(i, mod) if (!banned[i]) haveGCD[__gcd(i, mod)].push_back(i);
}

void optimize(void) {
    FOR(i, 1, mod) f[i] = haveGCD[i].size();
    FOR(i, 1, mod) for (int j = 2 * i; j <= mod; j += i)
        if (f[j] < f[i] + haveGCD[j].size()) {
            f[j] = f[i] + haveGCD[j].size();
            trace[j] = i;
        }
}

int modulo(long long a, int n) {
    return (a % n + n) % n;
}

int extendedEuclid(int a, int b, int &x, int &y) {
    int xx = y = 0;
    int yy = x = 1;
    while (b != 0) {
        int q = a / b;
        int t = b; b = a % b; a = t;
        t = xx; xx = x - q * xx; x = t;
        t = yy; yy = y - q * yy; y = t;
    }
    return a;
}

int modularLinearEquationSolver(int a, int b, int n) {
    int x, y;
    int d = extendedEuclid(a, n, x, y);
    if (b % d == 0) {
        x = modulo(1LL * x * (b / d), n);
        REP(i, d) return modulo(x + 1LL * i * (n / d), n);
    }
    return -1;
}

void findSolution(void) {
    vector<int> product;

    int best = 1;
    FOR(i, 1, mod) if (f[best] < f[i]) best = i;

    while (best > 0) {
        FORE(it, haveGCD[best]) product.push_back(*it);
        best = trace[best];
    }

    product.push_back(1);
    reverse(ALL(product));

    vector<int> res;
    REP(i, product.size() - 1) res.push_back(modularLinearEquationSolver(product[i], product[i + 1], mod));

    printf("%d\n", (int)res.size());
    FORE(it, res) printf("%d ", *it); printf("\n");
}

int main(void) {
    init();
    optimize();
    findSolution();
    return 0;
}

/*** LOOK AT MY CODE. MY CODE IS AMAZING :D ***/