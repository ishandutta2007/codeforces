#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int n, m;
  string s;
  cin >> n >> m >> s;
  int ans = 0;
  for (int i = 1; i < n; i++)
    ans += s[i-1]=='.'&&s[i]=='.';
  while (m--) {
    int i;
    char c;
    cin >> i >> c;
    i--;
    if (i) ans -= s[i-1]=='.'&&s[i]=='.';
    if (i<n-1) ans -= s[i+1]=='.'&&s[i]=='.';
    s[i] = c;
    if (i) ans += s[i-1]=='.'&&s[i]=='.';
    if (i<n-1) ans += s[i+1]=='.'&&s[i]=='.';
    cout << ans << '\n';
  }
}