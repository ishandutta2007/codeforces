#include<bits/stdc++.h>
#define MAX   400400
#define LOG   19
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
        if (x > y) x = y;
    }
template<class X,class Y>
    void maximize(X &x,const Y &y) {
        if (x < y) x = y;
    }

struct Stop {
    int pos, price, index;

    Stop(int _pos = 0, int _price = 0, int _index = 0) {
        pos = _pos; price = _price; index = _index;
    }

    bool operator < (const Stop &s) const {
        return pos < s.pos;
    }
};

const long long INF = (long long)1e18 + 7LL;

Stop stops[MAX];
int n, goal, capa, start;
int trace[MAX];
int rmq[MAX][LOG + 1];
int lg2[MAX];
void init(void) {
    scanf("%d%d%d", &goal, &capa, &n);
    FOR(i, 1, n) scanf("%d%d", &stops[i].pos, &stops[i].price);
    FOR(i, 1, n) stops[i].index = i;
    sort(stops + 1, stops + n + 1);
    stops[0] = Stop(0, INF >> 32, 0);
    stops[n + 1] = Stop(goal, INF >> 32, 0);
}
#define CHEAPER(x, y) (stops[x].price < stops[y].price ? (x) : (y))
void setupRMQ(void) {
    FOR(i, 1, n) rmq[i][0] = i;
    FOR(j, 1, LOG) FOR(i, 1, n - MASK(j) + 1)
        rmq[i][j] = CHEAPER(rmq[i][j - 1], rmq[i + MASK(j - 1)][j - 1]);
    FOR(i, 1, n) {
        while (MASK(lg2[i]) <= i) lg2[i]++;
        lg2[i]--;
    }
}
int getMin(int l, int r) {
    int k = lg2[r - l + 1];
    return CHEAPER(rmq[l][k], rmq[r - MASK(k) + 1][k]);
}
pair<long long,int> solve(int l, int r, int sta) {
    if (l >= r) return make_pair(0, sta);
    if (r - l == 1) return stops[r].pos - stops[l].pos > sta ? make_pair(INF,-1) :
            make_pair(0LL, sta - (stops[r].pos - stops[l].pos));
    int m = getMin(l + 1, r - 1);
    pair<long long, int> prev = solve(l, m, sta);
    if (prev.fi >= INF) return make_pair(INF, -1);
    int need = stops[r].pos - stops[m].pos;
    int buy = max(0, min(capa, need) - prev.se);
    trace[stops[m].index] = buy;
    pair<long long, int> next = solve(m, r, prev.se + buy);
    if (next.fi >= INF) return make_pair(INF, -1);
    long long cost = min(prev.fi + next.fi + 1LL * buy * stops[m].price, INF);
    return make_pair(cost, next.se);
}
void process(void) {
    long long res = solve(0, n + 1, capa).fi;
    if (res < INF) {
        printf("%lld\n", res);
//        FOR(i, 1, n) printf("%d ", trace[i]);
//        printf("\n");
    } else printf("-1\n");
}
int main(void) {
#ifdef ONLINE_JUDGE
//    freopen("delivery.inp", "r", stdin);
//    freopen("delivery.out", "w", stdout);
#endif // ONLINE_JUDGE
    init();
    setupRMQ();
    process();
    return 0;
}