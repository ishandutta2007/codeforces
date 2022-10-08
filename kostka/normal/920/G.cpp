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

const int MAXE = 1000007;
int sito[MAXE];

void preprocessing() {
  for(int i=2; i*i<MAXE; i++) {
    if(!sito[i]) {
      for(int j=i*i; j<MAXE; j+=i) sito[j] = i;
    }
  }
  for(int i=2; i<MAXE; i++) {
    if(!sito[i]) sito[i] = i;
  }
}

vi divisors(int x) {
  vi ret;
  while(x != 1) {
    int d = sito[x];
    while(x % d == 0) x /= d;
    ret.push_back(d);
  }
  return ret;
}

ll ile(ll y, vector<ll>& plus, vector<ll>& minus) {
  ll w = y;
  for(auto x : plus) w += y/x;
  for(auto x : minus) w -= y/x;
  return w;
}

void test() {
  int x, p, k;
  cin >> x >> p >> k;
  auto D = divisors(p);
  vector<ll> E[2];
  for(int mas=1; mas<1<<(SZ(D)); mas++) {
    ll w = 1;
    for(int i=0; i<SZ(D); i++) {
      if(mas & (1<<i)) w *= D[i];
    }
    E[__builtin_popcount(mas)%2].push_back(w);
  }
  k += ile(x, E[0], E[1]);
  ll a = 0, b = 1e15;
  while(b-a > 1) {
    ll m = (a+b)/2;
    if(ile(m, E[0], E[1]) < k) a = m;
    else b = m;
  }
  cout << b << "\n";
}

int main()
{
  ios_base::sync_with_stdio(0);
  preprocessing();
  int t;
  cin >> t;
  while(t--) test();
  return 0;
}