#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int n, k;
  string s;
  cin >> n >> k >> s;
  int overlap = 0;
  for (int i = 1; i < n; i++) {
    if (s.substr(0,i) == s.substr(n-i,i))
      overlap = i;
  }
  for (int i = 1; i < k; i++)
    s += s.substr(overlap,n-overlap);
  cout << s << endl;
}