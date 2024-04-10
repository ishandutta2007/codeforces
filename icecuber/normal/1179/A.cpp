#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int n, q;
  cin >> n >> q;
  deque<int> deque;
  int ma = 0;
  for (int i = 0; i < n; i++) {
    int a;
    cin >> a;
    deque.push_back(a);
  }
  vector<pair<int,int>> ans;
  for (int i = 0; i < n*2; i++) {
    int a = deque.front(); deque.pop_front();
    int b = deque.front(); deque.pop_front();
    ans.emplace_back(a,b);
    deque.push_front(max(a,b));
    deque.push_back(min(a,b));
  }
  while (q--) {
    ll m;
    cin >> m;
    m--;
    auto p = ans[m-max(m-(n-1),0ll)/(n-1)*(n-1)];
    cout << p.first << ' ' << p.second << '\n';
  }
}