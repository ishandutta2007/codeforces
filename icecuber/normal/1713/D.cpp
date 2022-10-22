#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int query(int a, int b) {
  cout << "? " << a+1 << ' ' << b+1 << endl;
  int ans;
  cin >> ans;
  return ans;
}

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int T;
  cin >> T;
  while (T--) {
    int n;
    cin >> n;
    vector<int> cur;
    for (int i = 0; i < 1<<n; i++) cur.push_back(i);
    while (cur.size() >= 4) {
      vector<int> ncur;
      for (int i = 0; i < (int)cur.size(); i += 4) {
        int q1 = query(cur[i], cur[i+2]);
        int a, b;
        if (q1 == 0) a = cur[i+1], b = cur[i+3];
        else if (q1 == 1) a = cur[i], b = cur[i+3];
        else if (q1 == 2) a = cur[i+1], b = cur[i+2];
        int q2 = query(a, b);
        assert(q2);
        ncur.push_back(q2 == 1 ? a : b);
      }
      cur = ncur;
    }
    if (cur.size() == 2) {
      int q = query(cur[0], cur[1]);
      assert(q);
      cur = {q == 1 ? cur[0] : cur[1]};
    }
    cout << "! " << cur[0]+1 << endl;
  }
}