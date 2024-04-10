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

int main() {
  ios_base::sync_with_stdio(false); cin.tie(0);

  int a = 0, b = 0, n; cin >> n;
  for(int i = 0; i < n; ++i) {
    int x; cin >> x;
    if(x == 1) {
      a ++;
    }
    else {
      b ++;
    }
  }

  if(b) {
    cout << 2 << " ";
    b --;
  }
  REP(i, a - (a + 1) % 2) {
    cout << 1 << " ";
  }
  REP(i, b) {
    cout << 2 << " ";
  }
  if(a) REP(i, (a + 1) % 2) {
    cout << 1 << " ";
  }
  cout << endl;
}