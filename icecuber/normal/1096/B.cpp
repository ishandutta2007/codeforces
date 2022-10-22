#include <bits/stdc++.h>
using namespace std;

long long mod = 998244353;

int main() {
  ios::sync_with_stdio(0);
  int n;
  string s;
  cin >> n >> s;
  int na, nb;
  char a = s[0], b = s[n-1];
  while (s[na] == a) na++;
  while (s[n-1-nb] == b) nb++;
  if (a == b) {
    cout << (1ll*(na+1)*(nb+1))%mod << endl;
  } else {
    cout << na+nb+1 << endl;
  }
}