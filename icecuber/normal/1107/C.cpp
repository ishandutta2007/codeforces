#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int a[200000];

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int n, k;
  cin >> n >> k;
  for (int i = 0; i < n; i++)
    cin >> a[i];
  string s;
  cin >> s;
  ll ans = 0;
  for (int i = 0; i < n; i++) {
    int j = i+1;
    priority_queue<int> pq;
    pq.push(a[i]);
    while (j < n && s[j] == s[i]) {
      pq.push(a[j]);
      j++;
    }
    for (int l = 0; l < k && pq.size(); l++) {
      ans += pq.top();
      pq.pop();
    }
    i = j-1;
  }
  cout << ans << endl;
}