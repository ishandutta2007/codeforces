#include <bits/stdc++.h>
using namespace std;

#define FOR(i, a, b) for(int i = a; i < b; ++i)
#define REP(i, n) FOR(i, 0, n)
#define _ << " " <<

typedef long long ll;
typedef pair<int, int> point;



int main() {
  int n, m; cin >> n >> m;
  if(n > 31) {
    cout << m;
  }
  else {
    int ret = 1;

    REP(i, n) ret *= 2;
    cout << m % ret;
  }
}