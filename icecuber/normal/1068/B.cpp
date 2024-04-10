#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  set<ll> s;
  ll b;
  cin >> b;
  for (ll i = 1; i*i <= b; i++)
    if (b%i==0) s.insert(i), s.insert(b/i);
  cout << s.size() << endl;
}