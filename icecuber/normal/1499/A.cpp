#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

bool f(int a, int b, int x) {
  return min(a,b)+(max(a,b)-min(a,b))/2 >= x;
}

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int t;
  cin >> t;
  while (t--) {
    int n, wa, wb, a, b;
    cin >> n >> wa >> wb >> a >> b;
    cout << (f(wa,wb,a) && f(n-wa,n-wb,b) ? "YES" : "NO") << endl;
  }
}