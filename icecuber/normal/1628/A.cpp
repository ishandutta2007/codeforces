#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

struct MEX {
  int cur = 0;
  multiset<int> has;
  void insert(int v) {
    has.insert(v);
    while (has.count(cur)) cur++;
  }
  void erase(int v) {
    has.erase(has.find(v));
    if (has.find(v) == has.end()) cur = min(cur, v);
    //while (cur && !has.count(cur-1)) cur--;
  }
};

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int T;
  cin >> T;
  while (T--) {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int&v : a) cin >> v;

    MEX mex;
    for (int v : a) mex.insert(v);

    vector<int> ans;
    int i = 0;
    while (i < n) {
      int target = mex.cur;
      ans.push_back(target);
      MEX part;
      do {
        assert(i < n);
        part.insert(a[i]);
        mex.erase(a[i]);
        i++;
      } while (part.cur < target);
    }
    cout << ans.size() << endl;
    for (int v : ans) cout << v << ' ';
    cout << endl;
  }
}