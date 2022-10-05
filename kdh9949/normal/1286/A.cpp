#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
#define x first
#define y second

const int N = 105;

int n, o, e, a[N], d[N][N][N][2];

int main(){
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  cin >> n;
  for(int i = 1; i <= n; i++){
    cin >> a[i];
  }
  o = (n + 1) / 2;
  e = n / 2;
  memset(d, 0x3f, sizeof(d));
  int r = int(1e9);
  d[0][o][e][0] = d[0][o][e][1] = 0;
  for(int i = 1; i <= n; i++){
    for(int j = 0; j <= o; j++){
      for(int k = 0; k <= e; k++){
        if(!a[i] || a[i] % 2 == 0) d[i][j][k][0] = min(d[i][j][k][0],
          min(d[i-1][j][k+1][0], d[i-1][j][k+1][1] + 1));
        if(!a[i] || a[i] % 2 == 1) d[i][j][k][1] = min(d[i][j][k][1],
          min(d[i-1][j+1][k][1], d[i-1][j+1][k][0] + 1));
        if(i == n) r = min(r, min(d[i][j][k][0], d[i][j][k][1]));
      }
    }
  }
  cout << r << '\n';
  return 0;
}