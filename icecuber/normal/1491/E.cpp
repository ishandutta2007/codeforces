#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int nax = 2e5+10;
int fib[nax];
int sz[nax], parent[nax];
vector<int> node[nax];

int rec(vector<int> vlist) {
  int n = vlist.size();
  if (n == 1) return 1;

  for (int i : vlist) sz[i] = 0;

  function<void(int, int)> dfs =
    [&](int p, int par) {
      parent[p] = par;
      sz[p] = 1;
      for (int i : node[p]) {
        if (i == par) continue;
        dfs(i, p);
        sz[p] += sz[i];
      }
    };

  dfs(vlist[0], -1);

  function<void(vector<int>&,int,int)> listdfs =
    [&](vector<int>&v, int p, int par) {
      v.push_back(p);
      for (int i : node[p]) {
        if (i != par) {
          listdfs(v, i, p);
        }
      }
    };

  for (int i : vlist) {
    if (fib[sz[i]] && fib[n-sz[i]]) {
      int a = i;
      int b = parent[i];
      node[a].erase(find(node[a].begin(), node[a].end(), b));
      node[b].erase(find(node[b].begin(), node[b].end(), a));
      vector<int> va, vb;
      listdfs(va, a, -1);
      listdfs(vb, b, -1);
      return rec(va) && rec(vb);
    }
  }
  return 0;
}

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int n;
  cin >> n;
  for (int i = 1; i < n; i++) {
    int a, b;
    cin >> a >> b;
    a--, b--;
    node[a].push_back(b);
    node[b].push_back(a);
  }
  {
    int a = 1, b = 2;
    fib[a] = 1;
    while (b < nax) {
      fib[b] = 1;
      a = a+b;
      swap(a,b);
    }
  }
  vector<int> all;
  for (int i = 0; i < n; i++) all.push_back(i);
  cout << (fib[n] && rec(all) ? "YES" : "NO") << endl;
}