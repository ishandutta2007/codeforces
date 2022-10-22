#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int query(int p) {
  cout << "? " << p+1 << endl;
  int ans;
  cin >> ans;
  assert(ans);
  //cerr << p+1 << ": " << ans << endl;
  return ans-1;
}

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int T;
  cin >> T;
  while (T--) {
    int n;
    cin >> n;
    vector<int> p(n,-1);
    for (int i = 0; i < n; i++) {
      if (p[i] != -1) continue;
      int start = query(i);
      int last = start;
      int a;
      while ((a = query(i)) != start) {
        p[last] = a;
        last = a;
      }
      p[last] = a;
    }
    cout << "!";
    for (int i : p) cout << ' ' << i+1;
    cout << endl;
  }
}