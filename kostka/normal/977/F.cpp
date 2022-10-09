//Bartek Kostka
//  You are not prepared!

#include "bits/stdc++.h"

using namespace std;

#define x first
#define y second
#define SZ(x) int(x.size())
#define ll long long
#define pii pair <int, int>
#define vi vector <int>

int main()
{
  ios_base::sync_with_stdio(0);
  int n;
  cin >> n;
  vector <int> a(n+7);
  for(int i=1; i<=n; i++) {
    cin >> a[i];
  }
  map <int, int> pre;
  vector <int> res(n+7);
  vector <int> skad(n+7, -1);
  pair <int, int> ans = {-1, -1};
  for(int i=1; i<=n; i++) {
    int s = pre[a[i]-1];
    res[i] = res[s] + 1;
    skad[i] = s;
    pre[a[i]] = i;
    if(res[i] > ans.x) {
      ans = {res[i], i};
    }
  }
  vi ret;
  int e = ans.y;
  while(e != 0) {
    ret.push_back(e);
    e = skad[e];
  }
  reverse(ret.begin(), ret.end());
  cout << SZ(ret) << "\n";
  for(auto r : ret) cout << r << " ";
  return 0;
}