#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int c[1000][5];
int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int n, m;
  cin >> n >> m;
  for (int i = 0; i < n; i++) {
    string s;
    cin >> s;
    for (int j = 0; j < m; j++) {
      c[j][s[j]-'A']++;
    }
  }

  int sum = 0;
  for (int j = 0; j < m; j++) {
    int ma = 0;
    for (int k = 0; k < 5; k++)
      ma = max(ma, c[j][k]);
    int weight;
    cin >> weight;
    sum += ma*weight;;
  }
  cout << sum << endl;
}