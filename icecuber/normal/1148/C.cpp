#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int p[300000], ip[300000];

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int n;
  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> p[i];
    p[i]--;
    ip[p[i]] = i;
  }
  vector<pair<int,int>> ans;
  auto s = [&](int i, int j) {
    swap(ip[p[i]], ip[p[j]]);
    swap(p[i],p[j]);
    ans.emplace_back(i+1,j+1);
  };
  for (int i = 1; i < n; i++) {
    if (p[i] != i) {
      int j = ip[i];
      if (abs(i-j)*2 >= n) s(i,j);
      else if (j < n/2) {
	s(j,n-1);
	if (i < n/2) s(i,n-1);
	else s(n-1,0),s(i,0);
      } else {
	s(j,0);
	if (i >= n/2) s(i,0);
	else s(n-1,0),s(i,n-1);
      }
    }
  }
  cout << ans.size() << endl;
  for (auto p : ans) {
    cout << p.first << ' ' << p.second << endl;
    //assert(abs(p.second-p.first)*2 >= n);
  }
  //for (int i = 0; i < n; i++) assert(p[i] == i && ip[i] == i);
}