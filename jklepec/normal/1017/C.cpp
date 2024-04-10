#include <bits/stdc++.h>
using namespace std;

#define FOR(i, a, b) for(int i = a; i < b; ++i)
#define REP(i, n) FOR(i, 0, n)
#define pb push_back
#define _ << " " <<
#define sz(x) ((int) x.size())

typedef long long ll;
typedef pair<int, int> point;

int calc(int n, int N) {
  int ret = N;
  ret += n / N;
  if(n % N != 0) ret ++;
  return ret;
}

int main() {
  ios_base::sync_with_stdio(false); cin.tie(0);

  int n; cin >> n;

  int N = sqrt(n);

  if(calc(n, N + 1) < calc(n, N)) {
    N ++;
  }
  else if(calc(n, N + 1) < calc(n, N)) {
    N --;
  }

  int l = n;

  while(l) {
    int sz = min(N, l);

    REP(i, sz) {
      cout << i + l - sz + 1 << " ";
    }

    l -= sz;
  }
}