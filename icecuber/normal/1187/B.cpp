#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int pref[200001][26];

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int n;
  string s;
  cin >> n >> s;
  for (int i = 0; i < n; i++) {
    copy_n(pref[i], 26, pref[i+1]);
    pref[i+1][s[i]-'a']++;
  }
  int q;
  cin >> q;
  while (q--) {
    string t;
    cin >> t;
    int need[26] = {};
    for (char c : t) need[c-'a']++;
    int fail = 0, pass = n;
    while (pass-fail > 1) {
      int mid = pass+fail>>1;
      int ok = 1;
      for (int i = 0; i < 26; i++)
	if (need[i] > pref[mid][i])
	  ok = 0;
      if (ok) pass = mid;
      else fail = mid;
    }
    cout << pass << endl;
  }
}