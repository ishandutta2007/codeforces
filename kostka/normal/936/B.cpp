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

const int MAXN = 1e5+7;
int tab[2][MAXN], deg[MAXN];
vector <int> G[MAXN];

int lisc(int n) {
  for(int i=1; i<=n; i++) {
    if(SZ(G[i]) == 0 and tab[1][i]) return i;
  }
  return 0;
}

bool cykl(int n) {
  for(int i=1; i<=n; i++) {
    if(deg[i] != 0 and (tab[0][i] or tab[1][i])) return true;
  }
  return false;
}

int main()
{
  ios_base::sync_with_stdio(0);
  int n, m;
  cin >> n >> m;
  for(int i=1; i<=n; i++) {
    int x;
    cin >> x;
    while(x--) {
      int j;
      cin >> j;
      G[i].push_back(j);
    }
  }
  int s;
  cin >> s;
  tab[0][s] = -1;
  queue <pii> Q;
  Q.emplace(0, s);
  while(!Q.empty()) {
    int c, v;
    tie(c, v) = Q.front();
    Q.pop();
    for(auto w : G[v]) {
      if(!tab[1-c][w]) {
        tab[1-c][w] = v;
        Q.emplace(1-c, w);
      }
    }
  }
  int e = lisc(n);
  if(e) {
    cout << "Win\n";
    int c = 1;
    vector <int> V;
    while(e != -1) {
      V.push_back(e);
      e = tab[c][e];
      c = 1-c;
    }
    reverse(V.begin(), V.end());
    for(auto v : V) cout << v << " ";
    cout << "\n";
    return 0;
  }
  queue <int> QQ;
  int znajdz = 0;
  for(int i=1; i<=n; i++) {
    if(tab[0][i] or tab[1][i]) {
      for(auto j : G[i]) deg[j]++;
      znajdz++;
    }
  }
  for(int i=1; i<=n; i++) if(deg[i] == 0 and (tab[0][i] or tab[1][i])) QQ.push(i);
  while(!QQ.empty()) {
    int v = QQ.front();
    znajdz--;
    QQ.pop();
    for(auto w : G[v]) {
      deg[w]--;
      if(deg[w] == 0) QQ.push(w);
    }
  }
  if(znajdz != 0) cout << "Draw\n";
  else cout << "Lose\n";
  return 0;
}