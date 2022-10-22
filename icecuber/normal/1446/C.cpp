#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int dq(vector<int> a, int i = 29) {
  if (a.empty()) return 0;
  if (i == -1) return a.size()>0;
  vector<int> l, r;
  for (int v : a) {
    if (v>>i&1) r.push_back(v);
    else l.push_back(v);
  }
  return max(dq(l, i-1)+(r.size()>0),
             dq(r, i-1)+(l.size()>0));
}

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int n;
  cin >> n;
  vector<int> a(n);
  for (int&v : a) cin >> v;
  cout << n-dq(a) << endl;
}