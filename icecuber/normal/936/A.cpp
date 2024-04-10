#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  ll k, d, t;
  cin >> k >> d >> t;
  ll step = (k+d-1)/d*d;
  ll get = k*2+(step-k);
  ll full = t*2/get;
  ll left = t*2%get;
  ll ans;
  if (left <= k*2)
    ans = full*step*2+left;
  else
    ans = full*step*2+k*2+(left-k*2)*2;
  cout << ans/2 << '.' << ans%2*5 << endl;
}