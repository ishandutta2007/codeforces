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
  vi a(n);
  for(int i=0; i<n; i++) cin >> a[i];
  sort(a.begin(), a.end());
  cout << a[(n-1)/2] << "\n";
  return 0;
}