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

const int MAXN = 2007;
char tab[MAXN][MAXN];
int freed[MAXN][MAXN], freer[MAXN][MAXN];

int main()
{
  ios_base::sync_with_stdio(0);
  int n, m, k;
  cin >> n >> m >> k;
  for(int i=0; i<n; i++) cin >> tab[i];
  if(k == 1) {
    int res = 0;
    for(int i=0; i<n; i++)
      for(int j=0; j<m; j++)
        if(tab[i][j] == '.') res++;
    cout << res << "\n";
    return 0;
  }
  for(int i=0; i<m; i++) {
    if(tab[0][i] == '.') freed[0][i] = 1;
  }
  for(int i=1; i<n; i++) {
    for(int j=0; j<m; j++) {
      if(tab[i][j] == '.') freed[i][j] = freed[i-1][j] + 1;
    }
  }
  for(int i=0; i<n; i++) {
    if(tab[i][0] == '.') freer[i][0] = 1;
  }
  for(int i=0; i<n; i++) {
    for(int j=1; j<m; j++) {
      if(tab[i][j] == '.') freer[i][j] = freer[i][j-1] + 1;
    }
  }
  int res = 0;
  for(int i=0; i<n; i++) {
    for(int j=0; j<m; j++) {
      if(freed[i][j] >= k) res++;
      if(freer[i][j] >= k) res++;
    }
  }
  cout << res << "\n";
  return 0;
}