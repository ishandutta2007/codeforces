#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int ns, nb;
  cin >> ns >> nb;
  vector<int> a(ns);
  for (int i = 0; i < ns; i++)
    cin >> a[i];
  vector<pair<int,int>> dg(++nb,{0,0});
  for (int i = 0; i < nb; i++)
    cin >> dg[i].first >> dg[i].second;
  sort(dg.begin(), dg.end());
  for (int i = 1; i < nb; i++)
    dg[i].second += dg[i-1].second;
  for (int i = 0; i < ns; i++) {
    cout << prev(upper_bound(dg.begin(), dg.end(), make_pair(a[i],(int)2e9)))->second << endl;
  }
}