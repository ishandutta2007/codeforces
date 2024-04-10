#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int n, k;
  cin >> n >> k;
  string s;
  cin >> s;
  int count[26] = {};
  int streak = 0;
  char last = ' ';
  for (char c : s) {
    if (c == last) streak++;
    else {
      streak = 1;
      last = c;
    }
    if (streak == k) {
      count[last-'a']++;
      streak = 0;
    }
  }
  int x = 0;
  for (int i = 0; i < 26; i++) x = max(x, count[i]);
  cout << x << endl;
}