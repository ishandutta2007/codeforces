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
  vector <int> a(n);
  long long res = 0;
  for(int i=0; i<n; i++) {
    cin >> a[i];
    res -= a[i];
  }
  reverse(a.begin(), a.end());
  int vis = 0;
  for(int i=0; i<n; i++) {
    --vis;
    a[i] = vis = max(a[i], vis);
  }
  reverse(a.begin(), a.end());
  vis = 0;
  for(int i=0; i<n; i++) {
    a[i] = vis = max(a[i], vis);
  }
  for(int i=0; i<n; i++) res += a[i];
  cout << res << "\n";
  return 0;
}