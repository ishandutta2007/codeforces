#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int n, q;
  cin >> n >> q;
  string s;
  cin >> s;
  int cnt = 0;
  for (int i = 0; i+2 < (int)s.size(); i++) {
    if (s.substr(i, 3) == "abc") cnt++;
  }
  while (q--) {
    int p;
    char c;
    cin >> p >> c;
    p--;
    for (int k : {-1,1}) {
      for (int i = max(p-2,0); i+2 < (int)s.size() && i <= p; i++) { 
        cnt += k*(s.substr(i, 3) == "abc");
      }
      s[p] = c;
    }
    cout << cnt << endl;
  }
}