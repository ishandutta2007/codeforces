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
  vector <int> D;
  int i = 0;
  while(SZ(D) != 10000) {
    i += 1;
    int sum = 0;
    int ii = i;
    while(ii != 0) {
      sum += ii%10;
      ii /= 10;
    }
    if(sum == 10) D.push_back(i);
  }
  int k;
  cin >> k;
  cout << D[k-1] << "\n";
  return 0;
}