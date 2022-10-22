#include <iostream>
#include <set>
#include <vector>
#include <map>

using namespace std;

int par[1000000];
vector<int> child[1000000];
int c[1000000];

int n, k;
map<int, int> dfs(int p, int d, int&rsum) {
  map<int, int> r;
  rsum = 0;
  for (int i : child[p]) {
    int sum = 0;
    map<int,int> m = dfs(i, d+1, sum);
    if (m.size() > r.size()) swap(r,m);
    for (auto p : m)
      r[p.first] += p.second;
    rsum += sum;
  }
  if (child[p].empty()) {
    r[d]++;
    rsum = 1;
  }
  while (r.size() && r.begin()->first >= d+k) {
    rsum -= r.begin()->second;
    r.erase(r.begin());
  }
  c[p] = rsum;
  return r;
}

int f(int p) {
  if (child[p].empty()) return 1;
  int r = 0, ma = -1e9;
  for (int i : child[p]) {
    r += c[i];
    ma = max(ma, f(i)-c[i]);
  }
  return r+ma;
}

int main() {
  cin >> n >> k;
  for (int i = 1; i < n; i++) {
    cin >> par[i];
    child[--par[i]].push_back(i);
  }
  int rsum;
  dfs(0, 0, rsum);
  //cout << rsum << endl;
  cout << f(0) << endl;
  //for (int i = 0; i < n; i++)
  //  cout << i+1 << ' ' << c[i]  <<endl;
}