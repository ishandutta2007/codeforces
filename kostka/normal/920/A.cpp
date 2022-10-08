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
  int t;
  cin >> t;
  while(t--) {
    int n, k;
    cin >> n >> k;
    vector <int> X;
    for(int i=0; i<k; i++) {
      int x;
      cin >> x;
      X.push_back(x);
    }
    int res = 0;
    for(int i=1; i<=n; i++) {
      int tim = 1e9;
      for(auto x : X) {
        tim = min(tim, abs(i-x));
      }
      res = max(res, tim);
    }
    cout << res+1 << "\n";
  }
  return 0;
}