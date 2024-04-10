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

int numCell, numShip, len, numShot;
char shot[MAX];
vector<pair<int, int> > segments;

void process(void) {
    scanf("%d%d%d%d", &numCell, &numShip, &len, &numShot);

    vector<int> points;
    points.push_back(0);
    points.push_back(numCell + 1);
    scanf("%s", shot + 1);
    FOR(i, 1, numCell) if (shot[i] == '1') points.push_back(i);
    sort(ALL(points));

    REP(i, points.size() - 1) if (points[i] + 1 <= points[i + 1] - 1)
        segments.push_back(make_pair(points[i] + 1, points[i + 1] - 1));


    int curShip = 0;
    FORE(it, segments) curShip += (it->se - it->fi + 1) / len;

    vector<int> res;
    FORE(it, segments) {
        int x = it->fi + len - 1;
        while (curShip >= numShip && x <= it->se) {
            res.push_back(x);
            x += len;
            curShip--;
        }
    }
    printf("%d\n", (int)res.size());
    FORE(it, res) printf("%d ", *it); printf("\n");
}

int main(void) {
    process();
    return 0;
}

/*** LOOK AT MY CODE. MY CODE IS AMAZING :D ***/