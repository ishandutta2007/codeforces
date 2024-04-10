#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int nax = 1e5;
vector<pair<int,int>> node[nax];

int done[nax], a[nax], sign[nax];
int x;
int ans[nax];
vector<int> vlist;

void fail() {
  cout << "NO" << endl;
  exit(0);
}

void dfs(int p, int a_, int sign_) {
  if (done[p]) {
    if (sign_ == sign[p] && a_ != a[p]) fail();
    if (sign_ != sign[p]) {
      int nx = (a_-a[p])/(sign[p]-sign_);
      if (x != 1e9 && nx != x) fail();
      x = nx;
    }
    return;
  }
  done[p] = 1;
  a[p] = a_;
  sign[p] = sign_;
  vlist.push_back(p);
  for (auto [i, sum] : node[p]) {
    dfs(i, sum-a_, -sign_);
  }
}

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int n, m;
  cin >> n >> m;
  for (int i = 0; i < m; i++) {
    int a, b, sum;
    cin >> a >> b >> sum;
    a--, b--;
    node[a].emplace_back(b, sum*2);
    node[b].emplace_back(a, sum*2);
  }

  ll total = 0;
  for (int i = 0; i < n; i++) {
    if (done[i]) continue;
    x = 1e9;
    vlist.clear();
    dfs(i, 0, 1);
    vector<int> med;
    for (int p : vlist) {
      med.push_back(-a[p]*sign[p]);
    }
    sort(med.begin(), med.end());
    if (x == 1e9) x = med[med.size()/2];
    for (int p : vlist) {
      ans[p] = a[p]+sign[p]*x;
      total += abs(ans[p]);
    }
  }
  //cout << total << endl;
  cout << "YES" << endl;
  cout << setprecision(20);
  for (int i = 0; i < n; i++)
    cout << ans[i]*.5 << ' ';
  cout << endl;
}