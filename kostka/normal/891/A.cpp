//Bartek Kostka
//  You are not prepared!

#include "bits/stdc++.h"

using namespace std;

int main()
{
  ios_base::sync_with_stdio(0);
  int n;
  cin >> n;
  vector <int> a(n);
  for(int i=0; i<n; i++) {
    cin >> a[i];
  }
  int gcd = a[0];
  for(int i=1; i<n; i++) {
    gcd = __gcd(a[i], gcd);
  }
  //cerr << gcd << "\n";
  if(gcd != 1) {
    cout << "-1\n";
    return 0;
  }
  int ile = 0;
  for(int i=0; i<n; i++) if(a[i] == 1) ile++;
  if(ile > 0) {
    cout << n-ile << "\n";
    return 0;
  }
  int res = n;
  for(int i=0; i<n; i++) {
    int e = a[i];
    for(int j=i+1; j<n; j++) {
      e = __gcd(e, a[j]);
      if(e == 1) {
        res = min(res, j-i); 
        break;
      }
    }
  } 
  cout << n + res - 1 << "\n";
  return 0;
}