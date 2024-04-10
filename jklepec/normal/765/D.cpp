#include <bits/stdc++.h>
using namespace std;

#define FOR(i, a, b) for(int i = a; i < b; ++i)
#define REP(i, n) FOR(i, 0, n)

#define _ << " " <<

typedef long long ll;
typedef pair<int, int> point;

const int MAXN = 1e6 + 5;

int a[MAXN];
int bio[MAXN];

int b[MAXN];
int c[MAXN];

int cookie = 1;

int main() {
  int n; cin >> n;
  REP(i, n) cin >> a[i];

  REP(i, n) {
    if(!bio[a[i]]) {
      bio[a[i]] = cookie;
      c[cookie - 1] = a[i];
      b[i] = cookie ++;
    }
    else {
      b[i] = bio[a[i]];
    }
  }

  bool ok = true;
  REP(i, cookie - 1) {
    if(b[c[i] - 1] != i + 1) {
      ok = false;
    }
  }

  if(!ok) {
    cout << -1;
  }
  else {
    cout << cookie - 1 << endl;
    REP(i, n) {
      cout << b[i] << ' ';
    }
    cout << endl;
    REP(i, cookie - 1) {
      cout << c[i] << ' ';
    }
  }

}