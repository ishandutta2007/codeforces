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

const int MAXN = 2005;
int a[MAXN];

int main() {
  ios_base::sync_with_stdio(false); cin.tie(0);
  int n; cin >> n;
  REP(i, n) {
    cin >> a[i];

    a[i] += 100000;
  }

  cout << n + 1 << endl;

  cout << 1 _ n _ 100000 << endl;

  REP(i, n) {
    cout << 2 _ i + 1 _ a[i] - i - 1 << endl;
  }

}