#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int n;
  string a, b;
  cin >> n >> a >> b;
  int c[26] = {};
  for (int i = 0; i < n; i++)
    c[a[i]-'a']++, c[b[i]-'a']--;
  for (int j = 0; j < 26; j++)
    if (c[j]) {
      cout << -1 << endl;
      return 0;
    }

  vector<int> ans;
  auto f = [&](int x) {
    reverse(a.begin(), a.end());
    reverse(a.begin()+n-x, a.end());
    ans.push_back(n-x);
  };
  int l = n/2-1, r = l+1;
  for (int k = 0; k < n; k++) {
    char need = k%2 ? b[l--] : b[r++];
    int pos = 0;
    while (a[pos] != need) pos++;
    //assert(pos < n-k);
    f(n-k);
    f(k+pos);
    f(n-pos);
    //assert(a[n-k-1] == need);
  }
  if (n%2) f(0);
  assert(a == b);
  cout << ans.size() << endl;
  for (int i : ans) cout << i << ' ';
  cout << endl;
}