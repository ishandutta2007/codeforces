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
  map <int, int> M;
  for(int i=0; i<n; i++) {
    int x, y;
    cin >> x >> y;
    M[x] = max(M[x], y);
  }
  int m;
  cin >> m;
  for(int i=0; i<m; i++) {
    int x, y;
    cin >> x >> y;
    M[x] = max(M[x], y);
  }
  ll res = 0;
  for(auto ele : M) {
    res += ele.y;
  }
  cout << res << "\n";

  return 0;
}