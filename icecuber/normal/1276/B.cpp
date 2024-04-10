#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int nax = 2e5;
vector<int> node[nax];
int rem[nax];

int done[nax];
int mark[nax];
int marka[nax];
int markb[nax];

void dfs(int p, int c) {
  if (done[p]++) return;
  mark[p] = c;
  for (int i : node[p]) dfs(i, c);
}

void f(int n) {
  copy_n(rem, n, done);
  int c = 0;
  for (int i = 0; i < n; i++) {
    if (!done[i]) {
      dfs(i, c++);
    }
  }
}

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int t;
  cin >> t;
  while (t--) {
    int n, m, A, B;
    cin >> n >> m >> A >> B;
    A--, B--;
    for (int i = 0; i < n; i++) {
      rem[i] = 0;
      node[i].clear();
    }
    while (m--) {
      int a, b;
      cin >> a >> b;
      a--, b--;
      node[a].push_back(b);
      node[b].push_back(a);
    }

    rem[A] = 1;
    f(n);
    rem[A] = 0;
    copy_n(mark, n, marka);

    rem[B] = 1;
    f(n);
    rem[B] = 0;
    copy_n(mark, n, markb);

    ll ans = ll(n-2)*(n-3)/2;
    map<int,int> x, y;
    map<pair<int,int>,int> xy;
    for (int i = 0; i < n; i++) {
      if (i == A || i == B) continue;
      int a = marka[i], b = markb[i];
      ans -= x[a]++;
      ans -= y[b]++;
      ans += xy[{a,b}]++;
    }
    cout << ans << '\n';
  }
}