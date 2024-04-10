#include <bits/stdc++.h>
using namespace std;

int main() {
  int a, b, c, d;
  cin >> a >> b >> c >> d;
  vector<int> x, y;
  for (int i = 0; i < a; i++) x.push_back(0);
  for (int i = 0; i < c; i++) x.push_back(2);
  for (int i = 0; i < b; i++) y.push_back(1);
  for (int i = 0; i < d; i++) y.push_back(3);
  for (int k : {0,1}) {
    vector<int> ans(max({(int)x.size()*2-!k,(int)y.size()*2-k,1}),-10);
    for (int i = 0; i < x.size(); i++)
      ans[i*2+k] = x[i];
    for (int i = 0; i < y.size(); i++)
      ans[i*2+!k] = y[i];
    int last = ans[0]+1;
    int ok = 1;
    for (int i : ans) {
      if (abs(i-last) != 1) ok = 0;
      last = i;
    }
    if (ok) {
      cout << "YES" << endl;
      for (int i : ans) cout << i << ' ';
      cout << endl;
      return 0;
    }
  }
  cout << "NO" << endl;
}