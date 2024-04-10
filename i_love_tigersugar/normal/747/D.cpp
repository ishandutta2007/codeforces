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

int n, k;
bool need[MAX];

void process(void) {
    scanf("%d%d", &n, &k);
    FOR(i, 1, n) {
        int x; scanf("%d", &x);
        need[i] = x < 0;
    }

    int last = 0;
    while (last < n && !need[n - last]) last++;

    if (last == n) {
        printf("0\n");
        return;
    }

    vector<pair<int, int> > needUse;
    vector<int> between;

    vector<int> sta, fin;
    FOR(i, 1, n) if (need[i]) {
        if (i == 1 || !need[i - 1]) sta.push_back(i);
        if (i == n || !need[i + 1]) fin.push_back(i);
    }
    REP(i, sta.size()) needUse.push_back(make_pair(sta[i], fin[i]));

    sta.clear(); fin.clear();
    FOR(i, 1, n) if (!need[i]) {
        if (i == 1 || need[i - 1]) sta.push_back(i);
        if (i == n || need[i + 1]) fin.push_back(i);
    }
    REP(i, sta.size()) between.push_back(fin[i] - sta[i] + 1);
    if (!need[1]) between.erase(between.begin());
    if (!need[n]) between.erase(between.end() - 1);
    sort(ALL(between), greater<int>());

    FORE(it, needUse) k -= it->se - it->fi + 1;
    if (k < 0) {
        printf("-1\n");
        return;
    }

    int res = 2 * needUse.size() - (last == 0);
    while (!between.empty()) {
        if (k < between.back()) break;
        k -= between.back();
        between.pop_back();
        res -= 2;
    }

    if (last > 0 && k >= last) res--;

    printf("%d\n", res);
}

int main(void) {
#ifdef SKY
    freopen("tmp.txt", "r", stdin);
#endif // SKY
    process();
    return 0;
}

/*** LOOK AT MY CODE. MY CODE IS AMAZING :D ***/