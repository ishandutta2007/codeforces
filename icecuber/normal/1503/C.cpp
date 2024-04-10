#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int n;
  cin >> n;
  vector<array<int,2>> ac(n);
  for (auto&[a,c] : ac) cin >> a >> c;
  sort(ac.begin(), ac.end());
  int r = ac[0][0], tot = 0;
  ll totc = 0;
  for (auto [a,c] : ac) {
    totc += c;
    if (r < a) tot += a-r;
    r = max(r, a+c); 
  }
  cout << tot+totc << endl;
}