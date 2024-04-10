#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int n, a, b, c;
ll solve(int ones, vector<int> groups, int zeros, int all_zeros) {
  /*cout << ones << ' ' << zeros << ' ' << all_zeros << ": ";
  for (int v : groups) cout << v << ' ';
  cout << " = ";*/

  int ready = 0;
  while (groups.size() && groups.back() == 1) {
    groups.pop_back(), ready++;
  }

  ll score = 0;
  while (1) {
    if (ones) {
      if (groups.size()) {
        if (--groups.back() == 1) {
          ready++;
          groups.pop_back();
        }
        score += a+b;
      } else if (zeros) {
        score += a+b;
      } else if (b > c && all_zeros) {
        zeros++;
        if (ready)
          ones++, ready--;
        score += b-c;
      } else break;
    } else {
      if (ready && b > c) {
        ones++;
        zeros++;
        ready--;
        score += b-c;
      } else if (zeros) {
        score += a;
        break;
      } else break;
    }

    zeros--;
    all_zeros--;
    ones--;
  }

  //cout << score << endl;
  return score;
}

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int T;
  cin >> T;
  while (T--) {
    string s;
    cin >> n >> a >> b >> c >> s;
    int ones = 0, zeros = 0;
    vector<int> groups;
    for (int i = 1; i < n; i++) {
      if (s[i-1] == '1' && s[i] == '1') ones++;
      if (s[i-1] == '0' && s[i] == '0') zeros++;
      if (s[i-1] == '1' && s[i] == '0') {
        int k = i;
        while (k < n && s[k] == '0') k++;
        if (k < n) groups.push_back(k-i);
      }
    }

    int all_zeros = count(s.begin(), s.end(), '0');
    sort(groups.rbegin(), groups.rend());
    ll ans = solve(ones, groups, zeros, all_zeros);
    if (ones) 
      ans = max(ans, solve(ones-1, groups, zeros, all_zeros)+b);
    cout << ans << endl;
  }
}