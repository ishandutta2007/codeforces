#include <bits/stdc++.h>
using namespace std;

#define FOR(i, a, b) for(int i = a; i < b; ++i)
#define REP(i, n) FOR(i, 0, n)
#define _ << " " <<
#define sz(x) ((int) x.size())
#define pb push_back

typedef long long ll;
typedef pair<int, int> point;

const int MAXN = 1e7 + 5;

int sito[MAXN];

int main() {
  ios_base::sync_with_stdio(false); cin.tie(0);

  FOR(i, 2, MAXN) {
    if(!sito[i]) {
      sito[i] = i;
      for(int j = i; j < MAXN; j += i) sito[j] = i;
    }
  }

  int n; cin >> n;

  if(n == 1) {
    cout << 1 _ 0 << endl;
    return 0;
  }

  int sol = 1, mx = 0;

  bool treba = false;
  int mn = n;

  while(n != 1) {
    int p = sito[n], rep = 0;
    while(n % p == 0) {
      rep ++;
      n /= p;
    }

    sol *= p;

    int tmp = 0;

    int off = 1;
    while(off < rep) {
      off *= 2;
    }
    if(off != rep) treba = true;
    while(off != 1) {
      off /= 2;
      tmp ++;
    }

    mn = min(mn, tmp);
    mx = max(tmp, mx);
  }

  if(treba) mx ++;
  if(!treba && mn != mx) mx ++;
  cout << sol _ mx << endl;
}