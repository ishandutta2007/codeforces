#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int done[200];

void solve(vector<string>&v, string sol) {
  string ans;
  for (int i = 0; i < 200; i++) done[i] = 0;
  //cout << sol << endl;
  for (string i : v) {
    if (sol.substr(0,i.size()) == i && !done[i.size()]++)
      ans += 'P';
    else if (sol.substr(sol.size()-i.size(),i.size()) == i)
      ans += 'S';
    else return;
  }
  cout << ans << endl;
  exit(0);
}

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int n;
  cin >> n;
  vector<string> v;
  vector<string> large;
  for (int i = 0; i < n*2-2; i++) {
    string s;
    cin >> s;
    v.push_back(s);
    if (s.size() == n-1)
      large.push_back(s);
  }
  solve(v,large[0][0]+large[1]);
  solve(v,large[1][0]+large[0]);
}