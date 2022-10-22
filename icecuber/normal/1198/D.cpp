#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int mem[51][51][51][51];
string board[51];

int f(int x0, int y0, int x1, int y1) {
  int&memo = mem[x0][y0][x1][y1];
  if (!memo) {
    int ans = max(x1-x0,y1-y0);
    if (x1-x0 == 1 && y1-y0 == 1)
      ans = board[y0][x0] == '#';
    for (int i = x0+1; i < x1; i++) {
      ans = min(ans, f(x0,y0,i,y1)+f(i,y0,x1,y1));
    }
    for (int i = y0+1; i < y1; i++) {
      ans = min(ans, f(x0,y0,x1,i)+f(x0,i,x1,y1));
    }
    memo = ans+1;
  }
  return memo-1;
}

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int n;
  cin >> n;
  for (int i = 0; i < n; i++)
    cin >> board[i];
  cout << f(0,0,n,n) << endl;
}