#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int triplets, straights;
pair<int,int> query(int i) {
  cout << "+ " << i+1 << endl;
  int nt, ns;
  cin >> nt >> ns;
  pair<int,int> ret = {nt-triplets, ns-straights};
  triplets = nt;
  straights = ns;
  return ret;
}

int invert(int v) {
  int i = 0;
  while (i*(i-1)/2 < v) i++;
  assert(i*(i-1)/2 == v);
  return i;
}

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int n;
  cin >> n;
  cin >> triplets >> straights;

  vector<int> ans(n);
  vector<int> a(n), b(n);
  for (int i = 0; i < n-1; i++) {
    auto [x,y] = query(i);
    a[i] = x;
    b[i] = y;
    ans[i] = invert(x);
  }

  auto [x,y] = query(0);
  ans[0] = max(invert(x)-1,0);
  int sum12 = y-b[0]-1;
  if (ans[2] == 0 && b[1]) ans[2] = 1;
  ans[1] = sum12-ans[2];
  for (int i = 2; i < n-1; i++) {
    b[i] -= (ans[i-2]+1)*(ans[i-1]+1);
    if (i == n-2) break;
    if (ans[i+1] == 0 && b[i]) ans[i+1] = 1;
  }
  ans[n-1] = b[n-2]/(ans[n-3]+1);

  cout << "! ";
  for (int i = 0; i < n; i++) {
    cout << ans[i] << ' ';
  }
  cout << endl;
}