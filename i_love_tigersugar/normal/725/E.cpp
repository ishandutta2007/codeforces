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

#define MAX   200200

const char noAns[] = "Greed is good";
const int INF = (int) 1e9 + 7;

int a[MAX], n, c;
long long sum[MAX];
bool die[MAX];
vector<pair<int, int> > events;

void init(void) {
    scanf("%d%d", &c, &n);
    FOR(i, 1, n) scanf("%d", &a[i]);
    sort(a + 1, a + n + 1);
    FOR(i, 1, n) sum[i] = sum[i - 1] + a[i];
}

void genEvent(void) {
    int i = n;
    int tmp = c;
    while (tmp > 0) {
        while (i > 0 && a[i] > tmp) i--;
        assert(i > 0);
        events.push_back(make_pair(tmp, a[i]));
        tmp -= a[i];
        i--;
    }
    sort(ALL(events));
    //FORE(it, events) printf("%d %d\n", it->fi, it->se);
}

bool compSecond(const pair<int, int> &a, const pair<int, int> &b) {
    return a.se < b.se;
}

void process(void) {
    FOR(i, 1, c) {
        int R = upper_bound(a + 1, a + n + 1, i) - a - 1;
        if (i >= sum[R]) die[i] = i > sum[R];
        else {
            int j = lower_bound(sum, sum + R + 1, sum[R] - i) - sum + 1;
            assert (j <= R && i - (sum[R] - sum[j - 1]) >= 0);
            die[i] = die[i - (sum[R] - sum[j - 1])];
        }
    }
    assert(!die[c]);

    int j = (int)events.size();
    int res = INF;
    FORD(i, c, 1) {
        while (j > 0 && events[j - 1].fi >= i) j--;
        int id = upper_bound(events.begin() + j, events.end(), make_pair(i, i), compSecond) - events.begin() - 1;
        if (id < 0) continue;
        if (events[id].fi >= i && i >= events[id].se) {
            if (die[events[id].fi - i]) minimize(res, i);
        }
    }
    if (res < INF) printf("%d\n", res);
    else printf("%s\n", noAns);
}

int main(void) {
    init();
    genEvent();
    process();
    return 0;
}

/*** LOOK AT MY CODE. MY CODE IS AMAZING :D ***/