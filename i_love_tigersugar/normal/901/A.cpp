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

const string YES = "ambiguous";
const string NO = "perfect";

vector<int> nodes[MAX];
int cnt[MAX], par[2][MAX], n;

void process(void) {
    scanf("%d", &n);
    FOR(i, 0, n) scanf("%d", &cnt[i]);

    int cntNode = 0;
    FOR(i, 0, n) REP(love, cnt[i]) nodes[i].push_back(++cntNode);
    FOR(i, 1, n) FORE(jt, nodes[i]) REP(k, 2) par[k][*jt] = nodes[i - 1].front();
    REP(i, n) if (cnt[i] > 1 && cnt[i + 1] > 1) {
        int tmp = nodes[i + 1].back();
        par[1][tmp] = nodes[i].back();

        cout << YES << endl;
        REP(j, 2) {
            FOR(k, 1, cntNode) printf("%d ", par[j][k]); printf("\n");
        }
        return;
    }

    cout << NO << endl;
}

int main(void) {
    process();
    return 0;
}

/*** LOOK AT MY CODE. MY CODE IS AMAZING :D ***/