#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int nax = 1e5;
vector<pair<int,int>> node[nax];
#define x first
#define y second

int rem[nax], sz[nax];
void szDfs(int p, int par) {
  sz[p] = 1;
  for (auto [i,c] : node[p]) {
    if (i == par || rem[i]) continue;
    szDfs(i, p);
    sz[p] += sz[i];
  }
}

int findDfs(int p, int par, int tot) {
  int ma = 0;
  for (auto [i,c] : node[p]) {
    if (i == par || rem[i]) continue;
    int ans = findDfs(i, p, tot);
    if (ans != -1) return ans;
    ma = max(ma, sz[i]);
  }
  if (ma <= tot/2 && tot-sz[p] <= tot/2) return p;
  return -1;
}

int getCentroid(int p) {
  szDfs(p, -1);
  return findDfs(p, -1, sz[p]);
}

int ops = 0;

vector<pair<int,int>> glob_best;
void build(int p, int par, int need, int balance, int depth) {
  auto pa = make_pair(balance, p);
  if (depth == glob_best.size())
    glob_best.push_back(pa);
  else
    glob_best[depth] = max(glob_best[depth], pa);
  for (auto [i,c] : node[p]) {
    if (i != par && !rem[i])
      build(i, p, need, balance+(c >= need)*2-1, depth+1);
  }
}


int n, l, r;
int ansa, ansb;
int centroid[20][nax];
int rec(int p, int need, int depth = 0) {
  //assert(depth < 20);
  pair<int,int> pp = {p, depth};
  if (!centroid[depth][p])
    centroid[depth][p] = getCentroid(p)+1;
  int root = centroid[depth][p]-1;
  assert(root != -1);

  vector<vector<pair<int,int>>> all;
  for (auto [i,c] : node[root]) {
    if (rem[i]) continue;
    glob_best.assign(1,{0,root});
    build(i, root, need, (c >= need)*2-1, 1);
    all.emplace_back(glob_best);
  }
  sort(all.begin(), all.end(), [](vector<pair<int,int>>&a, vector<pair<int,int>>&b) {return a.size() < b.size();});

  vector<pair<int,int>> prv = {{0,root}};
  for (auto&best : all) {
    int j = 0;
    deque<pair<int, pair<int,int>>> deq;
    for (int d = (int)best.size()-1; d >= 0; d--) {
      while (j < prv.size() && j+d <= r) {
	while (deq.size() && deq.back().y <= prv[j]) {
	  deq.pop_back();
	}
	deq.emplace_back(j,prv[j]);
	j++;
      }
      while (deq.size() && deq.front().x+d < l) deq.pop_front();
      if (deq.size() && deq.front().y.x+best[d].x >= 0) {
	int dist = deq.front().x+d;
	assert(dist >= l && dist <= r);
	ansa = deq.front().y.y;
	ansb = best[d].y;
	return 1;
      }
    }
    for (int d = 0; d < best.size(); d++) {
      if (d == prv.size()) prv.push_back(best[d]);
      else prv[d] = max(prv[d], best[d]);
    }
  }

  rem[root] = 1;
  for (auto [i,c] : node[root]) {
    if (!rem[i] && rec(i, need, depth+1)) {
      return 1;
    }
  }
  return 0;
}

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  cin >> n >> l >> r;
  for (int i = 1; i < n; i++) {
    int a, b, c;
    cin >> a >> b >> c;
    a--, b--;
    node[a].emplace_back(b, c);
    node[b].emplace_back(a, c);
  }

  int pass = -1, fail = 1e9+1;
  while (fail-pass > 1) {
    int mid = pass+fail>>1;
    fill_n(rem, n, 0);
    if (rec(0, mid)) {
      pass = mid;
    } else {
      fail = mid;
    }
  }
  //cerr << pass << endl;
  cout << ansa+1 << ' ' << ansb+1 << endl;
  //cout << ops <<endl;
}