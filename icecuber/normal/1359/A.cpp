#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int t;
  cin >> t;
  while (t--) {
    int n, m, k;
    cin >> n >> m >> k;
    int e = n/k;
    int x = min(m,e);
    int y = (m-x+k-1-1)/(k-1);
    cout << x-y << endl;
  }
}