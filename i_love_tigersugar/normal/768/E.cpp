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

map<long long, int> gr;
int total;

int calc(long long mask) {
    if (gr.find(mask) != gr.end()) return gr[mask];

    int left = total;
    FOR(i, 1, total) if (BIT(mask, i)) left -= i;

    set<int> s;
    FOR(i, 1, left) if (!BIT(mask, i)) s.insert(calc(mask | MASK(i)));

    REP(i, 100000) if (s.find(i) == s.end()) return gr[mask] = i;
}

void calcGrundy(int n) {
    gr.clear();
    total = n;
    printf("%d, ", calc(0));
    //FORE(it, gr) printf("GR of %lld is %d\n", it->fi, it->se);
}

const int magic[] = {1, 1, 2, 2, 2, 3, 3, 3, 3, 4, 4, 4, 4, 4, 5, 5, 5, 5, 5, 5, 6, 6, 6, 6, 6, 6, 6, 7, 7, 7, 7, 7, 7, 7, 7, 8, 8, 8, 8, 8, 8, 8, 8, 8, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 10, 10, 10, 10, 10, 10};

int main(void) {
    //FOR(i, 1, 60) calcGrundy(i);

    int res = 0;
    int n; scanf("%d", &n);
    REP(love, n) {
        int x; scanf("%d", &x);
        res ^= magic[x - 1];
    }

    cout << (res == 0 ? "YES" : "NO") << endl;

    return 0;
}

/*** LOOK AT MY CODE. MY CODE IS AMAZING :D ***/