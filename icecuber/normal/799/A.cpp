#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  ll n, t, k, d;
  cin >> n >> t >> k >> d;
  ll A = (n+k-1)/k*t;
  cout << (A > d && (A-1)/t*k+(A-1-d)/t*k >= n ? "YES" : "NO") << endl;
}