#include <bits/stdc++.h>
using namespace std;

#define FOR(i, a, b) for(int i = a; i < b; ++i)
#define REP(i, n) FOR(i, 0, n)
#define _ << " " <<
typedef long long ll;
typedef pair<int, int> pii;
#define pb push_back


int main() {
  int m = 0;
  int b, k; cin >> b >> k;
  b %= 2;
  REP(i, k - 1) {
    int x; cin >> x;
    m += (x % 2) * b % 2;
  }
  int x; cin >> x;
  m += x;
  m %= 2;

  if(m) cout << "odd";
  else cout << "even";
}