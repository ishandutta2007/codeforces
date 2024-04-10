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

#define MAX   300300
const string A = "USB";
const string B = "PS/2";

int numA, numB, numBoth, numItem;
pair<int, int> items[MAX];

void init(void) {
    scanf("%d%d%d%d", &numA, &numB, &numBoth, &numItem);
    REP(i, numItem) {
        int x;
        char s[10];
        scanf("%d%s", &x, s);
        items[i].fi = x;
        items[i].se = string(s) == A ? 1 : 2;
    }
    sort(items, items + numItem);
}

void process(void) {
    long long totCost = 0;
    int cnt = 0;

    REP(i, numItem) {
        if (items[i].se == 1 && numA + numBoth > 0) {
            cnt++;
            totCost += items[i].fi;
            if (numA > 0) numA--; else numBoth--;
        }

        if (items[i].se == 2 && numB + numBoth > 0) {
            cnt++;
            totCost += items[i].fi;
            if (numB > 0) numB--; else numBoth--;
        }
    }

    cout << cnt << " " << totCost << endl;
}

int main(void) {
    init();
    process();
    return 0;
}

/*** LOOK AT MY CODE. MY CODE IS AMAZING :D ***/