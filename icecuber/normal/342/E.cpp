#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

vector<int> node[100000];
int sz[100000], done[100000], dist[100000];
vector<int> last_list;
int calcSize(int p, int par = -1, int d = 0) {
  last_list.push_back(p);
  sz[p] = 1;
  dist[p] = d;
  for (int i : node[p]) {
    if (par == i || done[i]) continue;
    sz[p] += calcSize(i,p,d+1);
  }
  return sz[p];
}

int findCentroid(int p) {
  last_list.clear();
  int n = calcSize(p);
  for (int c : last_list) {
    int ok = n-sz[c] <= n/2;
    for (int i : node[c])
      if (!done[i] && sz[i] > n/2 && sz[i] < sz[c]) ok = 0;
    if (ok) return c;
  }
  //cout << "What?" << endl;
  assert(0);
}


vector<pair<int,int>> query[100000];
int ans[100000];
int paint[100000];

void solve(int p) {
  int c = findCentroid(p);
  last_list.clear();
  calcSize(c);
  //cout << c+1 << endl;
  vector<pair<int,int>> red;
  //cout << "Distances:" << endl;
  for (int i : last_list) {
    //cout << i+1 << ' ' << dist[i] << ' ' << sz[i] << endl;
    int d = dist[i], t = paint[i];
    if (paint[i] < 1e9) {
      red.emplace_back(-t, d);
    }
  }
  sort(red.begin(), red.end());
  vector<pair<int,int>> bin;
  for (auto p : red) {
    while (bin.size() && p.second <= bin.back().second) bin.pop_back();
    bin.emplace_back(p);
  }
  //cout << "Centroid " << c+1 << endl;
  //for (auto p : bin) cout << p.first << ' ' << p.second << endl;
  //cout << endl;
  for (int i : last_list) {
    for (auto p : query[i]) {
      auto it = upper_bound(bin.begin(), bin.end(), make_pair(-p.first,0));
      if (it != bin.end()) {
	//cout << p.second << ' ' << i+1 << ' ' << dist[i]+it->second << endl;
	ans[p.second] = min(ans[p.second], dist[i]+it->second);
      }
    }
  }

  done[c] = 1;
  for (int i : node[c])
    if (!done[i])
      solve(i);
}

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int n, m;
  cin >> n >> m;
  for (int i = 1; i < n; i++) {
    int a, b;
    cin >> a >> b;
    a--, b--;
    node[a].push_back(b);
    node[b].push_back(a);
  }

  fill_n(paint, n, 1e9);
  paint[0] = -1;
  int queries = 0;
  for (int i = 0; i < m; i++) {
    int t, v;
    cin >> t >> v;
    v--;
    if (t == 1) {
      paint[v] = min(paint[v], i);
    } else {
      query[v].emplace_back(i,queries++);
    }
  }
  fill_n(ans, queries, n);
  solve(0);
  for (int i = 0; i < queries; i++)
    cout << ans[i] << endl;
}