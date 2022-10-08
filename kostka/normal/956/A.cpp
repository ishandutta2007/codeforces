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

const int MAXN = 57;

string tab[MAXN];
vector <int> G[2*MAXN];
bool odw[2*MAXN], needed[MAXN][MAXN];
vi consider;

void dfs(int v) {
  odw[v] = true;
  consider.push_back(v);
  for(auto w : G[v]) if(!odw[w]) dfs(w);
}

int main()
{
  ios_base::sync_with_stdio(0);
  int n, m;
  cin >> n >> m;
  for(int i=0; i<n; i++) {
    cin >> tab[i];
    for(int j=0; j<m; j++) {
      if(tab[i][j] == '#') {
        G[i].push_back(n+j);
        G[n+j].push_back(i);
      }
    }
  }
  for(int i=0; i<n+m; i++) {
    if(!odw[i]) {
      consider.clear();
      dfs(i);
      for(auto a : consider) for(auto b : consider) {
        if(a < n and b >= n) {
          needed[a][b-n] = true;
        }
      }
    }
  }
  for(int i=0; i<n; i++) {
    for(int j=0; j<m; j++) {
      if(needed[i][j] != (tab[i][j] == '#')) {
        puts("No");
        return 0;
      }
    }
  }
  puts("Yes");
  return 0;
}