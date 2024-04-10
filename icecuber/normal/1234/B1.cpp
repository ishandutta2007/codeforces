#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  set<int> on;
  deque<int> screen;
  int n, k;
  cin >> n >> k;
  for (int i = 0; i < n; i++) {
    int id;
    cin >> id;
    if (on.count(id)) continue;
    if (screen.size() == k) {
      on.erase(screen.back());
      screen.pop_back();
    }
    screen.push_front(id);
    on.insert(id);
  }
  cout << screen.size() << endl;
  for (int i : screen)
    cout << i << ' ';
  cout << endl;
}