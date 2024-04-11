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
#define ALL(x) x.begin(), x.end()

#ifdef LOCAL
template<class TH> void _dbg(const char *sdbg, TH h){ cerr<<sdbg<<" = "<<h<<endl; }
template<class TH, class... TA> void _dbg(const char *sdbg, TH h, TA... a) {
  while(*sdbg!=',')cerr<<*sdbg++;
  cerr<<" = "<<h<<", "; _dbg(sdbg+1, a...);
}
#define dbg(...) _dbg(#__VA_ARGS__, __VA_ARGS__)
#else
#define dbg(...)
#define cerr if(false) cout
#endif

#ifdef ONLINE_JUDGE
#define FREOPEN(name) \
  freopen(name".in", "r", stdin); \
  freopen(name".out", "w", stdout);
#else
#define FREOPEN(name)
#endif

int main() {
  ios_base::sync_with_stdio(0);
  int n;
  cin >> n;
  vector <ll> L(n);
  ll ret = 0;
  for(int i=0; i<n; i++) {
    cin >> L[i];
    ret += L[i];
  }
  string s;
  cin >> s;
  ll staminaW = 0, staminaG = 0;
  int mn = 5;
  for(int i=0; i<n; i++) {
    // cerr << i << ": " << staminaG << " " << staminaW << " " << ret << "\n";
    if(s[i] == 'W') {
      staminaW += L[i];
      ret += L[i];
      mn = 3;
    }
    if(s[i] == 'G') {
      ll left = L[i];
      ll fromW = min(staminaW, left);
      left -= fromW;
      staminaW -= fromW;
      staminaG += 2LL*fromW + left;
      ret += fromW + 2LL*left;
    }
    if(s[i] == 'L') {
      ll left = L[i];
      ll fromW = min(staminaW, left);
      left -= fromW;
      staminaW -= fromW;

      ll fromG = min(staminaG, left);
      left -= fromG;
      staminaG -= fromG;

      ret += fromW + 2LL*fromG + 1LL*mn*left;
    }
  }
  cout << ret << "\n";
  return 0;
}