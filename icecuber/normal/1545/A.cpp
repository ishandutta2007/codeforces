#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int t;
  cin >> t;
  while (t--) {
    map<int,array<int,2>> cnt;
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
      int a;
      cin >> a;
      cnt[a][i%2]++;
    }
    int ok = 1;
    int pos = 0;
    for (auto [a,c] : cnt) {
      int tot = c[0]+c[1];
      ok &= (tot/2 == c[1-pos%2]);
      ok &= ((tot+1)/2 == c[pos%2]);
      pos += tot;
    }
    cout << (ok ? "YES" : "NO") << endl;
  }
}