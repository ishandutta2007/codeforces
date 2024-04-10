#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int n, k;
  cin >> n >> k;
  string s;
  cin >> s;
  int inf = 1e9;
  int first[2] = {inf,inf}, last[2] = {-inf,-inf};
  for (int i = 0; i < n; i++) {
    int c = s[i]-'0';
    first[c] = min(first[c], i);
    last[c] = max(last[c], i);
  }
  if (last[0]-first[0] < k || last[1]-first[1] < k) {
    cout << "tokitsukaze" << endl;
    return 0;
  }
  if (last[0]-first[0] == k && last[1]-first[1] == k && 2*k >= n) {
    cout << "quailty" << endl;
    return 0;
  }
  cout << "once again" << endl;
}