#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int a[200000], b[200000];
int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int n;
  cin >> n;
  for (int i = 0; i < n; i++)
    cin >> a[i];
  int j = 0;
  set<int> done;
  for (int i = 0; i < n; i++) {
    cin >> b[i];
    if (done.count(b[i])) {
      cout << 0 << ' ';
      continue;
    }
    int j0 = j;
    while (a[j] != b[i]) done.insert(a[j]),j++;
    done.insert(a[j++]);
    cout << j-j0 << ' ';
  }
  cout << endl;
}