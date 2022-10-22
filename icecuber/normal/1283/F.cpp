#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

#define count adfdwarf
const int nax = 2e5+10;
int count[nax];
int a[nax];
int par[nax];

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int n;
  cin >> n;
  n++;
  for (int i = 0; i < n-2; i++) {
    cin >> a[i];
    count[a[i]]++;
  }
  reverse(a, a+n-2);
  set<int> leaf;
  for (int i = 1; i <= n; i++)
    if (!count[i]) leaf.insert(i);

  for (int i = 0; i < n-2; i++) {
    int v = *leaf.begin();
    leaf.erase(v);
    if (!--count[a[i]])
      leaf.insert(a[i]);
    par[v] = a[i];
  }
  par[*leaf.begin()] = n;
  cout << *leaf.begin() << endl;
  for (int i = 1; i < n; i++) {
    if (par[i] == n) continue;
    cout << i << ' ' << par[i] << '\n';
  }
}