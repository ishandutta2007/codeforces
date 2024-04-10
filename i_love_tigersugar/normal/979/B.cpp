#include<bits/stdc++.h>
#define FOR(i, a, b) for (int i = (a), _b = (b); i <= _b; i++)
#define FORD(i, b, a) for (int i = (b), _a = (a); i >= _a; i--)
#define REP(i, n) for (int i = 0, _n = (n); i < _n; i++)
#define FORE(i, v) for (__typeof((v).begin()) i = (v).begin(); i != (v).end(); i++)
#define ALL(v) (v).begin(), (v).end()
#define fi   first
#define se   second
#define MASK(i) (1LL << (i))
#define BIT(x, i) (((x) >> (i)) & 1)
#define div   ___div
#define next   ___next
#define prev   ___prev
#define left   ___left
#define right   ___right
#define __builtin_popcount __builtin_popcountll
using namespace std;
template<class X, class Y>
    bool minimize(X &x, const Y &y) {
        X eps = 1e-9;
        if (x > y + eps) {
            x = y;
            return true;
        } else return false;
    }
template<class X, class Y>
    bool maximize(X &x, const Y &y) {
        X eps = 1e-9;
        if (x + eps < y) {
            x = y;
            return true;
        } else return false;
    }
template<class T>
    T Abs(const T &x) {
        return (x < 0 ? -x : x);
    }

/* Author: Van Hanh Pham */

/** END OF TEMPLATE - ACTUAL SOLUTION COMES HERE **/
const string PLAYERS[3] = {"Kuro", "Shiro", "Katie"};
const string DRAW = "Draw";

int getScore(string s, int numTurn) {
    if (s.size() == 1) return 1;

    map<char, int> cnt;
    FORE(it, s) cnt[*it]++;
    int maxApp = 0;
    FORE(it, cnt) maximize(maxApp, it->se);
    if (0LL + maxApp + numTurn <= (int)s.size()) return maxApp + numTurn;
    if (maxApp + numTurn == (int)s.size() + 1) return numTurn == 1 ? s.size() - 1 : s.size();
    return s.size();
}

int main(void) {
    int numTurn; cin >> numTurn;
    int score[5];
    REP(aye, 3) {
        string input; cin >> input;
        score[aye] = getScore(input, numTurn);
    }

    REP(i, 3) {
        int j = (i + 1) % 3, k = (i + 2) % 3;
        if (score[i] > score[j] && score[i] > score[k]) {
            cout << PLAYERS[i] << endl;
            return 0;
        }
    }

    cout << DRAW << endl;
    return 0;
}

/*** LOOK AT MY CODE. MY CODE IS AMAZING :D ***/