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
  int n, q;
  cin >> n >> q;
  vector <ll> a(n+1);
  for(int i=1; i<=n; i++) cin >> a[i];
  for(int i=2; i<=n; i++) a[i] += a[i-1];
  while(q--) {
    ll x;
    cin >> x;
    auto it = distance(a.begin(), lower_bound(a.begin(), a.end(), x));
    cout << it << " " << x - a[it-1] << "\n";
  }
  return 0;
}