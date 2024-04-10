#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int n;
  cin >> n;
  const int q = 13;
  vector<vector<int>> query(q, vector<int>(n));
  int p = 0;
  for (int i = 0; i < 1<<q && p < n; i++) {
    if (__builtin_popcount(i) != 6) continue;
    for (int j = 0; j < q; j++) {
      query[j][p] = i>>j&1;
    }
    p++;
  }
  vector<ll> answer;
  for (int j = 0; j < q; j++) {
    vector<int> s;
    for (int i = 0; i < n; i++)
      if (query[j][i]) s.push_back(i);
    if (s.empty()) {
      answer.push_back(0);
    } else {
      cout << "? " << s.size();
      for (int i : s) cout << ' ' << i+1;
      cout << endl;
      ll a;
      cin >> a;
      assert(a != -1);
      answer.push_back(a);
    }
  }
  vector<ll> ans(n);
  for (int bit = 0; bit < 63; bit++) {
    int any = 0;
    for (int j = 0; j < q; j++)
      if (answer[j]>>bit&1) any = 1;
    if (!any) continue;

    int one = -1;
    for (int i = 0; i < n; i++) {
      int all = 1;
      for (int j = 0; j < q; j++) {
	if (query[j][i] && !(answer[j]>>bit&1)) all = 0;
      }
      if (all) one = i;
    }
    for (int j = 0; one != -1 && j < q; j++) {
      int expect = query[j][one];
      if ((answer[j]>>bit&1) != expect) one = -1;
    }
    for (int i = 0; i < n; i++) {
      ans[i] |= ll(i != one)<<bit;
    }
  }

  cout << "!";
  for (ll v : ans) cout << ' ' << v;
  cout << endl;
}