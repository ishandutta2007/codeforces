#include <bits/stdc++.h>
#define pb push_back
#define rep(i, j, k) for(int i = j; i <= k; ++ i)
#define per(i, j, k) for(int i = j; i >= k; -- i)
using namespace std;
const int N = 2e5 + 10;
int n;
vector<int> s1, s2;
int query(vector<int> s1, vector<int> s2) {
  cout << "? " << s1.size() << ' ' << s2.size() << '\n';
  for(int v : s1) cout << v << ' ';
  cout << '\n';
  for(int v : s2) cout << v << ' ';
  cout << endl;
  int res; cin >> res; return res;
}
void report(vector<int> s) {
  cout << "! " << s.size() << ' ';
  for(int v : s) cout << v << ' ';
  cout << endl;
}
int main() {
  int t; cin >> t;
  while(t --) {
    cin >> n;
    s1.clear();
    int a = 0, b = 0;
    rep(i, 2, n) {
      s1.pb(i - 1); s2 = {i};
      if(query(s1, s2)) {
        b = i; break ;
      }
    }
    s2 = {b};
    int l = 1, r = b - 1;
    while(l <= r) {
      int mid = (l + r) >> 1;
      s1.clear();
      rep(i, 1, mid) s1.pb(i);
      if(query(s1, s2)) r = mid - 1;
      else l = mid + 1;
    }
    a = r + 1;
    vector<int> ans;
    rep(i, 1, b - 1) if(i != a) ans.pb(i);
    rep(i, b + 1, n) {
      s1 = {i};
      if(!query(s1, s2)) {
        ans.pb(i);
      }
    }
    report(ans);
  }
  return 0;
}