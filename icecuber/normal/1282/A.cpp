#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int t;
  cin >> t;
  while (t--) {
    int a, b, c, rad;
    cin >> a >> b >> c >> rad;
    if (a > b) swap(a,b);
    int l = c-rad, r = c+rad;
    cout << min(b,l)-min(a,l) + max(b,r)-max(a,r) << endl;
  }
}