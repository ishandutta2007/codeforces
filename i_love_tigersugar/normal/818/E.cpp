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

#define MAX   100100
#define NUM_FACT   20

vector<pair<int, int> > primeFacts;
int value[MAX], n, mod;
int sumFact[NUM_FACT][MAX];

void init(void) {
    if (scanf("%d%d", &n, &mod) != 2) exit(EXIT_SUCCESS);
    FOR(i, 1, n) scanf("%d", &value[i]);
}

vector<pair<int, int> > getPrimeFacts(int x) {
    map<int, int> res;
    for (int i = 2; 1LL * i * i <= x; i++) if (x % i == 0) {
        while (x % i == 0) {
            res[i]++;
            x /= i;
        }
    }

    if (x > 1) res[x]++;
    return vector<pair<int, int> > (ALL(res));
}

int getMultiply(int x, int p) {
    int res = 0;
    for (; x % p == 0; x /= p) res++;
    return res;
}

bool ok(int l, int r) {
    if (l > r) return false;
    REP(i, primeFacts.size()) if (sumFact[i][r] - sumFact[i][l - 1] < primeFacts[i].se) return false;
    return true;
}

void process(void) {
    primeFacts = getPrimeFacts(mod);
    REP(j, primeFacts.size()) FOR(i, 1, n)
        sumFact[j][i] = sumFact[j][i - 1] + getMultiply(value[i], primeFacts[j].fi);

    long long res = 0;
    int j = 1;
    FOR(i, 1, n) {
        while (j <= n && !ok(i, j)) j++;
        if (j <= n) res += n - j + 1;
    }

    cout << res << endl;
}

int main(void) {
    while (true) {
        init();
        process();
    }
    return 0;
}



/*** LOOK AT MY CODE. MY CODE IS AMAZING :D ***/