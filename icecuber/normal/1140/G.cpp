#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define x first
#define y second

vector<pair<int,ll>> node[300000][2];
ll switch_w[300000];
int centroid[300000];

ll ans[600000];
struct Query {
  int x, y, i;
};

ll dist[2][300000][2];

int flood0(int p, int par = -1) {
  if (centroid[p]) return 0;
  dist[0][p][0] = dist[0][p][1] = 1e18;
  dist[1][p][0] = dist[1][p][1] = 1e18;
  int sz = 1;
  for (auto&i : node[p][0])
    if (i.first != par)
      sz += flood0(i.first, p);
  return sz;
}

int centroid_ans;
int calcCentroid(int p, int n, int par = -1) {
  if (centroid[p]) return 0;

  int ok = 1, tot = 1;
  for (auto&i : node[p][0]) {
    if (i.x == par) continue;
    int sz = calcCentroid(i.x, n, p);
    if (sz > n/2) ok = 0;
    tot += sz;
  }
  if (n-tot > n/2) ok = 0;
  if (ok) centroid_ans = p;
  return tot;
}

struct Pos {
  int x, y;
  ll dist;
};
bool operator<(Pos a, Pos b) {
  return a.dist > b.dist;
}

void dijkstra(int x0, int y0, ll dist[][2]) {
  //dist reset in flood0
  priority_queue<Pos> pq;
  pq.push({x0,y0,0});
  dist[x0][y0] = 0;
  while (pq.size()) {
    Pos p = pq.top();
    pq.pop();
    if (p.dist > dist[p.x][p.y]) continue;
    for (int ei = 0; ei <= node[p.x][p.y].size(); ei++) {
      pair<int,int> i;
      ll d;
      if (ei == node[p.x][p.y].size()) {
	i = {p.x,!p.y};
	d = p.dist+switch_w[p.x];
      } else {
	i = {node[p.x][p.y][ei].first,p.y};
	d = p.dist+node[p.x][p.y][ei].second;
      }
      if (!centroid[i.x] && d < dist[i.x][i.y]) {
	dist[i.x][i.y] = d;
	pq.push({i.x,i.y,d});
      }
    }
  }
}

void floodFill(int p, int*branch, int col, int par = -1) {
  if (centroid[p]) return;
  branch[p] = col;
  for (auto&i : node[p][0])
    if (i.x != par)
      floodFill(i.x, branch, col, p);
}

int branch[300000];
void solve(int p, vector<Query>&query) {
  int sz = flood0(p);
  calcCentroid(p, sz);
  int c = centroid_ans;
  //cerr << "Centroid: " << c*2+1 << endl;
  dijkstra(c, 0, dist[0]);
  dijkstra(c, 1, dist[1]);
  for (auto p : query) {
    for (int j : {0,1})
      ans[p.i] = min(ans[p.i], dist[j][p.x/2][p.x%2]+dist[j][p.y/2][p.y%2]);
  }
  centroid[c] = 1;
  int j = 0;
  for (auto&p : node[c][0]) {
    int i = p.x;
    if (centroid[i]) continue;
    floodFill(i, branch, j++);
  }
  vector<vector<Query>> queries(j);
  for (auto&p : query) {
    //cout << p.x << ' ' << p.y << ' ' << branch[p.x/2] << ' ' << branch[p.y/2] << ' ' << j << endl;
    if (p.x/2 != c && p.y/2 != c && branch[p.x/2] == branch[p.y/2])
      queries[branch[p.x/2]].push_back(p);
  }
  j = 0;
  for (auto&p : node[c][0]) {
    int i = p.first;
    if (centroid[i]) continue;
    solve(i, queries[j++]);
  }
}

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int n;
  cin >> n;
  for (int i = 0; i < n; i++)
    cin >> switch_w[i];
  for (int i = 1; i < n; i++) {
    int a, b;
    ll w0, w1;
    cin >> a >> b >> w0 >> w1;
    a--,b--;
    node[a][0].emplace_back(b,w0);
    node[a][1].emplace_back(b,w1);
    node[b][0].emplace_back(a,w0);
    node[b][1].emplace_back(a,w1);
  }
  int q;
  cin >> q;

  vector<Query> query(q);
  int i = 0;
  for (Query&p : query) {
    cin >> p.x >> p.y;
    p.x--, p.y--;
    p.i = i++;
  }

  fill_n(ans, q, 1e18);
  solve(0, query);
  for (int i = 0; i < q; i++)
    cout << ans[i] << endl;
}