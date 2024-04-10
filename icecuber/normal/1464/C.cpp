#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int n;
  ll k;
  cin >> n >> k;
  string s;
  cin >> s;
  vector<int> cnt(26);
  k -= (1<<(s[n-1]-'a'));
  k += (1<<(s[n-2]-'a'));
  for (int i = 0; i < n-2; i++) {
    cnt[s[i]-'a']++;
  }
  for (int i = 25; i >= 0; i--) {
    for (int j = 0; j < cnt[i]; j++) {
      if (k > 0) k -= 1<<i;
      else k += 1<<i;
    }
  }
  cout << (!k ? "Yes" : "No") << endl;
}