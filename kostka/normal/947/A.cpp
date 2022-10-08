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

const int MAXN = 1e6+7;
int sito[MAXN];

vi dzielniki(int x) {
  vi ret;
  while(x != 1) {
    int d = sito[x];
    ret.push_back(d);
    while(x % d == 0) x /= d;
  }
  return ret;
}

int main()
{
  ios_base::sync_with_stdio(0);
  for(int i=2; i*i<=1e6; i++) {
    if(sito[i] == 0) {
      for(int j=i*i; j<=1e6; j+=i) sito[j] = i;
    }
  }
  for(int i=2; i<=1e6; i++) {
    if(!sito[i]) sito[i] = i;
  }
  int x2;
  cin >> x2;
  auto d2 = dzielniki(x2);
  int x0 = x2;
  for(int x1=3; x1<=x2; x1++) {
    for(auto d : d2) {
      if(x2 == (x1+d-1)/d*d) {
        auto d1 = dzielniki(x1);
        for(auto e : d1) {
          int k0 = x1 - e + 1;
          if(k0 >= e) x0 = min(x0, k0);
        }
      }
    }
  }
  cout << x0 << "\n";
  return 0;
}