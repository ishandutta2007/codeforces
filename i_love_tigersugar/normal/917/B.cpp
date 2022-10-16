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

#define MAX   111

vector<pair<int, int>> adj[MAX];
int result[MAX][MAX][29][2];
int n, m;

void loadGraph(void) {
    char str[7];
    memset(str, 0, sizeof str);

    scanf("%d%d", &n, &m);
    REP(love, m) {
        int u, v; scanf("%d%d%s", &u, &v, str);
        adj[u].push_back(make_pair(v, str[0] - 'a'));
    }
}

int getResult(int a, int b, int last, int player) {
    int &res = result[a][b][last][player];
    if (res >= 0) return res;
    if (player == 0) {
        FORE(it, adj[a]) if (it->se >= last) {
            if (getResult(it->fi, b, it->se, player ^ 1) == player)
                return res = player;
        }
    } else {
        FORE(it, adj[b]) if (it->se >= last) {
            if (getResult(a, it->fi, it->se, player ^ 1) == player)
                return res = player;
        }
    }
    return res = player ^ 1;
}

void process(void) {
    memset(result, -1, sizeof result);
    FOR(i, 1, n) {
        string tmp;
        FOR(j, 1, n) tmp.push_back(getResult(i, j, 0, 0) + 'A');
        cout << tmp << "\n";
    }
}

int main(void) {
    loadGraph();
    process();
    return 0;
}

/*** LOOK AT MY CODE. MY CODE IS AMAZING :D ***/