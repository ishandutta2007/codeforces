#include <bits/stdc++.h>
using namespace std;

#define FOR(i, a, b) for(int i = a; i < b; ++i)
#define REP(i, n) FOR(i, 0, n)
#define _ << " " <<

typedef long long ll;
typedef pair<int, int> point;

const int MAXN = 3e5 + 5;

int a[MAXN], n;

void do1() {
  int l = 1; cout << 0 << " ";
  int cnt = 2;
  FOR(i, 1, n) {
    REP(j, a[i]) {
      cout << l << " ";
    }
    l = cnt;
    cnt += a[i];
  }
}

void do2() {
  int l = 1; cout << 0 << " ";
  int cnt = 2;
  FOR(i, 1, n) {
    if(a[i] > 1 && a[i - 1] > 1) {
      cout << l + 1 << " ";
      REP(j, a[i] - 1) {
        cout << l << " ";
      }
    }
    else {
      REP(j, a[i]) {
        cout << l << " ";
      }
    }
    l = cnt;
    cnt += a[i];
  }
}

int main() {
  cin >> n; n ++;

  int l = 1;
  bool ok = false;
  REP(i, n) {
    cin >> a[i];
    if(a[i] > 1 && l > 1)
      ok = true;
    l = a[i];
  }

  if(ok) {
    cout << "ambiguous\n";
    do1();
    cout << endl;
    do2();
  }
  else {
    cout << "perfect\n";
  }
}