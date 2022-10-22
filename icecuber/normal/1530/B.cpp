#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int T;
  cin >> T;
  while (T--) {
    int h, w;
    cin >> h >> w;
    vector<string> ans(h, string(w, '0'));
    for (int i : {0,h-1})
      for (int j : {0,w-1})
        ans[i][j] = '1';
    for (int i = 2; i+1 < h-1; i += 2)
      ans[i][0] = ans[i][w-1] = '1';
    for (int j = 2; j+1 < w-1; j += 2)
      ans[0][j] = ans[h-1][j] = '1';
    for (string s : ans) 
      cout << s << endl;
  }
}