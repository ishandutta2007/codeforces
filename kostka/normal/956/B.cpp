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

double foo(double ei, double ej, double ek) {
  return (ek - ej) / (ek - ei);
}

int main()
{
  ios_base::sync_with_stdio(0);
  int n, U;
  cin >> n >> U;
  vector <int> a(n);
  for(int i=0; i<n; i++) {
    cin >> a[i];
  }
  // sort(a.begin(), a.end());
  double ret = -1;
  int p = 0, k = 0;
  while(p < n) {
    while(k<n and a[k]-a[p] <= U) k++;
    if(k-p > 2) ret = max(ret, foo(a[p], a[p+1], a[k-1]));
    p++;
  }
  cout << fixed << setprecision(10) << ret << "\n";
  return 0;
}