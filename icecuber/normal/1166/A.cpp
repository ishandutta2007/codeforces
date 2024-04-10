#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int n;
  cin >> n;
  map<char, int> count;
  for (int i = 0; i < n; i++) {
    string s;
    cin >> s;
    count[s[0]]++;
  }
  int ans = 0;
  for (auto p : count) {
    int k = p.second, a = k/2, b = k-a;
    ans += a*(a-1)/2+b*(b-1)/2;
  }
  cout << ans << endl;
}