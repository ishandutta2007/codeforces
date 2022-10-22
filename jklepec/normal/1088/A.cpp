#include <bits/stdc++.h>
using namespace std;

#define FOR(i, a, b) for(int i = a; i < b; ++i)
#define REP(i, n) FOR(i, 0, n)
#define _ << " " <<
#define sz(x) ((int) x.size())
#define pb push_back

typedef long long ll;
typedef pair<int, int> point;

#define fi first
#define se second

const int mod = 1e9 + 7;
int add(int x, int y) {
  x += y;
  if(x >= mod) return x - mod;
  return x;
}
int mul(int x, int y) {
  return (ll) x * y % mod;
}
int sub(int x, int y) {
  x -= y;
  if(x < 0) return x + mod;
  return x;
}

int main() {
  ios_base::sync_with_stdio(false); cin.tie(0);

  int n; cin >> n;

  if(n == 1) {
    cout << -1;
  }
  else if(n % 2) {
    cout << (n - 1) _ 2 << endl;
  }
  else {
    cout << n _ 2 << endl;
  }
}