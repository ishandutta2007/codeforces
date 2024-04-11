//Bartek Kostka
//  You are not prepared!

#include "bits/stdc++.h"

using namespace std;

#define x first
#define y second
#define SZ(x) int(x.size())

const int MAXN = 300007;
vector <int> G[MAXN];
vector <pair <int, int> > O;
bool odw[MAXN];
int nex[MAXN], prz[MAXN], poz[MAXN];
long long res[MAXN];

pair <int, int> go(int p, int q) {
  int maxi = p;
  int mini = p;
  while(p != q) {
    maxi = max(maxi, q);
    mini = min(mini, q);
    q = prz[q];
  }
  return {maxi, mini};
}

void dfs(int v) { //, int prz = -1) {
  odw[v] = true;
  for(auto w : G[v]) {
    if(w == prz[v]) continue;
    if(odw[w] == false) {
      prz[w] = v;
      poz[w] = poz[v] + 1;
      dfs(w);
    } else if(poz[w] > poz[v]){
      auto x = go(v, w);
      nex[x.second] = x.first - 1;
    }
  }
}

long long sum(int x) {
  return 1LL * x * (x+1) / 2;
}

int main()
{
  ios_base::sync_with_stdio(0);
  int n, m;
  cin >> n >> m;
  for(int i=0; i<m; i++) {
    int a, b;
    cin >> a >> b;
    G[a].push_back(b);
    G[b].push_back(a);
  }
  for(int i=1; i<=n; i++) nex[i] = n;
  for(int i=1; i<=n; i++) if(!odw[i]) {
    prz[i] = i;
    dfs(i);
  }
  for(int i=n-1; i>=1; i--) nex[i] = min(nex[i], nex[i+1]);
  //for(int i=1; i<=n; i++) cerr << nex[i] << " ";
  for(int i=1; i<=n; i++) res[i] = res[i-1] + nex[i] - i + 1;
  int q;
  cin >> q;
  while(q--) {
    int l, r;
    cin >> l >> r;
    int p = l-1, k = r+1;
    while(k - p > 1) {
      int med = (p+k)/2;
      if(r < nex[med]) k = med;
      else p = med;
    }
    cout << res[p] - res[l-1] + sum(r-p) << "\n";
  }
  return 0;
}