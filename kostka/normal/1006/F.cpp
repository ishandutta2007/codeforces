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

const int MAXN = 25;
ll tab[MAXN][MAXN];
int n, m;
map<ll, int> M[2][MAXN][MAXN];

void go(int d, int a, int b, int moves, ll x = 0) {
  if(not(0 <= a and a < n and 0 <= b and b < m)) return;
  x ^= tab[a][b];
  if(moves == 0) {
    M[d][a][b][x]++;
    return;
  }
  go(d, a + (d == 0 ? 1 : -1), b, moves-1, x);
  go(d, a, b + (d == 0 ? 1 : -1), moves-1, x);
}

int main()
{
  ios_base::sync_with_stdio(0);
  ll k;
  cin >> n >> m >> k;
  for(int i=0; i<n; i++) {
    for(int j=0; j<m; j++) cin >> tab[i][j];
  }
  go(0, 0, 0, (n+m-2)/2);
  go(1, n-1, m-1, (n+m-1)/2);
  ll ret = 0;
  for(int i=0; i<n; i++) {
    for(int j=0; j<m; j++) {
      for(auto ele : M[0][i][j]) {
        if(M[1][i][j].find(ele.x ^ k ^ tab[i][j]) != M[1][i][j].end()) {
          ret += 1LL * ele.y * M[1][i][j][ele.x ^ k ^ tab[i][j]];
        }
      }
    }
  }
  cout << ret << "\n";
  return 0;
}