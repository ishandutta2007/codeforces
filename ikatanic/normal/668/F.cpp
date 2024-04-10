#include <algorithm>
#include <cassert>
#include <cstring>
#include <iostream>
#include <cstdio>
#include <map>

using namespace std;

#define FOR(i, a, b) for (int i = (a); i < (b); ++i)
#define REP(i, n) FOR(i, 0, n)
#define TRACE(x) cout << #x << " = " << x << endl
#define _ << " _ " <<

typedef long long llint;

const int MAXN = 10010;
const int mod = 1e9 + 7;

inline int add(int a, int b) {
  return a+b >= mod ? a+b-mod : a+b;
}

inline int sub(int a, int b) {
  return a >= b ? a-b : a-b+mod;
}

inline int mul(int a, int b) {
  return llint(a)*b % mod;
}

struct Node {
  vector<int> v;
  vector<int> E;
} a[MAXN];

int n;

map<vector<int>, int> nodeId;
map<vector<int>, int> f[MAXN];

vector<int> merge(vector<int> v, int x, int y) {
  int cx = min(v[x], v[y]);
  int cy = max(v[x], v[y]);
  for (int& w: v) 
    if (w == cy) w = cx;
  return v;
}

bool connected(const vector<int>& v, int x, int y) {
  return v[x] == v[y];
}

int main(void) {
  int m, k;
  scanf("%d %d", &m, &k);
  
  n = 0;
  REP(i, k) {
    vector<int> v;
    REP(j, i + 1) v.push_back(j);
    nodeId[v] = n;
    if (n > 0) a[n-1].E.push_back(n);
    a[n++].v = v;
  }
  
  FOR(i, k, m) {
    vector<int> v(k);
    REP(j, k) {
      scanf("%d", &v[j]);
      --v[j];
    }
    sort(v.begin(), v.end());     
    int par = nodeId[v];

    v.push_back(i);
    REP(j, k) {
      vector<int> w = v;
      w.erase(w.begin() + j);
      nodeId[w] = n;
    }

    a[par].E.push_back(n);
    a[n++].v = v;
  }

  for (int x = n-1; x >= 0; --x) {
    map<vector<int>, int> cur;
    int m = a[x].v.size();
    REP(s, 1<<(m-1)) {
      vector<int> c;
      REP(i, m) c.push_back(i);
      REP(i, m-1) if (s & (1<<i)) c = merge(c, i, m-1);
      cur[c]++;
    }

    static int idx[MAXN];
    REP(i, m) idx[a[x].v[i]] = i;

    for (int y: a[x].E) {
      map<vector<int>, int> next;
      for (auto& px: cur) {
        for (auto& py: f[y]) {
          bool ok = true;
          auto c = px.first;
          REP(i, (int)py.first.size())
            if (py.first[i] != i) {
              if (connected(c, idx[a[y].v[py.first[i]]], idx[a[y].v[i]])) { 
                ok = false; 
                break; 
              } else {
                c = merge(c, idx[a[y].v[py.first[i]]], idx[a[y].v[i]]);
              }
            }
          if (ok) {
            next[c] = add(next[c], mul(px.second, py.second));
          }
        }
      }
      cur = next;
    }

    for (auto& px: cur) {
      if (x > 0 && px.first[m-1] == m-1) continue;
      auto c = px.first;
      c.pop_back();
      f[x][c] = add(f[x][c], px.second);
    }
  }

  printf("%d\n", f[0][{}]);
  return 0;
}