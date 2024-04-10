#include<bits/stdc++.h>
#define FOR(i, a, b) for (int i = (a), _b = (b); i <= _b; i++)
#define FORD(i, b, a) for (int i = (b), _a = (a); i >= _a; i--)
#define REP(i, n) for (int i = 0, _n = (n); i < _n; i++)
#define FORE(i, v) for (__typeof((v).begin()) i = (v).begin(); i != (v).end(); i++)
#define ALL(v) (v).begin(), (v).end()
#define IS_INF(x)   (std::isinf(x))
#define IS_NAN(x)   (std::isnan(x))
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

string check(const string &s, char limit) {
  int n = s.size();
  int maxOne = -1;
  int minTwo = s.size();

  string res(n, '0');

  REP(i, s.size()) {
    if (s[i] < limit) maximize(maxOne, i);
    if (s[i] > limit) minimize(minTwo, i);
    if (s[i] < limit) res[i] = '1';
    if (s[i] > limit) res[i] = '2';
  }

  REP(i, s.size()) if (s[i] == limit) {
    bool mustTwo = i < maxOne;
    bool mustOne = i > minTwo;
    if (mustOne && mustTwo) return "";
    res[i] = mustOne ? '1' : '2';
  }

  string after(n, '0');
  int cnt = 0;
  REP(i, s.size()) if (res[i] == '1') after[cnt++] = s[i];
  REP(i, s.size()) if (res[i] == '2') after[cnt++] = s[i];
  REP(i, n - 1) if (after[i] > after[i + 1]) return "";
  return res;
}

string solve(const string &s) {
  REP(i, 10) {
    string tmp = check(s, i + '0');
    if (!tmp.empty()) return tmp;
  }
  return "-";
}

int main(void) {
  ios::sync_with_stdio(false); cin.tie(NULL);
  int t; cin >> t;
  REP(love, t) {
    string s; cin >> s >> s;
    cout << solve(s) << "\n";
  }
  return 0;
}

/*** LOOK AT MY CODE. MY CODE IS AMAZING :D ***/