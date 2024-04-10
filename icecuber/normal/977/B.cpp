#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  string s;
  int n;
  cin >> n >> s;
  map<string,int> ma;
  string ans;
  int best = -1;
  for (int i = 0; i < n-1; i++) {
    int score = ++ma[s.substr(i,2)];
    if (score > best) {
      best = score;
      ans = s.substr(i,2);
    }
  }
  cout << ans << endl;
}