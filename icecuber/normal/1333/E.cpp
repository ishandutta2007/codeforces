#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int nax = 500;

int board[nax][nax];

const int dx[] = {-1,1,0,0,-1,-1,1,1};
const int dy[] = {0,0,-1,1,-1,1,-1,1};

int done[nax][nax];

int n;
int solve(int dirs) {
  set<tuple<int,int,int>> left;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      left.emplace(board[i][j], i, j);
    }
  }
  fill_n((int*)done, nax*nax, 0);

  int y = -1, x = -1;
  int ans = 0;
  for (int it = 0; it < n*n; it++) {
    if (x == -1) {
      int v;
      tie(v,y,x) = *left.begin();
      left.erase(left.begin());
    }
    assert(!done[y][x]);
    done[y][x] = 1;
    tuple<int,int,int> best = {1e9,-1,-1};
    for (int d = 0; d < dirs; d++) {
      int nx = x, ny = y;
      while (nx >= 0 && ny >= 0 && nx < n && ny < n) {
	if (!done[ny][nx]) {
	  best = min(best, make_tuple(board[ny][nx], ny, nx));
	}
	nx += dx[d];
	ny += dy[d];
      }
    }
    if (get<0>(best) == 1e9) {
      x = -1;
      ans++;
    } else {
      int v;
      tie(v,y,x) = best;
      left.erase(best);
    }
  }
  return ans;
}

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  cin >> n;
  if (n <= 2) {
    cout << -1 << endl;
    return 0;
  }
  int its = 0;
  while (1) {
    if (n < 5) {
      vector<int> perm;
      for (int i = 0; i < n*n; i++) perm.push_back(i);
      random_shuffle(perm.begin(), perm.end());
      for (int i = 0; i < n; i++) {
	for (int j = 0; j < n; j++) {
	  board[(i+j)%n][j] = perm[i*n+j];
	}
      }
    } else if (n%2 == 0) {
      for (int i = 0; i < n; i++) {
	for (int j = 0; j < n; j++) {
	  board[(i+j)%n][j] = i*n+j;
	}
      }
      break;
    } else {
      int s = 0;
      for (int j = 0; j < n; j++) board[0][j] = s++;
      for (int i = 1; i < n; i++) board[i][n-1] = s++;
      for (int i = 1; i < n; i++) {
	for (int j = 0; j < n-1; j++) {
	  board[1+(i-1+j)%(n-1)][j] = s++;
	}
      }
      break;
    }
    //break;
    int a = solve(4);
    int b = solve(8);
    //cout << a << ' ' << b << endl;
    if (a < b) break;
    //if (its++ == 10) return 0;
  }
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      cout << board[i][j]+1 << ' ';
    }
    cout << endl;
  }
}