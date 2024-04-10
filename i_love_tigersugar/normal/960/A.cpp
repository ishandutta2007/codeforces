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
    void minimize(X &x, const Y &y) {
        if (x > y) x = y;
    }
template<class X, class Y>
    void maximize(X &x, const Y &y) {
        if (x < y) x = y;
    }
template<class T>
    T Abs(const T &x) {
        return (x < 0 ? -x : x);
    }

/* Author: Van Hanh Pham */

/** END OF TEMPLATE - ACTUAL SOLUTION COMES HERE **/

const string YES = "YES";
const string NO = "NO";

bool check(string s) {
    map<char, int> cnt;
    FORE(it, s) cnt[*it]++;

    int numA = cnt['a'];
    int numB = cnt['b'];
    int numC = cnt['c'];

    if (numA + numB + numC != s.size()) return false;
    if (numA == 0 || numB == 0) return false;
    if (numA != numC && numB != numC) return false;

    if (s != string(numA, 'a') + string(numB, 'b') + string(numC, 'c')) return false;
    return true;
}

int main(void) {
    string input;
    while (cin >> input) cout << (check(input) ? YES : NO) << endl;
    return 0;
}

/*** LOOK AT MY CODE. MY CODE IS AMAZING :D ***/