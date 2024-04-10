#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

struct point {
  ll x, y;
  void reduce() {
    ll g = gcd(abs(x),abs(y));
    if (g) x /= g, y /= g;
  }
};

bool operator<(point a, point b) {
  return make_pair(a.x,a.y) < make_pair(b.x,b.y);
}

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int n, k;
  cin >> n >> k;
  map<point,vector<double>> line;
  map<pair<point,double>,int> id;
  for (int i = 0; i < n; i++) {
    point p;
    cin >> p.x >> p.y;
    double d = sqrt(p.x*p.x+p.y*p.y);
    p.reduce();
    id[{p,d}] = i+1;
    line[p].push_back(d);
  }

  vector<int> open;
  vector<vector<int>> node(n);
  vector<double> scores;
  int cur = -1;
  auto reset = [&]() {
    cur = -1;
  };
  auto add = [&](double s) {
    if (cur != -1)
      node[cur].push_back(scores.size());
    else
      open.push_back(scores.size());
    cur = scores.size();
    scores.push_back(s);
  };

  for (auto [p,v] : line) {
    sort(v.rbegin(), v.rend());
    int i = 0;
    reset();
    for (double d : v) {
      if (k <= (i*2+1)) break;
      add(d*(k-(i*2+1)));
      //cout << id[{p,d}] << ' ' << d << ' ' << d*(k-(i*2+1)) << endl;
      i++;
    }
    reverse(v.begin(), v.end());
    int j = i;
    double acc = 0;
    for (double d : v) {
      if (j == (int)v.size()) break;
      add(d*(k-(i*2+1))-2*acc);
      acc += d;
      j++;
    }
  }
  //cout << scores.size() << ' ' << n << endl;
  //assert((int)scores.size() == n);
  priority_queue<pair<double,int>> pq;
  for (int i : open) {
    pq.push({scores[i], i});
  }
  vector<int> done(n);
  double ans = 0, used = 0;
  while (pq.size()) {
    auto [s,i] = pq.top();
    pq.pop();
    if (done[i]++) continue;
    ans += s;
    used++;
    for (int j : node[i])
      pq.push({scores[j], j});
    if (used == k) break;
  }
  cout << setprecision(20) << ans << endl;
}