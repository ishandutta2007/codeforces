#include <bits/stdc++.h>
using namespace std;

#define FOR(i, a, b) for(int i = a; i < b; ++i)
#define REP(i, n) FOR(i, 0, n)
#define _ << " " <<

typedef long long ll;
typedef pair<int, int> point;



int main() {
  int a, b; cin >> a >> b;
  int sol = 1;

  FOR(i, 1, min(a, b) + 1) sol *= i;
  cout << sol;
}