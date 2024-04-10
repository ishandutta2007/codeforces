// Hydro submission #61cb0717c5d719cb7e1daa7f@1640695575881
#include <bits/stdc++.h>
using namespace std;

#define all(a) a.begin(), a.end()
#define fi first
#define se second
#define pb push_back
#define mp make_pair

using ll = long long;
using pii = pair<int, int>;
//#define int ll

const int MOD = 1000000007;

vector<int> elist[1000006], relist[1000006];
stack<int> post;
bool vis[1000006];
int SCC[1000006], sccs;

void karatsuba1(int u) {
  if (vis[u])
    return;
  vis[u] = 1;
  for (int v : elist[u])
    karatsuba1(v);
  post.push(u);
}

void karatsuba2(int u, int x) {
  if (SCC[u] != -1)
    return;
  SCC[u] = x;
  for (int v : relist[u])
    karatsuba2(v, x);
}

void ka(int n) {
  for (int i = 0; i < n; i++)
    karatsuba1(i);
  while (post.size()) {
    karatsuba2(post.top(), sccs++);
    post.pop();
  }
}

void init(int n) {
  for (int i = 0; i < n; i++) {
    elist[i].clear();
    relist[i].clear();
    vis[i] = 0;
    SCC[i] = -1;
  }
  sccs = 0;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    init(n);
    vector<int> a(n), b(n);
    for (int i = 0; i < n; i++)
      cin >> a[i];
    for (int j = 0; j < n; j++)
      cin >> b[j];
    vector<int> R(n);
    iota(all(R), 0);
    sort(all(R), [&](int i, int j) { return a[i] < a[j]; });
    for (int i = 0; i < n - 1; i++)
      elist[R[i]].push_back(R[i + 1]), relist[R[i + 1]].push_back(R[i]);
    sort(all(R), [&](int i, int j) { return b[i] < b[j]; });
    for (int i = 0; i < n - 1; i++)
      elist[R[i]].push_back(R[i + 1]), relist[R[i + 1]].push_back(R[i]);
    ka(n);
    vector<int> sccOdeg(n);
    for (int i = 0; i < n; i++)
      for (int j : elist[i])
        if (SCC[i] != SCC[j])
          sccOdeg[SCC[i]] = 1;
    int x = 0;
    for (int i = 0; i < n; i++)
      if (sccOdeg[SCC[i]] != 1)
        x = SCC[i];
    for (int i = 0; i < n; i++)
      cout << "01"[SCC[i] == x];
    cout << endl;
  }
  return 0;
}