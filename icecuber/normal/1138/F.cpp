#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

vector<int> move(vector<int> v) {
  cout << "next";
  for (int i : v)
    cout << ' ' << i;
  cout << endl;
  vector<int> ret(10);
  string ans;
  getline(cin, ans);
  //cerr << ans << endl;
  if (ans == "stop") exit(0);
  int groupi = 0;
  for (char c : ans) {
    if (c == ' ') groupi++;
    else ret[c-'0'] = groupi;
  }
  return ret;
}

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int x = 0;
  while (1) {
    auto tmp = move({0,1});
    auto ans = move({0});
    x++;
    if (ans[0] == ans[1]) break;
  }
  int c = 0;
  while (1) {
    auto ans = move({0});
    c++;
    if (ans[0] == ans[1]) break;
  }
  vector<int> v;
  for (int i = 2; i < 10; i++) v.push_back(i);
  for (int i = 0; i < x-c; i++)
    move(v);
  v.push_back(0);
  v.push_back(1);
  while (1) {
    auto ans = move(v);
    if (ans[0] == ans[9]) break;
  }
  cout << "done" << endl;
}