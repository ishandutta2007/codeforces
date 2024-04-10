#include <algorithm>
#include <cassert>
#include <cstring>
#include <iostream>
#include <cstdio>

using namespace std;

#define FOR(i, a, b) for (int i = (a); i < (b); ++i)
#define REP(i, n) FOR(i, 0, n)
#define TRACE(x) cout << #x << " = " << x << endl
#define _ << " _ " <<

typedef long long llint;

const int MAX = 444;

int deg[MAX];
int d[MAX][MAX];
int n, m;

void next(vector<int>& v, vector<pair<int, double>>& w) {
  static double prob[MAX];
  REP(i, n) prob[i] = 0;
  for (int x: v) {
    REP(j, n) {
      if (d[x][j] == 1) prob[j] += 1.0 / deg[x];
    }
  }
  w.clear();
  REP(i, n) if (prob[i] > 0) w.push_back({i, prob[i] / v.size()});
}

vector<pair<int, double>> v;

double solve(vector<int>& w) {
  next(w, v);
  
  double tot = 0;
  for (auto& p: v) tot += p.second;
  
  double ans = 0;
  REP(i, n) {
    static int bio[MAX];
    static double mx[MAX];
    static int cookie;

    cookie++;
    double score = 0;
    for (auto& p: v) {
      int x = p.first;
      int q = d[i][x];
      if (bio[q] != cookie) {
        bio[q] = cookie;
        mx[q] = 0;
      }
      score -= mx[q];
      mx[q] = max(mx[q], p.second);
      score += mx[q];
    }

    ans = max(ans, score/tot);
  }
  return ans;
}

int main(void) {
  scanf("%d %d", &n, &m);
  REP(i, n) REP(j, n) d[i][j] = i == j ? 0 : n;
  REP(i, m) {
    int a, b;
    scanf("%d %d", &a, &b); --a, --b;
    d[a][b] = d[b][a] = 1;
    deg[a]++, deg[b]++;
  }
  REP(k, n) REP(i, n) REP(j, n)
    d[i][j] = min(d[i][j], d[i][k] + d[k][j]);

  double ans = 0;
  REP(i, n) {
    vector<vector<int>> w(n);
    REP(j, n) w[d[i][j]].push_back(j);
    double score = 0;
    vector<pair<int, double>> nxt;
    REP(j, n)
      if (w[j].size()) {
        score += w[j].size()*1.0 / n * max(1.0 / w[j].size(), solve(w[j]));
      }

    ans = max(ans, score);
  }

  printf("%.10lf\n", ans);
  return 0;
}