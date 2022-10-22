#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll f(vector<int> v) {
  ll ans = 1;
  int left = v.size()+1;
  int streak = 0, last = -1;
  ll div = 1;
  for (int i : v) {
    //cout << i << ' ';
    ans *= left-max(i,1);
    left--;
    if (i != last) {
      last = i;
      streak = 0;
    }
    streak++;
    div *= streak;
  }
  return ans/div;
}

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int t;
  cin >> t;
  while (t--) {
    ll k;
    cin >> k;
    vector<int> v;
    for (int i = 2; k; i++) {
      v.push_back(k%i);
      k /= i;
    }
    sort(v.rbegin(), v.rend());
    ll ans = f(v);
    int zeros = count(v.begin(), v.end(), 0);
    if (zeros) {
      v.pop_back();
      ans -= f(v);
    }
    cout << ans-1 << endl;
  }
}