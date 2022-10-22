#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

map<pair<int,int>,int> mem;
int n;
int win(int a, int b) {
  if (pow(a,b) >= n) return 1;
  if (b == 1 && (double)a*a >= n) return (n-a)%2==0;
  if (b > 30) return -1;
  int&memo = mem[{a,b}];
  if (!memo) {
    int wa = win(a+1,b), wb = win(a,b+1);
    if (!wa || !wb)
      memo = 1;
    else if (wa == -1 || wb == -1)
      memo = -1;
    else
      memo = 0;
    memo += 10;
  }
  return memo-10;
}

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int a, b;
  cin >> a >> b >> n;
  int w = win(a,b);
  if (w == 1) cout << "Masha" << endl;
  else if (w == -1) cout << "Missing" << endl;
  else cout << "Stas" << endl;
}