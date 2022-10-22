#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

struct point {
  ll x, y;
};
point operator-(point a, point b) {
  return {a.x-b.x, a.y-b.y};
}
point operator+(point a, point b) {
  return {a.x+b.x, a.y+b.y};
}
ll operator*(point a, point b) {
  return a.x*b.x+a.y*b.y;
}
point operator*(point a, int m) {
  return {a.x*m, a.y*m};
}

int ans[100000];
struct Group {
  point sum;
  int ind;
  int mul;
  Group*cl, *cr;
  Group() {
    cl = cr = NULL;
    mul = 1;
  }
  Group(Group*l, Group*r) {
    mul = 1;
    ind = -1;
    cl = l, cr = r;
    r->sum = r->sum * -1;
    r->mul *= -1;
    sum = l->sum + r->sum;
    assert(sum * sum <= max(l->sum * l->sum, r->sum * r->sum));
  }
  int part() {
    if (sum.y < 0 || (sum.y == 0 && sum.x < 0)) {
      mul *= -1;
      sum = sum * (-1);
    }
    double ang = atan2(sum.y, sum.x) * 3 / (3.141592653589793);
    //assert(ang >= 0 && ang < 3);
    int r = ang;
    return min(r,2);
  }
  void dfs(int top = 1) {
    if (cl) {
      cl->dfs(top * mul);
      cr->dfs(top * mul);
    } else {
      assert(ind != -1);
      ans[ind] = top * mul;
    }
  }
};

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int n;
  cin >> n;
  vector<Group*> g[3];
  vector<point> inp(n);
  for (int i = 0; i < n; i++) {
    cin >> inp[i].x >> inp[i].y;
    Group*x = new Group();
    x->ind = i;
    x->sum = inp[i];
    x->mul = 1;
    int pi = x->part();
    g[pi].push_back(x);
  }
  while (1) {
    int happen = 0;
    for (int k = 0; k < 3; k++) {
      if ((int)g[k].size() >= 2) {
	Group*a = g[k].back();
	g[k].pop_back();
	Group*b = g[k].back();
	g[k].pop_back();
	Group*x = new Group(a, b);
	int pi = x->part();
	g[pi].push_back(x);
	happen = 1;
	break;
      }
    }
    if (!happen) break;
  }

  for (int i = 0; i < 8; i++) {
    point sum = {0,0};
    for (int j = 0; j < 3; j++) {
      if (g[j].size())
	sum = sum + g[j][0]->sum * ((i>>j&1)*2-1);
    }
    ll ma = 1500 * 1000;
    if (sum*sum <= ma*ma) {
      for (int j = 0; j < 3; j++) {
	if (g[j].size()) {
	  int m = ((i>>j&1)*2-1);
	  g[j][0]->sum = g[j][0]->sum * m;
	  g[j][0]->mul *= m;
	  g[j][0]->dfs();
	}
      }
      for (int j = 0; j < n; j++) cout << ans[j] << ' ';
      cout << endl;
      point sum2 = {0,0};
      for (int j = 0; j < n; j++) {
	sum2 = sum2 + inp[j] * ans[j];
      }
      assert(sum.x == sum2.x && sum.y == sum2.y);
      return 0;
    }
  }
}