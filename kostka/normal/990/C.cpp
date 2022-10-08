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

vi C[300007];

int main()
{
  ios_base::sync_with_stdio(0);
  int n;
  cin >> n;
  map <int, int> X;
  for(int i=0; i<n; i++) {
    string s;
    cin >> s;
    int akt = 0, minx = 0;
    for(auto c : s) {
      if(c == '(') akt++;
      else akt--;
      minx = min(akt, minx);
    }
    if(X.find(akt) == X.end()) {
      int a = SZ(X);
      X[akt] = a;
    }
    C[X[akt]].push_back(minx);
  }
  for(int i=0; i<SZ(X); i++) {
    sort(C[i].begin(), C[i].end());
  }
  ll res = 0;
  for(auto ele : X) {
    if(ele.x < 0) continue;
    if(X.find(-ele.x) == X.end()) continue;
    for(auto f : C[X[ele.x]]) {
      if(f >= 0) {
        res += distance(lower_bound(C[X[-ele.x]].begin(), C[X[-ele.x]].end(), -ele.x), C[X[-ele.x]].end());
      }
    }
  }
  cout << res << "\n";
  return 0;
}