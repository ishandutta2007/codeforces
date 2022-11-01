//============================================================================
// Name        : D.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;



typedef pair<int, int> pii;

vector< vector<int> > e;
vector<char> been;
vector<int> order;

void dfs(int p) {
  if (been[p])
    return;
  been[p] =true;
  for (auto i: e[p])
    dfs(i);
  order.push_back(p);
}

int main() {
  ios::sync_with_stdio(false);
  int n, m;
  cin >> n >> m;
  vector<pii> edges(m);
  for (int i = 0; i < m; ++i) {
    cin >> edges[i].first >> edges[i].second;
    --edges[i].first;
    --edges[i].second;
  }
  int l = 0, r = m + 1;
  e.assign(n, vector<int>());
  while (r - l != 1) {
    int mid = (l + r) / 2;
    for (int i = 0; i < n; ++i)
      e[i].clear();
    for (int i = 0; i < mid; ++i) {
      e[edges[i].first].push_back(edges[i].second);
    }
    for (int i = 0; i < n; ++i) {
      sort(e[i].begin(), e[i].end());
    }
    been.assign(n, 0);
    order.clear();
    for (int i = 0; i < n; ++i) {
      dfs(i);
    }
    bool is_good = true;
    for (int i = 0; i < n - 1; ++i) {
      const auto& ec = e[order[i+1]];
      if (!binary_search(ec.begin(), ec.end(), order[i])) {
        is_good = false;
        break;
      }
    }
    if (is_good) {
      r = mid;
    } else {
      l = mid;
    }
  }
  if (r == m + 1) {
    r = -1;
  }
  cout << r << endl;
  return 0;
}