#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int a[200000];
int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int n;
  cin >> n;
  ll sum = 0;
  priority_queue<int> pq;
  for (int i = 0; i < n; i++) {
    cin >> a[i];
    sum += a[i];
    pq.push(a[i]);
  }
  int ma = pq.top();
  pq.pop();
  int se = pq.top();
  vector<int> ans;
  for (int i = 0; i < n; i++) {
    int ok = 0;
    if (a[i] == ma) {
      if (sum-a[i] == se*2) ok = 1;
    } else {
      if (sum-a[i] == ma*2) ok = 1;
    }
    if (ok) ans.push_back(i+1);
  }
  cout << ans.size() << endl;
  for (int i : ans)
    cout << i << ' ';
  cout << endl;
}