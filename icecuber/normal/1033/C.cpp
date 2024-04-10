#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int ans[100000];
int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int n;
  cin >> n;
  vector<int> a(n);
  vector<pair<int,int>> q;
  for (int i = 0; i < n; i++) {
    cin >> a[i];
    q.emplace_back(a[i], i);
  }
  sort(q.rbegin(), q.rend());
  for (auto p : q) {
    int i = p.second;
    int found = 0;
    for (int j = i%a[i]; j < n; j += a[i])
      found |= ans[j];
    ans[i] = !found;
  }
  for (int i = 0; i < n; i++)
    cout << "AB"[ans[i]];
  cout << endl;
}