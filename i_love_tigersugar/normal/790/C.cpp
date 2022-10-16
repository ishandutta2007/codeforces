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
const int INF = (int)1e9 + 7;

int f[MAX][MAX][MAX][3];

#define LAST_V   0
#define LAST_K   1
#define LAST_X   2

int countGreater(const vector<int> &v, int pos, int value) {
    int res = 0;
    REP(i, pos) if (v[i] > value) res++;
    return res;
}

int solve(string s) {
    int n = s.size();
    vector<int> posV, posK, posX;

    REP(i, n) {
        if (s[i] == 'V') posV.push_back(i);
        else if (s[i] == 'K') posK.push_back(i);
        else posX.push_back(i);
    }

    int numV = posV.size(), numK = posK.size(), numX = posX.size();

    memset(f, 0x3f, sizeof f);
    f[0][0][0][LAST_X] = 0;

    REP(i, numV + 1) REP(j, numK + 1) REP(k, numX + 1) REP(last, 3) if (f[i][j][k][last] < INF) {
        int newPos = i + j + k;

        if (i < numV) {
            int cost = countGreater(posK, j, posV[i]) + countGreater(posX, k, posV[i]);
            minimize(f[i + 1][j][k][LAST_V], f[i][j][k][last] + cost);
        }
        if (j < numK && last != LAST_V) {
            int cost = countGreater(posV, i, posK[j]) + countGreater(posX, k, posK[j]);
            minimize(f[i][j + 1][k][LAST_K], f[i][j][k][last] + cost);
        }
        if (k < numX) {
            int cost = countGreater(posV, i, posX[k]) + countGreater(posK, j, posX[k]);
            minimize(f[i][j][k + 1][LAST_X], f[i][j][k][last] + cost);
        }
    }

    int res = INF;
    REP(i, 3) minimize(res, f[numV][numK][numX][i]);
    return res;
}

int main(void) {
    string s; while (cin >> s >> s) cout << solve(s) << endl;
    return 0;
}

/*** LOOK AT MY CODE. MY CODE IS AMAZING :D ***/