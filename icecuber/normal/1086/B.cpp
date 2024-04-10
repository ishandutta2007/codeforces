#include <bits/stdc++.h>
using namespace std;

int deg[100000];
int main() {
  int n, s;
  cin >> n >> s;
  for (int i = 1; i < n; i++) {
    int a, b;
    cin >> a >> b;
    a--,b--;
    deg[a]++;
    deg[b]++;
  }
  int leaves = 0;
  for (int i = 0; i < n; i++)
    leaves += deg[i] == 1;
  if (n == 2) {
    cout << s << endl;
    return 0;
  }
  cout << setprecision(20) << 2.*s/leaves << endl;
}