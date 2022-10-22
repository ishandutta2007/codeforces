#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int n, k;
  cin >> n >> k;
  deque<int> d(n);
  for (int i = 0; i < n; i++)
    cin >> d[i];
  while (d.size() && d.front() <= k) d.pop_front();
  while (d.size() && d.back() <= k) d.pop_back();
  cout << n-d.size() << endl;
}