#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int T;
  cin >> T;
  while (T--) {
    int n;
    cin >> n;
    vector<int> a(n), b(n);
    ll sum = 0, sum2 = 0;
    for (int&v : a) cin >> v, sum += v, sum2 += v*v;
    for (int&v : b) cin >> v, sum += v, sum2 += v*v;
    int nax = n*100+1;
    vector<int> can(nax);
    can[0] = 1;
    for (int i = 0; i < n; i++) {
      vector<int> ncan(nax);
      for (int v : {a[i],b[i]})
        for (int j = 0; j+v < nax; j++)
          ncan[j+v] |= can[j];
      can = ncan;
    }
    ll ans = 1e18;
    for (int i = 0; i < nax; i++) {
      if (can[i])
        ans = min(ans, sum2*(n-2)+(ll)i*i+(sum-i)*(sum-i)); 
    }
    cout << ans << endl;
  }
}