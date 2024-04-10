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
#define MAX   100100

char s[MAX];
int n, seg;

void init(void) {
    scanf("%d", &seg);
    scanf("%s", s + 1);
    n = strlen(s + 1);
}

bool canPutAll(int numChar) {
    int last = 0;
    FOR(i, 1, n) if (s[i] < 'a' + numChar) {
        if (i - last > seg) return false;
        last = i;
    }
    return last >= n - seg + 1;
}

void solvePutAll(int numChar) {
    vector<int> pos;
    FOR(i, 1, n) if (s[i] < 'a' + numChar) pos.push_back(i);
    pos.push_back(n + 1);
    int last = 0;
    string res;
    REP(i, (int)pos.size() - 1) {
        if (s[pos[i]] < 'a' + numChar - 1) {
            last = pos[i];
            res.push_back(s[pos[i]]);
        } else {
            if (pos[i + 1] - last > seg) {
                last = pos[i];
                res.push_back(s[pos[i]]);
            }
        }
    }
    sort(ALL(res));
    cout << res << endl;
    exit(0);
}

void process(void) {
    FOR(i, 1, 26) if (canPutAll(i)) solvePutAll(i);
    assert(false);
}

int main(void) {
    init();
    process();
    return 0;
}

/*** LOOK AT MY CODE. MY CODE IS AMAZING :D ***/