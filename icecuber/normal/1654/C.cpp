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
    map<ll,int> cnt;
    ll sum = 0;
    for (int i = 0; i < n; i++) {
      int v;
      cin >> v;
      sum += v;
      cnt[v]++;
    }
    function<bool(ll)> rec = [&](ll v) {
      if (cnt.count(v) && cnt[v] > 0) {
        cnt[v]--;
        return true;
      } else {
        if (v == 1) return false;
        return rec(v/2) && rec((v+1)/2);
      }
    };
    cout << (rec(sum) ? "YES" : "NO") << endl;
  }
}