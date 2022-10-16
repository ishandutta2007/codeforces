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

int f[MAX][3][2];

string solve(string digits) {
    int n = digits.size();

    memset(f, -1, sizeof f);
    f[0][0][0] = 0;

    REP(i, n) REP(j, 3) REP(k, 2) if (f[i][j][k] >= 0) {
        maximize(f[i + 1][j][k], f[i][j][k]);
        if (digits[i] != '0' || k)
            maximize(f[i + 1][(j + digits[i] - '0') % 3][1], f[i][j][k] + 1);
    }

    bool containZero = false;
    FORE(it, digits) if (*it == '0') containZero = true;

    if (containZero && f[n][0][1] <= 1) return "0";

    if (f[n][0][1] <= 0) return "-1";

    string res;
    int i = n, j = 0;
    while (res.size() < f[n][0][1]) {
        if (f[i][j][1] == f[i - 1][j][1]) {
            i--;
            continue;
        }

        res.push_back(digits[i - 1]);
        j = (j - (digits[i - 1] - '0') % 3 + 3) % 3;
        i--;
    }

    reverse(ALL(res));
    return res;
}

int main(void) {
    ios::sync_with_stdio(false); cin.tie(NULL);
    string s; while (cin >> s) cout << solve(s) << endl;
    return 0;
}

/*** LOOK AT MY CODE. MY CODE IS AMAZING :D ***/