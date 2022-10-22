#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int p[200000], ip[200001];
ll rec(int a, int b, map<int,int>&m) {
  if (b-a <= 1) return 0;
  int ma = m.rbegin()->first, mai = m.rbegin()->second;

  ll ans = 0;
  int l, r;
  if (mai-a < b-(mai+1)) l = a, r = mai;
  else l = mai+1, r = b;
  map<int,int> m_;
  m.erase(ma);
  for (int i = l; i < r; i++) {
    m.erase(p[i]);
    m_[p[i]] = i;
  }
  for (int i = l; i < r; i++)
    ans += m.count(ma-p[i]);

  ans += rec(mai+1, b, l==a ? m : m_);
  ans += rec(a, mai, l==a ? m_ : m);
  return ans;
}

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int n;
  cin >> n;
  map<int,int> m;
  for (int i = 0; i < n; i++) {
    cin >> p[i];
    ip[p[i]] = i;
    m[p[i]] = i;
  }
  cout << rec(0,n,m) << endl;
}