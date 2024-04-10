#include <bits/stdc++.h>
using namespace std;

#define FOR(i, a, b) for(int i = a; i < b; ++i)
#define REP(i, n) FOR(i, 0, n)

#define _ << " " <<

typedef long long ll;
typedef pair<int, int> point;

int main() {
  int k, a, b;
  cin >> k >> a >> b;

  if(a < k && b < k) {
    cout << -1;
    return 0;
  }
  if(a / k == 0 && b % k != 0) {
    cout << -1;
    return 0;
  }
  if(b / k == 0 && a % k != 0) {
    cout << -1;
    return 0;
  }

  cout << a / k + b / k;
}