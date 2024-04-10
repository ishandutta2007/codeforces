#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int nax = 2e5;
vector<int> node[nax], rnode[nax];

int h, w;
void addEdge(int ai, int aj, int bi, int bj) {
  assert(ai >= 0 && aj >= 0 && ai < h && aj < w);
  if (bi >= 0 && bj >= 0 && bi < h && bj < w) {
    node[ai*w+aj].push_back(bi*w+bj);
    rnode[bi*w+bj].push_back(ai*w+aj);
  }
}

ll A[2][nax], B[2][nax], t[2];

void dfs(int k, int p) {
  A[k][p] = t[k]++;
  for (int i : rnode[p]) {
    dfs(k, i);
  }
  B[k][p] = t[k];
}

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  cin >> h >> w;
  vector<string> board(h);
  for (int i = 0; i < h; i++) {
    cin >> board[i];
  }

  vector<array<int,2>> start;
  auto add_start = [&](int x, int y) {
    if ((x%w+x/w)%2) swap(x,y);
    start.push_back({x,y});
  };
  for (int i = 0; i < h; i++) {
    for (int j = 0; j < w; j++) {
      if (board[i][j] == 'U') {
	addEdge(i+1, j, i-1, j);
	add_start(i*w+j, (i+1)*w+j);
      } else if (board[i][j] == 'D') {
	addEdge(i-1, j, i+1, j);
      } else if (board[i][j] == 'R') {
	addEdge(i, j-1, i, j+1);
      } else if (board[i][j] == 'L') {
	addEdge(i, j+1, i, j-1);
	add_start(i*w+j, i*w+(j+1));
      } else assert(0);
    }
  }
  for (int k : {0,1}) {
    for (int i = 0; i < h; i++) {
      for (int j = 0; j < w; j++) {
	if ((i+j)%2 == k) {
	  if (node[i*w+j].empty())
	    dfs(k, i*w+j);
	}
      }
    }
  }

  /*
  for (int i = 0; i < h; i++) {
    for (int j = 0; j < w; j++) {
      int k = (i+j)%2;
      cout << B[k][i*w+j]-A[k][i*w+j] << ' ';
    }
    cout << endl;
  }
  */

  vector<vector<array<int,3>>> event(t[0]+1);
  for (auto [x,y] : start) {
    int x0 = A[0][x], x1 = B[0][x];
    int y0 = A[1][y], y1 = B[1][y];
    event[x0].push_back({y0, y1, 1});
    event[x1].push_back({y0, y1,-1});
    //if ((x == 8 && y == 9) || (x == 2 && y == 3))
    //  cout << x0 << ' ' << x1 << ' ' << y0 << ' ' << y1 << endl;
  }

  int M = 1;
  while (M < t[1]+1) M *= 2;
  vector<int> mi(M*2), mis(M*2, 1), off(M*2);
  for (int i = M-1; i; i--)
    mis[i] = mis[i*2]+mis[i*2+1];
  auto add = [&](int i, int v) {
    for (i += M; i > 1; i >>= 1) {
      if (i&1) {
	off[i-1] += v;
      }
      mi[i>>1] = min(mi[i]+off[i], mi[i^1]+off[i^1]);
      mis[i>>1] = mis[i]*(mi[i]+off[i] == mi[i>>1]);
      mis[i>>1]+= mis[i^1]*(mi[i^1]+off[i^1] == mi[i>>1]);
    }
  };
  auto query = [&]() {
    return M-mis[1];
  };

  //vector<int> cnt(t[1]);
  ll ans = 0;
  for (auto&e : event) {
    for (auto [y0, y1, d] : e) {
      add(y1, d);
      add(y0,-d);
      //for (int y = y0; y < y1; y++) cnt[y] += d;
    }
    ans += query();
    //for (int y = 0; y < t[1]; y++)
    //  ans += cnt[y]>0;
  }
  cout << ans << endl;
}