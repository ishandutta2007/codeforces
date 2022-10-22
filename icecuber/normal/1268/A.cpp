#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int n, k;
  cin >> n >> k;
  string s;
  cin >> s;
  string ans = s;
  for (int i = k; i < n; i++) ans[i] = ans[i-k];
  if (ans < s) {
    int p = k-1;
    while (ans[p] == '9') ans[p--] = '0';
    ans[p]++;
    for (int i = k; i < n; i++) ans[i] = ans[i-k];
  }
  cout << n << endl;
  cout << ans << endl;
}