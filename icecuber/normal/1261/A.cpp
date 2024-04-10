#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int t;
  cin >> t;
  while (t--) {
    int n, k;
    cin >> n >> k;
    string s;
    cin >> s;
    string target;
    for (int i = 0; i < k-1; i++)
      target += "()";
    int rem = n-2*(k-1);
    for (int i = 0; i < rem/2; i++)
      target += "(";
    for (int i = 0; i < rem/2; i++)
      target += ")";
    vector<int> a, b;
    for (int i = 0; i < n; i++) {
      if (s[i] == '(' && target[i] == ')')
	a.push_back(i);
      if (s[i] == ')' && target[i] == '(')
	b.push_back(i);
    }
    vector<pair<int,int>> ans;
    for (int i = 0; i < a.size(); i++) {
      int x = a[i], y = b[i];
      if (x > y) swap(x,y);
      if (y-1 > x+1)
	ans.emplace_back(x+1, y-1);
      ans.emplace_back(x, y);
    }
    cout << ans.size() << endl;
    for (auto p : ans) {
      cout << p.first+1 << ' ' << p.second+1 << endl;
      //reverse(s.begin()+p.first, s.begin()+p.second+1);
    }
    //assert(s == target);
  }
}