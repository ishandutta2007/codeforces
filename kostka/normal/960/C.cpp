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
  ll x, d;
  cin >> x >> d;
  ll ele = 1;
  vector<long long> ret;
  for(int i=0; i<__builtin_popcount(x); i++) {
    ret.push_back(ele);
    ele += d+1;
  }
  for(int i=1; i<=30; i++) {
    if(x & (1<<i)) {
      for(int j=0; j<i; j++) ret.push_back(ele);
      ele += d+1;
    }
  }
  cout << SZ(ret) << "\n";
  for(auto r : ret) cout << r << " ";
  cout << "\n";
  return 0;
}