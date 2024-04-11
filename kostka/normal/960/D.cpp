//Bartek Kostka

#include "bits/stdc++.h"

using namespace std;

#define x first
#define y second
#define SZ(x) int(x.size())
#define ll long long
#define pii pair <int, int>
#define vi vector <int>

ll counter[64];

void fix(ll &x, ll mas) {
  while(x < mas) x += mas;
  while(x >= mas) x -= mas;
  // assert(x >= 0 and x < mas);
}

void shift(int lvl, ll k, bool one_step=false) {
  for(int i=lvl; i<=60; i++) {
    k %= 1LL<<i;
    counter[i] += k;
    counter[i] %= 1LL<<i;
    k *= 2;
    if(one_step) return;
  }
}

int main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int q;
  cin >> q;
  while(q--) {
    int t;
    cin >> t;
    if(t <= 2) {
      ll x, k;
      cin >> x >> k;
      int lvl = 63-__builtin_clzll(x);
      shift(lvl, k, t==1);
    } else {
      // for(int i=0; i<10; i++) cerr << counter[i] << " ";
      // cerr << "\n";
      ll x;
      cin >> x;
      int lvl = 63-__builtin_clzll(x);
      // vector <ll> ret;
      while(lvl--) {
        // ret.push_back(x);
        cout << x << " ";
        x += counter[lvl+1];
        fix(x, 1LL<<(lvl+1));
        x += 1LL<<(lvl+1);
        x >>= 1;
        x -= counter[lvl];
        fix(x, 1LL<<lvl);
        x += 1LL<<lvl;
      }
      cout << x << "\n";
    }
  }

  return 0;
}