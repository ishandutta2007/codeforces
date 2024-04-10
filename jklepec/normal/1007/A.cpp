#include <bits/stdc++.h>
using namespace std;

#define FOR(i, a, b) for(int i = a; i < b; ++i)
#define REP(i, n) FOR(i, 0, n)
#define _ << " " <<
#define sz(x) ((int) x.size())

typedef long long ll;
typedef pair<int, int> point;

const int MAXN = 3e5 + 5;

multiset<int> s;

int a[MAXN];

int main() {
  ios_base::sync_with_stdio(false); cin.tie(0);

  int n; cin >> n;
  REP(i, n) {
    cin >> a[i];
    s.insert(a[i]);
  }

  sort(a, a + n);
  reverse(a, a + n);

  int sol = 0;
  REP(i, n) {
    auto it = s.upper_bound(a[i]);
    if(it == s.end()) {
      continue;
    }
    s.erase(it);
    sol ++;
  }

  cout << sol;

}