#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int read() {
  int n;
  cin >> n;
  int ma = 0;
  for (int i = 0; i < n; i++) {
    int a;
    cin >> a;
    ma = max(ma, a);
  }
  return ma;
}
int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int a = read();
  int b = read();
  cout << a << ' ' << b << endl;
}