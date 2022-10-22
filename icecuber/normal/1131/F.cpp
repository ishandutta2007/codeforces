#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

vector<int> clist[150000];
int par[150000];

int myfind(int p) {
  int&pa = par[p];
  if (pa != par[pa]) pa = myfind(pa);
  return pa;
}

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int n;
  cin >> n;
  for (int i = 0; i < n; i++)
    par[i] = i, clist[i].push_back(i);
  for (int i = 1; i < n; i++) {
    int a, b;
    cin >> a >> b;
    a--, b--;
    int pa = myfind(a), pb = myfind(b);
    if (clist[pa].size() < clist[pb].size()) swap(pa,pb);
    par[pb] = pa;
    for (int i : clist[pb])
      clist[pa].push_back(i);
    clist[pb].clear();
  }
  for (int i : clist[myfind(0)])
    cout << i+1 << ' ';
  cout << endl;
}