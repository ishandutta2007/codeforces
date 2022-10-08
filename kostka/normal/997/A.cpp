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
  int n, x, y;
  cin >> n >> x >> y;
  string a;
  cin >> a;
  int groups = 0;
  for(int i=0; i<n; i++) {
    if(a[i] == '0' and (i == 0 or a[i-1] == '1')) groups++;
  }
  if(groups == 0) cout << 0 << "\n";
  else cout << y + 1LL * (groups-1) * min(x, y) << "\n";
  return 0;
}