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
  vector <vi> R;
  for(int i=1; i<=n; i++) {
    for(int j=i; j<=n; j++) {
      int k = i^j;
      if(not(1 <= k and k <= n)) continue;
      vi X = {i,j,k};
      sort(X.begin(), X.end());
      if(k and X[2] < X[0]+X[1]) {
        //cerr << i << " " << j << " " << k << "\n";
        R.push_back(X);
      }
    }
  }
  sort(R.begin(), R.end());
  R.resize(distance(R.begin(), unique(R.begin(), R.end())));
  cout << SZ(R) << "\n";
  return 0;
}