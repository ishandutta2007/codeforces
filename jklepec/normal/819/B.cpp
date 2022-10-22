#include <bits/stdc++.h>
using namespace std;

#define FOR(i, a, b) for(int i = a; i < b; ++i)
#define REP(i, n) FOR(i, 0, n)
#define _ << " " <<

typedef long long ll;
typedef pair<int, int> point;


const ll inf = 1e15;
const int MAXN = 1e6 + 2;

int sweep[MAXN], flat[MAXN], n;

ll curr;

int solve(int i, int x) {
  flat[i] += abs(x - n) - abs(1 - x);

  if(i <= x) {
    sweep[1] ++;
    sweep[i] --;//

    sweep[i + 1] --;
    sweep[i + 1 + (n - x)] += 2;
  }
  else {
    sweep[1] --;
    sweep[i - x + 1] += 2;

    sweep[i] --;
    sweep[i + 1] --;
  }
}

int main() {
  cin >> n;

  FOR(i, 1, n + 1) {
    int x; cin >> x;
    solve(i, x);
    curr += abs(x - i);
  }

  int K = 0, tmp = 0;
  ll best = inf;

  REP(k, n) {

    tmp += sweep[k];
    curr += tmp + flat[k];

    if(curr < best) {
      best = curr;
      K = k;
    }
  }


  cout << best _ (-K + n) % n;
}