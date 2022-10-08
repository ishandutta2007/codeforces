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
  int n, k;
  cin >> n >> k;
  vector <int> a(n);
  for(int i=0; i<n; i++) {
    cin >> a[i];
  }
  sort(a.begin(), a.end());
  if(k == 0) {
    if(a[0] == 1) cout << -1 << "\n";
    else cout << 1 << "\n";
    return 0;
  }
  a.push_back(1e9+7);
  int e = a[k-1];
  cout << (a[k] == e ? -1 : e) << "\n";
}