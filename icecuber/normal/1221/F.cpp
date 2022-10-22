#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

#define x first
#define y second

struct point {
  int x, y;
  ll cost;
};

bool operator<(point a, point b) {
  return make_tuple(a.x,a.y,a.cost) < make_tuple(b.x,b.y,b.cost);
}

point p[500000];

const int n = 1<<19;

pair<ll,int> ma[n*2];
ll lazy[n*2];

void add(int i, ll v) {
  for (i += n; i > 1; i >>= 1) {
    if (i&1) {
      lazy[i-1] += v;
    }
    ma[i>>1] = max(make_pair(ma[i].x+lazy[i], ma[i].y),
		   make_pair(ma[i^1].x+lazy[i^1], ma[i^1].y));
  }
}

pair<ll,int> getMax(int i) {
  pair<ll,int> r(-1e18,-1);
  for (i += n; i > 1; i >>= 1) {
    r.x += lazy[i];
    if (i&1) {
      r = max(r, make_pair(ma[i-1].x+lazy[i-1], ma[i-1].y));
    }
  }
  return r;
}

void print(int m) {
  for (int i = 0; i < m; i++) {
    ll v = 0;
    for (int j = i+n; j; j >>= 1) {
      v += lazy[j];
    }
    cout << v << ' ';
  }
  cout << endl;
}

int main() {
  ios::sync_with_stdio(0); cin.tie(0);

  int n;
  cin >> n;
  map<int,int> comp;
  for (int i = 0; i < n; i++) {
    cin >> p[i].x >> p[i].y >> p[i].cost;
    if (p[i].x < p[i].y) swap(p[i].x,p[i].y);
    comp[p[i].y];
  }

  for (int i = 0; i < n; i++) {
    ma[i+(1<<19)].y = i;
  }

  int c = 0;
  vector<int> y;
  for (auto&i : comp) {
    y.push_back(i.first);
    add(c+1, i.first);
    add(c, -i.first);
    i.second = c++;
  }

  sort(p, p+n);

  tuple<ll,int,int> ans(0,2e9,2e9);
  int j = 0;
  for (int i = 0; i < n; i++) {
    add(comp[p[i].y]+1, p[i].cost);
    if (i+1 < n && p[i].x == p[i+1].x) continue;

    //print(c);
    while (j < c && y[j] <= p[i].x) j++;
    auto score = getMax(j);
    //cout << score.first << ' ' << score.second << endl;
    score.first -= p[i].x;
    ans = max(ans, make_tuple(score.first, y[score.second], p[i].x));
  }
  {
    ll score;
    int l, r;
    tie(score,l,r) = ans;
    cout << score << endl;
    cout << l << ' ' << l << ' ' << r << ' ' << r << endl;
  }
}