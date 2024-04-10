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
#define MAX_SIZE   111
const long long INF = (long long)1e15 + 7LL;

vector<long long> canSum;
int n, k, a[MAX];
long long sum[MAX];

int cnt[MAX];

void init(void) {
    scanf("%d%d", &n, &k);
    FOR(i, 1, n) scanf("%d", &a[i]);
    FOR(i, 1, n) sum[i] = sum[i - 1] + a[i];
}

void process(void) {
    long long tmp = 1;
    while (canSum.size() < MAX_SIZE && Abs(tmp) < INF) {
        canSum.push_back(tmp); tmp *= k;
    }

    sort(ALL(canSum));
    canSum.resize(unique(ALL(canSum)) - canSum.begin());

    vector<long long> values;
    REP(i, n + 1) values.push_back(sum[i]);
    sort(ALL(values));
    values.resize(unique(ALL(values)) - values.begin());

    long long res = 0;
    FORD(i, n, 1) {
        int id = lower_bound(ALL(values), sum[i]) - values.begin();
        cnt[id]++;
        FORE(it, canSum) {
            long long reqSum = sum[i - 1] + *it;
            id = lower_bound(ALL(values), reqSum) - values.begin();
            if (id < values.size() && values[id] == reqSum) res += cnt[id];
        }
    }

    cout << res << endl;
}

int main(void) {
    init();
    process();
    return 0;
}

/*** LOOK AT MY CODE. MY CODE IS AMAZING :D ***/