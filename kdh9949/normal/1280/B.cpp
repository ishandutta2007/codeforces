#include <bits/stdc++.h>
using namespace std;

const int N = 65;

int n, m;
char b[N][N];

int td(){
  for(int i = 1; i <= n; i++) for(int j = 1; j <= m; j++) if(b[i][j] != 'A') return 0;
  return 1;
}

int rd(int x){
  int t = 0;
  for(int i = 1; i <= m; i++) t += b[x][i] == 'A';
  return (t == m);
}

int cd(int x){
  int t = 0;
  for(int i = 1; i <= n; i++) t += b[i][x] == 'A';
  return (t == n);
}

int xd(int x, int y){
  return (b[x][y] == 'A');
}

string solve(){
  cin >> n >> m;
  for(int i = 1; i <= n; i++) cin >> b[i]+1;
  if(td()) return "0";
  if(rd(1) || rd(n) || cd(1) || cd(m)) return "1";
  for(int i = 1; i <= n; i++) if(rd(i)) return "2";
  for(int i = 1; i <= m; i++) if(cd(i)) return "2";
  if(xd(1, 1) || xd(1, m) || xd(n, 1) || xd(n, m)) return "2";
  for(int i = 1; i <= n; i++) if(xd(i, 1) || xd(i, m)) return "3";
  for(int i = 1; i <= m; i++) if(xd(1, i) || xd(n, i)) return "3";
  for(int i = 1; i <= n; i++) for(int j = 1; j <= m; j++) if(xd(i, j)) return "4";
  return "MORTAL";
}

int main(){
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  
  int t;
  cin >> t;
  while(t--) cout << solve() << '\n';
}