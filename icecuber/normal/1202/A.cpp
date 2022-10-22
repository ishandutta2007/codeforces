#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int t;
  cin >> t;
  while (t--) {
    string x, y;
    cin >> x >> y;
    int b = 0;
    while (y[y.size()-1-b] != '1') b++;
    int a = b;
    while (x[x.size()-1-a] != '1') a++;
    cout << a-b << endl;
  }
}