#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int n, A, B;
int hp[10];

int mem[10][17][17][17];
int shoot[10][17][17][17];
vector<int> par[10][17][17][17];

int f(int p, int a, int b, int c) {
  int&memo = mem[p][a][b][c];
  if (!memo) {
    int r = 1e9;
    if (a+b+c) {
      r = f(p,max(a-B,0),max(b-A,0),max(c-B,0))+1;
      shoot[p][a][b][c] = p+2;
      par[p][a][b][c] = {p,max(a-B,0),max(b-A,0),max(c-B,0)};
    }
    else if (p == n-3) {
      r = 0;
      par[p][a][b][c] = {-1,-1,-1,-1};
    }
    if (p < n-3 && a == 0) {
      int v = f(p+1,b,c,hp[p+3]);
      if (v < r) {
	r = v;
	shoot[p][a][b][c] = 0;
	par[p][a][b][c] = {p+1,b,c,hp[p+3]};
      }
    }
    memo = r+1;
  }
  return memo-1;
}

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  cin >> n >> A >> B;
  for (int i = 0; i < n; i++) {
    cin >> hp[i];
    hp[i]++;
  }
  cout << f(0,hp[0],hp[1],hp[2]) << endl;
  vector<int> p = {0,hp[0],hp[1],hp[2]};
  while (p[0] > -1) {
    int s = shoot[p[0]][p[1]][p[2]][p[3]];
    if (s) cout << s << ' ';
    p = par[p[0]][p[1]][p[2]][p[3]];
  }
  cout << endl;
}