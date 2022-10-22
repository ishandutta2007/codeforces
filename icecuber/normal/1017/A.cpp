#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int n;
  cin >> n;
  int id = 0;
  auto read = [&]() {
    int a, b, c, d;
    cin >> a >> b >> c >> d;
    return make_pair(a+b+c+d, -id++);
  };
  auto p = read();
  int ans = 1;
  for (int i = 1; i < n; i++) {
    if (read() > p) ans++;
  }
  cout << ans << endl;
}