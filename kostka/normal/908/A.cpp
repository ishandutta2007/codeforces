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
  string x;
  cin >> x;
  int res = 0;
  for(auto xx : x) {
    if(xx == 'a' or xx == 'e' or xx == 'i' or xx == 'o' or xx == 'u' or xx == '1' or xx == '3' or xx == '5' or xx == '7' or xx == '9') res++;
  }
  cout << res << "\n";
  return 0;
}