#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int n, k;
  cin >> n >> k;
  map<int, int> m;
  for (int i = 0; i < n; i++) {
    int s;
    cin >> s;
    m[s]++;
  }
  int pass = 0, fail = 3e6;
  while (pass+1 < fail) {
    int mid = pass+fail>>1;
    int letters = 0;
    for (auto p : m)
      letters += p.second/mid;
    if (letters >= k) pass = mid;
    else fail = mid;
  }
  vector<int> t;
  for (auto p : m) {
    for (int i = 0; i < p.second/pass && t.size() < k; i++)
      t.push_back(p.first);
  }
  for (int i : t)
    cout << i << ' ';
  cout << endl;
}