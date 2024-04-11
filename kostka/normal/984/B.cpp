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

int dx[] = {-1, -1, -1, 0, 0, 1, 1, 1};
int dy[] = {-1, 0, 1, -1, 1, -1, 0, 1};

int main()
{
  ios_base::sync_with_stdio(0);
  int n, m;
  cin >> n >> m;
  auto onboard = [&](int a, int b) -> bool {
    return 0 <= a and a < n and 0 <= b and b < m;
  };
  vector <string> tab(n);
  for(int i=0; i<n; i++) cin >> tab[i];
  for(int i=0; i<n; i++) {
    for(int j=0; j<m; j++) {
      if(tab[i][j] != '*') {
        if(tab[i][j] == '.') tab[i][j] = '0';
        int count = 0;
        for(int d=0; d<8; d++) {
          int ni = i+dx[d];
          int nj = j+dy[d];
          if(onboard(ni, nj) and tab[ni][nj] == '*') count++;
        }
        if(count != tab[i][j] - '0') {
          cout << "NO\n";
          return 0;
        }
      }
    }
  }
  cout << "YES\n";
  return 0;
}