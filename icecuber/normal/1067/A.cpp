#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll mod = 998244353;
int a[100000];

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int n;
  cin >> n;
  for (int i = 0; i < n; i++) cin >> a[i];
  vector<ll> up(201), notup(201), prev_up(201,0), prev_notup(201,0);
  prev_up[0] = 1;
  for (int i = 0; i < n; i++) {
    for (int j = 1; j <= 200; j++) {
      (prev_up[j] += prev_up[j-1]) %= mod;
      (prev_notup[j] += prev_notup[j-1]) %= mod;
    }
    up[0] = notup[0] = 0;
    for (int j = 1; j <= 200; j++) {
      up[j] = notup[j] = 0;
      if (a[i] != -1 && a[i] != j) continue;
      (up[j] += prev_up[j-1]+prev_notup[j-1]) %= mod;
      (notup[j] += prev_up[j]+prev_notup[j]) %= mod;
      (notup[j] -= prev_up[j-1]+prev_notup[j-1]) %= mod;
      (notup[j] += prev_notup[200]-prev_notup[j]) %= mod;
    }
    prev_up = up;
    prev_notup = notup;
  }
  ll ans = 0;
  for (int i = 1; i <= 200; i++)
    (ans += prev_notup[i]) %= mod;
  cout << (ans+mod)%mod << endl;
}