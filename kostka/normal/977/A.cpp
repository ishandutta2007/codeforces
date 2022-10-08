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
  while(k--) {
    if(n%10 == 0) {
      n /= 10;
    } else {
      n--;
    }
  }
  cout << n << "\n";
  return 0;
}