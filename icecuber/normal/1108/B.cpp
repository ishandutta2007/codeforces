#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int n;
  cin >> n;
  map<int,int> c;
  for (int i = 0; i < n; i++) {
    int d;
    cin >> d;
    c[d]++;
  }
  int x = c.rbegin()->first;
  for (int i = 1; i <= x; i++)
    if (x%i == 0) if (!--c[i]) c.erase(i);
  int y = c.rbegin()->first;
  cout << x << ' ' << y << endl;
}