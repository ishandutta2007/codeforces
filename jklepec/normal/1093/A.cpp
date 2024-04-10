#include <bits/stdc++.h>
using namespace std;

#define FOR(i, a, b) for(int i = a; i < b; ++i)
#define REP(i, n) FOR(i, 0, n)
#define _ << " " <<
#define sz(x) ((int) x.size())
#define pb push_back

typedef long long ll;
typedef pair<int, int> pii;

int main() {
  int t; cin >> t;
  while(t --) {
    int mx = 7, tmp = 1;
    int x; cin >> x;
    while(x > mx) {
      mx += 7;
      tmp ++;
    }
    cout << tmp << endl;
  }
}