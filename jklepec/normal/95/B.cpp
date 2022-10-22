#include <bits/stdc++.h>
using namespace std;

#define FOR(i, a, b) for(int i = a; i < b; ++i)
#define REP(i, n) FOR(i, 0, n)
#define _ << " " <<

typedef long long ll;
typedef pair<int, int> point;

const int inf = 1e9;

int n, can;

void ispis() {

  REP(i, n / 2 + 1) {
    cout << 4;
  }
  REP(i, n - n / 2 + (n + 1) % 2) {
    cout << 7;
  }
  cout << endl;
  return;
}

void check(int l, int r, int c) {
  if(c == 4) l ++;
  else r ++;

  if(min(l, r) + (n - l - r) < max(l, r)) return;

  can = max(can, (l + r - 1) * 2 + (c + 1) % 2);
}

int main() {
  string s; cin >> s;

  n = s.size();
  if(n % 2) {
    ispis(); return 0;
  }

  can = -1;

  int l = 0, r = 0;
  REP(i, n) {
    if(s[i] != '4' && s[i] != '7') {
      if(s[i] - '0' < 4)
        check(l, r, 4);
      if(s[i] - '0' < 7)
        check(l, r, 7);
      break;
    }
    if(s[i] - '0' == 4)
      check(l, r, 7);
    if(s[i] - '0' == 4) l ++;
    else r ++;
  }
  if(l == n / 2 && r == n / 2) {cout << s; return 0;}
  if(can == -1) ispis();
  else {
    int ll = 0, rr = 0;
    REP(i, can / 2) {
      if(s[i] - '0' == 4) ll ++;
      else rr ++;
      cout << s[i];
    }
    if(can % 2) {cout << 4; ll ++;}
    else {rr ++; cout << 7;}

    while(ll < n / 2) {cout << 4; ll ++;}
    while(rr < n / 2) {cout << 7; rr ++;}
  }
}