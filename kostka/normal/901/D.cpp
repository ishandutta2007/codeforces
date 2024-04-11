//Bartek Kostka
//  You are not prepared!

#include "bits/stdc++.h"

using namespace std;

#define x first
#define y second
#define SZ(x) int(x.size())
#define ll long long
#define pii pair <int, int>
#define vi vector <int>

const int MAXN = 100007;

int n, kolor[MAXN];
ll weights[MAXN], kraw[MAXN];
pii pre[MAXN];
vector <pii> G[MAXN], cykl;
bool odw[MAXN];

int dfs(int v, int kol = 1) {
  kolor[v] = kol;
  for(auto ele : G[v]) {
    int w, ix;
    tie(w, ix) = ele;
    if(w == pre[v].first) continue;
    if(kolor[w]==0) {
      pre[w] = {v, ix};
      int r = dfs(w, 3-kol);
      if(r != -1) return r;
    } else if(kolor[w] == kolor[v]) {
      int s = v;
      do {
        cykl.emplace_back(s, pre[s].second);
        s = pre[s].first;
      } while(s != w);
      cykl.push_back({w, ix});
      return w;
    }
  }
  return -1;
}

void foo(int v, int poprz = -1) {
  odw[v] = true;
  for(auto ele : G[v]) {
    int w, ix;
    tie(w, ix) = ele;
    if(!odw[w]) {
      foo(w, ix);
      weights[v] -= kraw[ix];
    }
  }
  if(poprz != -1) {
    kraw[poprz] += weights[v];
    weights[v] = 0;
  }
}

int main()
{
  ios_base::sync_with_stdio(0);
  int m;
  cin >> n >> m;
  for(int i=1; i<=n; i++) cin >> weights[i];
  for(int i=1; i<=m; i++) {
    int a, b;
    cin >> a >> b;
    G[a].emplace_back(b, i);
    G[b].emplace_back(a, i);
  }
  int c = dfs(1);
  if(c == -1) {
    long long suma[3] = {0};
    for(int i=1; i<=n; i++) suma[kolor[i]] += weights[i];
    if(suma[1] == suma[2]) {
      cout << "YES\n";
      foo(1);
      for(int i=1; i<=m; i++) {
        cout << kraw[i] << "\n";
      }
    } else {
      cout << "NO\n";
    }
  } else {
    foo(c);
    //cerr << "C " << c << " " << weights[c] << "\n";
    rotate(cykl.begin(), cykl.end()-1, cykl.end());
    // for(auto c : cykl) {
    //   cerr << c.first << " " << c.second << "\n";
    // }
    for(int i=0; i<SZ(cykl); i++) {
       kraw[cykl[i].second] += ((i%2) ? -1 : 1)*weights[c]/2;
    }
    cout << "YES\n";
    for(int i=1; i<=m; i++) {
      cout << kraw[i] << "\n";
    }
  }

  return 0;
}