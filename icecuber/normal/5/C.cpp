#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

#define x first
#define y second

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  string s;
  cin >> s;
  int acc = 0;
  stack<pair<int,int>> st;
  st.emplace(-1,0);
  int len = 0, count = 1;
  for (int i = 0; i < s.size(); i++) {
    acc += s[i] == '(' ? 1 : -1;
    while (st.size() && acc < st.top().y) st.pop();
    if (st.size() && acc == st.top().y) {
      int l = i-st.top().x;
      if (l > len) len = l, count = 0;
      if (l == len) count++;
    } else
      st.emplace(i,acc);
  }

  cout << len << ' ' << count << endl;
}