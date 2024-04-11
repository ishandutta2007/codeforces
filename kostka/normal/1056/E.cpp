//Bartek Kostka
//  You are not prepared!

#include "bits/stdc++.h"

using namespace std;

#define x first
#define y second
#define SZ(x) int(x.size())
#define ll long long
#define LL long long
#define VLL vector<LL>
#define pb push_back
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

struct hasze
{
      vector<int> wyk, pref, odw;
      VLL potpot = {5003, 5009, 5011, 5021, 5023, 5039, 5051, 5059, 5077, 5081, 5087, 5099, 5101, 5107, 5113, 5119, 5147, 5153, 5167, 5171};
      VLL modmod = {999999929, 999999937, 1000000007, 1000000009, 1000000021, 1000000033, 1000000087, 1000000093, 1000000097, 1000000103, 1000000123, 1000000181, 1000000207, 1000000223, 1000000241, 1000000271, 1000000289, 1000000297, 1000000321, 1000000349};
      static LL mod;//1e9 + 7; /////////////////////// tutaj wstawic modulo
      static LL POT;
      string s;

      LL pot(LL a, LL w)
      {
            if(w == 0)
                  return 1;
            LL b = pot(a, w / 2);
            b *= b;
            b %= mod;
            if(w & 1LL)
                  b = (b * a) % mod;
            return b;
      }

      hasze(string S)
      {
      	srand((LL) new int);
      	if(mod == 0)
      	{
      		POT = potpot[rand() % SZ(potpot)];
      		mod = modmod[rand() % SZ(modmod)];
      	}
      	s = S;
            wyk.pb(1);
            wyk.pb(POT); /////////////////////// tutaj wstawic podstawe
            for(int i = 2 ;i < SZ(s);i++)
                  wyk.pb((wyk.back() * (LL)wyk[1]) % mod);
            for(int i = 0 ;i < SZ(s);i++)
                  pref.pb(( (LL)(i == 0 ? 0 : pref.back()) + wyk[i] * (LL)s[i]) % mod);
            odw.pb(1);
            odw.pb(pot(wyk[1], mod - 2));
            for(int i = 2 ;i < SZ(s);i++)
                  odw.pb((odw.back() * (LL)odw[1]) % mod);
      }

      LL hasz(int l, int p)
      {
            if(l == 0)
                  return pref[p];
            return ((pref[p] - pref[l - 1] + mod) * (LL)odw[l]) % mod;
      }
};

LL hasze::mod = 0;
LL hasze::POT = 0;

int main() {
  ios_base::sync_with_stdio(0);
  srand(15061994);
  string s, t;
  cin >> s >> t;
  int cnt[2] = {0, 0};
  for(auto c : s) cnt[c-'0']++;
  auto HT = hasze(t);
  int ret = 0;
  for(int i=1; i*cnt[0] <= SZ(t); i++) {
    int j = (SZ(t) - i * cnt[0]) / cnt[1];
    if(j <= 0 or i * cnt[0] + j * cnt[1] != SZ(t)) continue;
    // cerr << i << " " << j << "\n";
    vi hahasze[2];
    int k = 0;
    for(auto c : s) {
      int l = (c == '0' ? i : j);
      hahasze[c-'0'].push_back(HT.hasz(k, k+l-1));
      k += l;
    }
    for(int d=0; d<2; d++) {
      sort(ALL(hahasze[d]));
      hahasze[d].resize(distance(hahasze[d].begin(), unique(ALL(hahasze[d]))));
    }
    if(SZ(hahasze[0]) == 1 and SZ(hahasze[1]) == 1 and hahasze[0][0] != hahasze[1][0]) ret++;
  }
  cout << ret << "\n";
  return 0;
}