#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

char ans[1010][1010];
int top[1010];

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int n, l, k;
  cin >> n >> l >> k;
  string s;
  cin >> s;
  sort(s.begin(), s.end());
  int a = 0;
  for (int j = 0; j < l; j++) {
    for (int i = top[j]; i < k; i++) {
      ans[i][j] = s[a++];
      if (i && ans[i][j] != ans[i-1][j]) top[j+1] = i;
    }
  }
  for (int j = 0; j < l; j++) {
    for (int i = 0; i < top[j]; i++) {
      ans[i][j] = s[a++];
    }
  }
  for (int j = 0; j < l; j++) {
    for (int i = k; i < n; i++) {
      ans[i][j] = s[a++];
    }
  }
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < l; j++)
      cout << ans[i][j];
    cout << endl;
  }
}