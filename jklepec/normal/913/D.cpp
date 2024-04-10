#include <bits/stdc++.h>
using namespace std;

#define FOR(i, a, b) for(int i = a; i < b; ++i)
#define REP(i, n) FOR(i, 0, n)
#define _ << " " <<

typedef long long ll;
typedef pair<int, int> point;

const int MAXN = 3e5 + 5;
int cost[MAXN];
int t[MAXN];

int n, T;

vector<point> v;

bool check(int M) {

  v.clear();

  REP(i, n) {
    if(cost[i] < M)
      continue;
    v.push_back({t[i], i});
  }

  sort(v.begin(), v.end());

  if(v.size() < M)
    return false;

  ll sum = 0;
  REP(i, M) {
    sum += v[i].first;
  }

  if(sum > (ll) T || v.size() < M)
    return false;
  return true;
}

int main() {
  ios_base::sync_with_stdio(false); cin.tie(0);
  cin >> n >> T;

  REP(i, n) {
    cin >> cost[i] >> t[i];
  }

  int lo = 0, hi = n;

  while(lo < hi) {
    int mid = (lo + hi + 1) >> 1;
    if(check(mid)) {
      lo = mid;
    }
    else {
      hi = mid - 1;
    }
  }

  check(lo);

  cout << lo << endl;
  cout << lo << endl;

  REP(i, lo) {
    cout << v[i].second + 1 << ' ';
  }
}