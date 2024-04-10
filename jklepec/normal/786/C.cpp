#include <bits/stdc++.h>

#define FOR(i, a, b) for (int i = (a); i < (b); i++)
#define FORd(i, a, b) for (int i = (a); i >= (b); i--)
#define REP(i, n) FOR(i, 0, n)
#define ll long long
#define pb push_back

using namespace std;

const int off = 1 << 17, MAXN = 1e5 + 5;

vector<int> solve[MAXN];

int t[2 * off];

void upd(int x, int v) {
  x += off;
  t[x] = v;
  for(x /= 2; x; x /= 2) {
    t[x] = t[x * 2] + t[x * 2 + 1];
  }
}

int get(int x, int lo, int hi, int k) {
  if(lo == hi - 1) return lo;

  int mid = (lo + hi) >> 1;
  if(t[x * 2] > k) {
    return get(x * 2, lo, mid, k);
  }
  return get(x * 2 + 1, mid, hi, k - t[x * 2]);
}

int sol[MAXN];
int a[MAXN];

queue<int> q[MAXN];

int N;

#define _ << " " <<
void gucci(int x, int i) {
  int nxt = get(1, 0, off, x + i);
  sol[x] ++;

  if(nxt < N) {
    solve[nxt].push_back(x);
  }
}

int main() {
  ios_base::sync_with_stdio(false); cin.tie(0);
  int n; cin >> n; N = n;
  REP(i, n) {
    cin >> a[i]; a[i] --;
    q[a[i]].push(i);
    solve[0].pb(i + 1);
  }

  REP(i, n) {
    if(q[i].size()) {
      upd(q[i].front(), 1);
    }
  }

  REP(i, n) {
    for(auto x: solve[i]) {
      gucci(x, i);
    }
    q[a[i]].pop();
    if(q[a[i]].size()) {
      upd(q[a[i]].front(), 1);
    }
  }

  FOR(i, 1, n + 1) {
    cout << sol[i] << " ";
  }
}