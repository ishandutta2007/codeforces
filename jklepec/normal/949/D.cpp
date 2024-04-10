#include <bits/stdc++.h>
using namespace std;

#define FOR(i, a, b) for(int i = a; i < b; ++i)
#define REP(i, n) FOR(i, 0, n)
#define _ << " " <<

typedef long long ll;
typedef pair<int, int> point;

const int MAXN = 1e5 + 5;

int n, d, b;
int pref[MAXN];

int query(ll l, ll r) {
  l = max((ll) 0, l);
  r = min((ll) n - 1, r);

  return pref[r] - (l ? pref[l - 1] : 0);
}

bool check(int k) {
  FOR(i, k, (n + 1) / 2) {
    int sum = query(i - (ll) (i + 1) * d, i + (ll) (i + 1) * d);
    if(sum < (i - k + 1) * b) {
      return false;
    }
  }

  FOR(i, (n + 1) / 2, n - k) {
    int sum = query(i - (ll) (n - i) * d, i + (ll) (n - i) * d);
    if(sum < (n - k - i) * b) {
      return false;
    }
  }

  return true;
}

int main() {
  ios_base::sync_with_stdio(false); cin.tie(0);

  cin >> n >> d >> b;

  REP(i, n) {
    cin >> pref[i];
    pref[i] += (i ? pref[i - 1] : 0);
  }

  int lo = 0, hi = (n / 2) + 1;

  while(lo < hi) {
    int mid = (lo + hi) >> 1;
    if(check(mid)) {
      hi = mid;
    }
    else {
      lo = mid + 1;
    }
  }

  cout << lo;
}