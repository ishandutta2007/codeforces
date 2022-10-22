#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

string board[3];
int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  for (int i = 0; i < 3; i++)
    cin >> board[i];
  int ok = 1;
  for (int i = 0; i < 3; i++) {
    for (int j = 0; j < 3; j++) {
      if (board[i][j] != board[2-i][2-j]) ok = 0;
    }
  }
  cout << (ok ? "YES" : "NO") << endl;
}