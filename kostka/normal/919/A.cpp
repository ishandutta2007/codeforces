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
  int n, m;
  cin >> n >> m;
  double res = 1e9;
  for(int i=0; i<n; i++) {
    int a, b;
    cin >> a >> b;
    res = min(res, 1.0*a*m/b);
  }
  cout << fixed << setprecision(10) << res << "\n";
  return 0;
}