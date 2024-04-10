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

int ask(int x, int y) {
  cout << '?' _ x _ y << endl;
  int ret; cin >> ret;
  return ret;
}

int a, b;

void finish(int k) {
  for(int i = k; i >= 0; --i) {
    int tmp = ask((a ^ (1 << i)), b);
    if(tmp == -1) {
      a |= (1 << i);
      b |= (1 << i);
    }
  }
}

int main() {
  ios_base::sync_with_stdio(false); cin.tie(0);

  int k = ask(0, 0);

  for(int i = 29; i >= 0; --i) {
    if(k == 0) {
      finish(i);
      break;
    }

    int ash = (a + (1 << i));
    int bsh = (b + (1 << i));

    if(k == 1) {

      int tmp = ask(ash, b);
      int tmp2 = ask(ash, bsh);

      if(tmp == 1) {
        if(tmp2 == 1) {
          k = 1;
        }
        else {
          a |= (1 << i);
          k = 1;
        }
      }
      else if(tmp == -1) {
        if(tmp2 == 1) {
          k = 1;
          a += (1 << i);
          b += (1 << i);
        }
        else {
          a += (1 << i);
          k = -1;
        }
      }
      else {
        a += (1 << i);
        k = 0;
      }
    }
    else {
      int tmp = ask(a, bsh);
      int tmp2 = ask(ash, bsh);

      if(tmp == -1) {
        if(tmp2 == -1) {
          k = -1;
        }
        else {
          b += (1 << i);
          k = -1;
        }
      }
      else if(tmp == 1) {
        if(tmp2 == -1) {
          k = -1;
          a += (1 << i);
          b += (1 << i);
        }
        else {
          b += (1 << i);
          k = 1;
        }
      }
      else {
        b += (1 << i);
        k = 0;
      }
    }
  }

  cout << '!' _ a _ b << endl;
}