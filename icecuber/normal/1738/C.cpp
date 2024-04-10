#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int mem[101][101][2];
bool win(int a, int b, int goal) {
  if (a<0 || b<0) return 1;
  if (a+b == 0) return (goal == 0);
  int&memo = mem[a][b][goal];
  if (!memo) {
    memo = 1+(!win(a-1,b, goal^b%2^1) || !win(a,b-1, goal^b%2^1));
  }
  return memo-1;
}

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int T;
  cin >> T;
  while (T--) {
    int c[2] = {};
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
      int a;
      cin >> a;
      c[a&1]++;
    }
    cout << (win(c[0],c[1],0) ? "Alice" : "Bob") << endl;
  }
}