#include <bits/stdc++.h>
using namespace std;

const int N = 300005;

int i, n, x, y, z, m, s, nr, oMin[N], oMax[N], cntMax, cntMin;
bool viz1[N], viz2[N];
vector<int> ldad[N];
vector<pair<pair<int, int>, int>> ldau[N];

void dfsMin(int x) {
  if(viz1[x]) return;

  viz1[x] = 1; ++cntMin;
  for(auto to : ldad[x]) dfsMin(to);

  for(auto to : ldau[x]) {
    if(!oMin[to.second]) {
      if(to.first.first == x) oMin[to.second] = -1;
      else oMin[to.second] = 1;
      continue;
    }

    if(to.first.first == x && oMin[to.second] == 1) dfsMin(to.first.second);
    if(to.first.second == x && oMin[to.second] == -1) dfsMin(to.first.first);
  }
}

void dfsMax(int x) {
  if(viz2[x]) return;

  viz2[x] = 1; ++cntMax;
  for(auto to : ldad[x]) dfsMax(to);

  for(auto to : ldau[x]) {
    if(!oMax[to.second]) {
      if(to.first.first == x) oMax[to.second] = 1;
      else oMax[to.second] = -1;
    }

    if(to.first.first == x && oMax[to.second] == 1) dfsMax(to.first.second);
    if(to.first.second == x && oMax[to.second] == -1) dfsMax(to.first.first);
  }
}

int main() {
  ios_base::sync_with_stdio(0);

  cin >> n >> m >> s;
  for(i = 1; i <= m; ++i) {
    cin >> z >> x >> y;

    if(z == 1) ldad[x].push_back(y);
    else {
      ++nr;
      ldau[x].push_back(make_pair(make_pair(x, y), nr));
      ldau[y].push_back(make_pair(make_pair(x, y), nr));
    }
  }

  dfsMin(s);
  dfsMax(s);

  cout << cntMax << '\n';
  for(i = 1; i <= nr; ++i) cout << (oMax[i] == 1 ? "+" : "-");
  cout << '\n' << cntMin << '\n';
  for(i = 1; i <= nr; ++i) cout << (oMin[i] == 1 ? "+" : "-");

  return 0;
}