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
  long long n, k;
  cin >> n >> k;
  if(k == 1) {
    cout << n << "\n";
  } else {
    cout << (1LL<<(64-__builtin_clzll(n)))-1 << "\n";
  }

  return 0;
}