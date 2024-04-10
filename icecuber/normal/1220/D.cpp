#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int n;
  cin >> n;
  vector<ll> b(n);
  map<int,int> count;
  int best = 0, bestt = 0;
  for (int i = 0; i < n; i++) {
    cin >> b[i];
    int t = __builtin_ctzll(b[i]);
    int c = ++count[t];
    if (c > best) best = c, bestt = t;
  }
  cout << n-best << endl;
  for (int i = 0; i < n; i++)
    if (__builtin_ctzll(b[i]) != bestt)
      cout << b[i] << ' ';
  cout << endl;
}