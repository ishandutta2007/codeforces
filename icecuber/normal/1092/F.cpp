#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

vector<int> node[200000];
ll a[200000];
ll sum_down[200000];

ll rec1(int p = 0, int par = -1, int depth = 0) {
  sum_down[p] = a[p];
  ll r = depth*a[p];
  for (int i : node[p]) {
    if (i == par) continue;
    r += rec1(i, p, depth+1);
    sum_down[p] += sum_down[i];
  }
  return r;
}

ll best = 0;
void rec2(int p = 0, int par = -1, ll off = 0) {
  best = max(best,off);
  for (int i : node[p]) {
    if (i == par) continue;
    rec2(i,p,off-sum_down[i]*2+sum_down[0]);
  }
}

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int n;
  cin >> n;
  for (int i = 0; i < n; i++)
    cin >> a[i];
  for (int i = 1; i < n; i++) {
    int a, b;
    cin >> a >> b;
    a--,b--;
    node[a].push_back(b);
    node[b].push_back(a);
  }
  ll base = rec1();
  rec2();
  cout << best+base << endl;
}