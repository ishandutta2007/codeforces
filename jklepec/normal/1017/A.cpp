#include <bits/stdc++.h>
using namespace std;

#define FOR(i, a, b) for(int i = a; i < b; ++i)
#define REP(i, n) FOR(i, 0, n)
#define pb push_back
#define _ << " " <<
#define sz(x) ((int) x.size())

typedef long long ll;
typedef pair<int, int> point;

int main() {
  ios_base::sync_with_stdio(false); cin.tie(0);
  int n; cin >> n;

  int uk = 0;
  REP(i, 4) {
    int x; cin >> x;
    uk += x;
  }

  int sol = 0;

  REP(i, n - 1) {
    int tmp = 0;
    REP(j, 4) {
      int x; cin >> x;
      tmp += x;
    }
    if(tmp > uk)
      sol ++;
  }
  cout << sol + 1;
}