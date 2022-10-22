#include <iostream>
#include <set>

using namespace std;

int a[10][100001];
set<int> b[100001];

int main() {
  ios::sync_with_stdio(0);
  int n, m;
  cin >> n >> m;
  for (int i = 0; i < m; i++) {
    for (int j = 0; j < n; j++) {
      cin >> a[i][j];
      if (j) b[a[i][j-1]].insert(a[i][j]);
    }
    b[a[i][n-1]].insert(-1);
  }
  int streak = 1;
  long long r = 0;
  for (int i = 0; i < n; i++) {
    if (b[a[0][i]].size() == 1 && i != n-1) {
      streak++;
    } else {
      r += 1LL*streak*(streak+1)/2;
      streak = 1;
    }
  }
  cout << r << endl;
}