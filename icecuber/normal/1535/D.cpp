#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int k;
  cin >> k;
  int n = 1<<k;
  vector<int> tree(n*2);
  for (int i = 0; i < n; i++) tree[i+n] = 1;

  vector<int> theirind(n*2, -1), myind(n*2, -1);
  for (int l = 0; l < k; l++)
    for (int i = 0; i < 1<<l; i++)
      theirind[(1<<l)+i] = n-1-((1<<l)*2-1-i);

  for (int i = 1; i < n; i++) myind[theirind[i]] = i;

  string s;
  cin >> s;
  auto update = [&](int i) {
    for (; i; i >>= 1) {
      assert(i >= 1 && i < n);
      char c = s[theirind[i]];
      tree[i] = tree[i*2]*(c!='1') + tree[i*2+1]*(c!='0');
    }
  };
  for (int i = n-1; i; i--) update(i);
  int q;
  cin >> q;
  while (q--) {
    int p;
    char c;
    cin >> p >> c;
    s[p-1] = c;
    update(myind[p-1]);
    cout << tree[1] << endl;
  }
}