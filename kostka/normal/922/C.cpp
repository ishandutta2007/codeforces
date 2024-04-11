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
  ll a, b;
  cin >> a >> b;
  for(ll i=1; i<=b; i++) {
    if(a % i != i-1) {
      cout << "No\n";
      exit(0);
    }
  }
  cout << "Yes\n";
  return 0;
}