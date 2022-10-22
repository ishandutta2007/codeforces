#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int n, r;
  cin >> n >> r;
  vector<int> p;
  for (int i = 0; i < n; i++) {
    int a;
    cin >> a;
    if (a) p.push_back(i);
  }
  int firstcold = 0, used = 0, failed = 0;
  for (int i = 0; i < p.size(); i++) {
    if (firstcold < n && (i+1 == p.size() || firstcold+r-1 < p[i+1])) {
      if (firstcold+r-1 < p[i]) failed = 1;
      used++, firstcold = p[i]+r;
    }
  }
  if (failed || firstcold < n) used = -1;
  cout << used << endl;
}