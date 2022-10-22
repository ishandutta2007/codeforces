#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int t;
  cin >> t;
  while (t--) {
    int n, na, nb;
    cin >> n >> na >> nb;
    int maa = 0, a;
    for (int i = 0; i < na; i++) {
      cin >> a;
      maa = max(maa, a);
    }
    for (int i = 0; i < nb; i++) cin >> a;
    cout << (maa == n ? "YES" : "NO") << endl;
  }
}