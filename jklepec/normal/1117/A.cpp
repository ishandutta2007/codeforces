#include <bits/stdc++.h>
using namespace std;
#define FOR(i, a, b) for(int i = a; i < b; ++i)
#define REP(i, n) FOR(i, 0, n)
#define _ << " " <<
#define pb push_back
#define fi first
#define se second

typedef double lf;
typedef long long ll;
typedef pair<int, int> pii;

const int mod = 1e9 + 7;
int add(int x, int y) {x += y; if(x >= mod) return x - mod; return x;}
int sub(int x, int y) {x -= y; if(x < 0) return x + mod; return x;}
int mul(int x, int y) {return (ll) x * y % mod;}

const int MAXN = 1e6 + 5;

int a[MAXN];

int main() {
  ios_base::sync_with_stdio(false); cin.tie(0);
  int n; cin >> n;
  int mx = 0;
  REP(i, n) {
    cin >> a[i];
    mx = max(mx, a[i]);
  }
  int tmp = 0, sol = 1;
  REP(i, n) {
    if(a[i] == mx) tmp ++;
    else tmp = 0;
    sol = max(sol, tmp);
  }

  cout << sol << endl;
}