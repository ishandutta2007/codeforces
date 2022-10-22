#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  vector<int> l;
  int g = 0;
  for (int i = 0; i < 4; i++) {
    cout << "? " << 1 << ' ' << i+2 << endl;
    int n;
    cin >> n;
    g = __gcd(g, n);
    l.push_back(n);
  }
  while ((g%5 == 0 || g%23 == 0) && g%2 == 0) g /= 2;
  int prod = 4*8*15*16*23*42/g;
  cout << "! " << g << ' ';
  for (int i = 0; i < 4; i++) {
    cout << l[i]/g << ' ';
    prod /= l[i]/g;
  }
  cout << prod << endl;
}