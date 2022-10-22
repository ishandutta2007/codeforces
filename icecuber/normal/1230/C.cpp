#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

vector<pair<int,int>> edge;

int v[7];
int ans = 0;
void rec(int n) {
  if (n == 0) {
    int taken[6][6] = {};
    int score = 0;
    for (auto e : edge) {
      int a = v[e.first], b = v[e.second];
      if (a > b) swap(a,b);
      score += !taken[a][b]++;
    }
    ans = max(ans, score);
    return;
  }
  for (int i = 0; i < 6; i++) {
    v[n-1] = i;
    rec(n-1);
  }
}

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int n, m;
  cin >> n >> m;
  for (int i = 0; i < m; i++) {
    int a, b;
    cin >> a >> b;
    a--, b--;
    edge.emplace_back(a,b);
  }
  rec(n);
  cout << ans << endl;
}