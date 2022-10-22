#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int c[5001];
int col[5001];
int used[5001];
int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int maxcol = 0;
  int n, k;
  cin >> n >> k;
  for (int i = 0; i < n; i++) {
    int a;
    cin >> a;
    maxcol = max(maxcol,c[i] = ++col[a]);
    used[c[i]]++;
  }
  if (maxcol > k) {
    cout << "NO" << endl;
    return 0;
  }
  cout << "YES" << endl;
  for (int i = 0; i < n; i++) {
    if (maxcol < k && used[c[i]] > 1) {
      cout << ++maxcol << ' ';
      used[c[i]]--;
    } else
      cout << c[i] << ' ';
  }
  cout << endl;
}