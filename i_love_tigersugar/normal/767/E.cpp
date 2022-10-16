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
const int MOD = 100;
int n, m, value[MAX], cost[MAX];
bool willPay[MAX];

void init(void) {
    scanf("%d%d", &n, &m);
    FOR(i, 1, n) scanf("%d", &value[i]);
    FOR(i, 1, n) scanf("%d", &cost[i]);
    FOR(i, 1, n) cost[i] = cost[i] * (MOD - value[i] % MOD);
}

void process(void) {
    priority_queue<pair<int, int>, vector<pair<int, int> >, greater<pair<int, int> > > q;

    int cur = m;
    long long res = 0;

    FOR(i, 1, n) {
        if (value[i] % MOD == 0) continue;
        cur -= value[i] % MOD;
        q.push(make_pair(cost[i], i));

        while (cur < 0) {
            assert(!q.empty());
            cur += MOD;
            res += q.top().fi;
            willPay[q.top().se] = true;
            q.pop();
        }
    }

    cout << res << endl;
    FOR(i, 1, n) {
        if (willPay[i]) printf("%d %d\n", value[i] / MOD + 1, 0);
        else printf("%d %d\n", value[i] / MOD, value[i] % MOD);
    }
}

int main(void) {
    init();
    process();
    return 0;
}

/*** LOOK AT MY CODE. MY CODE IS AMAZING :D ***/