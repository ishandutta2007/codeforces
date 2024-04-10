#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int p[100], s[100], c[100];
int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int n, m, k;
  cin >> n >> m >> k;
  map<int,int> best;
  for (int i = 0; i < n; i++)
    cin >> p[i];
  for (int i = 0; i < n; i++) {
    cin >> s[i];
    best[s[i]] = max(best[s[i]], p[i]);
  }
  int ans = 0;
  for (int i = 0; i < k; i++) {
    cin >> c[i];
    c[i]--;
    if (p[c[i]] != best[s[c[i]]]) ans++;
  }
  cout << ans << endl;
}