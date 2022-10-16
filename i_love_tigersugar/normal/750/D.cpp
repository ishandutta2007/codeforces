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

const int dx[] = {1, 1, 0, -1, -1, -1, 0, 1};
const int dy[] = {0, 1, 1, 1, 0, -1, -1, -1};

set<pair<int, int> > visited;
set<pair<int, int> > used[10][100];

int t[100], n;

void bfs(int x, int y, int dir, int depth) {
    if (depth >= n) return;
    if (used[dir][depth].find(make_pair(x, y)) != used[dir][depth].end()) return;
    used[dir][depth].insert(make_pair(x, y));

    REP(love, t[depth]) {
        x += dx[dir];
        y += dy[dir];
        visited.insert(make_pair(x, y));
    }
    bfs(x, y, (dir + 7) % 8, depth + 1);
    bfs(x, y, (dir + 1) % 8, depth + 1);
}

int main(void) {
    scanf("%d", &n);
    REP(i, n) scanf("%d", &t[i]);
    t[0]--;

    visited.insert(make_pair(0, 0));
    bfs(0, 0, 0, 0);

    cout << visited.size() << endl;
    return 0;
}

/*** LOOK AT MY CODE. MY CODE IS AMAZING :D ***/