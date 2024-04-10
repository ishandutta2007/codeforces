#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int n;
  cin >> n;
  set<pair<int,int>> empty, half;
  for (int i = 0; i < n; i++) {
    int w;
    cin >> w;
    empty.insert({w, i+1});
  }
  string s;
  cin >> s;
  for (char c : s) {
    if (c == '0') {
      cout << empty.begin()->second << ' ';
      half.insert(*empty.begin());
      empty.erase(empty.begin());
    } else {
      cout << half.rbegin()->second << ' ';
      half.erase(*half.rbegin());
    }
  }
  cout << endl;
}