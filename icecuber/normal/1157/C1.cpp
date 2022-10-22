#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int v[200000];
int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int n;
  cin >> n;
  for (int i = 0; i < n; i++) cin >> v[i];
  int a = 0, b = n-1;

  string ans;
  int last = 0;
  while (v[a] != v[b]) {
    if (v[a] > last && (v[a] < v[b] || v[b] <= last))
      ans += 'L', last = v[a++];
    else if (v[b] > last && (v[b] < v[a] || v[a] <= last))
      ans += 'R', last = v[b--];
    else break;
  }
  if (a == b) {
    if (v[a] > last)
      ans += 'L';
  } else if (v[a] == v[b] && v[a] > last) {
    int x = a+1;
    while (v[x] > v[x-1]) x++;
    int y = b-1;
    while (v[y] > v[y+1]) y--;
    if (x-a >= b-y)
      for (int i = a; i < x; i++) ans += 'L';
    else
      for (int i = y; i < b; i++) ans += 'R';
  }
  cout << ans.size() << endl;
  cout << ans << endl;
}