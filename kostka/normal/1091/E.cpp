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


int n;

pair <bool, bool> check(vector <int> A, int x) {
  bool vis = false;
  vi tab(n+7);
  for(auto a : A) tab[a]++;
  sort(ALL(A));
  reverse(ALL(A));
  int ile = n+1;
  ll low = 0, hig = 0;
  for(int i=0; i<=n; i++) {
    if(A[i] >= i) ile--;
    else hig -= A[i];
    vis |= (A[i] == x);
    tab[A[i]]--;
    ile -= tab[i];
    low += A[i];
    hig += 1LL * i * tab[i];
    if(low > hig + 1LL * (ile + i) * (i+1))
      return make_pair(false, vis);
  }
  return make_pair(true, vis);
}

int main() {
  ios_base::sync_with_stdio(0);
  cin >> n;
  vi A(n);
  for(int i=0; i<n; i++) cin >> A[i];
  ll sum = 0;
  for(int i=0; i<n; i++) sum += A[i];
  vi bounds;
  auto fix = [&](int x) -> int {
    if(x%2 != sum%2) x++;
    return x;
  };
  for(int _=0; _<2; _++) {
    // cerr << "Phase: " << _ << "\n";
    int p = 0, k = n+1;
    while(k - p > 0) {
      int med = (k+p+_)/2;
      // cerr << "M " << p << " " << k << " " << med << " " << fix(med) << "\n";
      A.resize(n);
      A.push_back(fix(med));
      bool res, vis;
      tie(res, vis) = check(A, fix(med));
      // cerr << "R" << res << "\n";
      if(res) {
        if(_) p = med;
        else k = med;
      } else {
        if(!vis) p = med + 1;
        else k = med - 1;
      }
    }
    // cerr << "P" << p << "\n";
    if(!_) {
      A.back() = fix(p);
      if(check(A, fix(p)).x) bounds.push_back(p);
      else bounds.push_back(p+1);
    } else {
      A.back() = fix(p);
      if(check(A, fix(p)).x) bounds.push_back(p);
      else bounds.push_back(p-1);
    }
  }
  // cerr << "ANS\n";
  // cerr << bounds[0] << " " << bounds[1] << "\n";
  vi ret;
  for(int i=fix(bounds[0]); i<=bounds[1]; i+=2) ret.push_back(i);
  if(ret.empty()) cout << -1 << "\n";
  else {
    for(auto r : ret) cout << r << " ";
    cout << "\n";
  }
  return 0;
}