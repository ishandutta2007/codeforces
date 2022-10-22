#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

struct Enemy {
  int x, y, d, t, e;
};

vector<pair<int,int>> atpos[500][500];
vector<Enemy> enemy;

int w, h, n;

ll dp[500][2][500];
ll ndp[500][2][500];

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  cin >> w >> h >> n;

  for (int i = 0; i < n; i++) {
    int x, y, d, t, e;
    cin >> x >> y >> d >> t >> e;
    enemy.push_back({x,y,d,t,e});
    pair<int,int> list[4] = {{x,y},{x+d,y-d},{x+d,y},{x,y+d}};
    for (auto p : list) {
      int nx,ny;
      tie(nx,ny) = p;
      atpos[ny][nx].push_back({i,t++});
    }
  }

  fill_n((ll*)dp, 500*500*2, 1e18);
  for (int y = h-1; y >= 0; y--) {
    for (int x = w-1; x >= 0; x--) {
      for (int streak_dir : {0,1}) {
	for (int streak = 0; streak <= (streak_dir ? y : x); streak++) {
	  int xstreak =!streak_dir * streak;
	  int ystreak = streak_dir * streak;
	  ll&ans = ndp[x][streak_dir][streak];
	  if (x == w-1 && y == h-1) {
	    ans = 0;
	    continue;
	  }
	  ans = min(x+1 < w ? ndp[x+1][0][xstreak+1] : ll(1e18),
		    y+1 < h ? dp[x][1][ystreak+1] : ll(1e18));

	  for (auto pi : atpos[y][x]) {
	    Enemy&e = enemy[pi.first];
	    int t0 = pi.second;
	    if (x+y >= t0 && (x+y-t0)%4 == 0) {
	      if (t0-e.t == 3 && e.d%4 == 3 && ystreak >= e.d) continue;
	      if (t0-e.t == 2 && e.d%4 == 2 && xstreak >= e.d) continue;
	      if (t0-e.t == 2 && e.d%4 == 1 && ystreak >= e.d) continue;
	      ans += e.e;
	    }
	  }
	}
      }
    }
    for (int x = 0; x < w; x++)
      for (int streak_dir : {0,1})
	for (int streak = 0; streak <= (streak_dir ? y : x); streak++)
	  dp[x][streak_dir][streak] = ndp[x][streak_dir][streak];
  }
  cout << dp[0][0][0] << endl;
}