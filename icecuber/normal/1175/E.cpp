#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

#define x first
#define y second

int nexti[20][200000];
int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int n, m;
  cin >> n >> m;
  vector<pair<int,int>> inp(n), query(m);
  for (auto&p : inp) cin >> p.x >> p.y;
  for (auto&p : query) cin >> p.x >> p.y;
  sort(inp.begin(), inp.end(), [](pair<int,int> a, pair<int,int> b){return make_pair(a.x,-a.y) < make_pair(b.x,-b.y);});
  vector<pair<int,int>> useful;
  int maxend = -1;
  for (int i = 0; i < n; i++) {
    if (inp[i].y > maxend) {
      maxend = inp[i].y;
      useful.push_back(inp[i]);
    }
  }

  for (int i = 0; i < useful.size(); i++)
    nexti[0][i] = upper_bound(useful.begin(), useful.end(), make_pair(useful[i].y,1<<30))-1-useful.begin();

  for (int l = 1; l < 20; l++)
    for (int i = 0; i < useful.size(); i++)
      nexti[l][i] = nexti[l-1][nexti[l-1][i]];

  for (auto p : query) {
    int i = upper_bound(useful.begin(), useful.end(), make_pair(p.x,1<<30))-1-useful.begin();
    if (i < 0 || useful[nexti[19][i]].y < p.y) {
      cout << -1 << endl;
      continue;
    }
    int ans = 1;
    for (int l = 19; l >= 0; l--)
      if (useful[nexti[l][i]].y < p.y) i = nexti[l][i], ans += 1<<l;
    ans += (useful[i].y < p.y);
    cout << ans << endl;
  }
}