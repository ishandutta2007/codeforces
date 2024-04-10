#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int n;
  cin >> n;
  vector<int> a(n);
  for (int&i : a)
    cin >> i;
  sort(a.begin(), a.end());
  vector<int> s, t;
  map<int,int> count;
  for (int i : a) {
    int c = count[i]++;
    if (c > 1) {
      cout << "NO" << endl;
      return 0;
    }
    if (c)
      t.push_back(i);
    else
      s.push_back(i);
  }
  reverse(t.begin(), t.end());
  cout << "YES" << endl;
  cout << s.size() << endl;
  for (int i : s) cout << i << ' ';
  cout << endl;
  cout << t.size() << endl;
  for (int i : t) cout << i << ' ';
  cout << endl;
}