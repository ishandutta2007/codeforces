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
const char ch[] = "DR";

int type[MAX];
bool live[MAX];
set<int> id[2];
int n;

void process(void) {
    string input;
    cin >> n >> input;
    REP(i, n) REP(j, 2) if (input[i] == ch[j]) type[i] = j;
    REP(i, n) live[i] = true;
    REP(i, n) {
        id[type[i]].insert(i);
        id[type[i]].insert(i + n);
    }

    for (int i = 0;; i = (i + 1) % n) if (live[i]) {
        set<int> &cur = id[type[i] ^ 1];
        if (cur.empty()) {
            printf("%c\n", ch[type[i]]);
            return;
        }
        int j = *cur.lower_bound(i) % n;
        live[j] = false;
        cur.erase(j);
        cur.erase(j + n);
    }
}

int main(void) {
    process();
    return 0;
}

/*** LOOK AT MY CODE. MY CODE IS AMAZING :D ***/