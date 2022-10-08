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

#ifdef ONLINE_JUDGE
#define FREOPEN(name) \
  freopen(name".in", "r", stdin); \
  freopen(name".out", "w", stdout);
#else
#define FREOPEN(name)
#endif

const int DRZ = 1<<18;
const int MOD = 1e9 + 7;
int drzL[2*DRZ], drzP[2*DRZ];
ll drzW[2*DRZ], drzWA[2*DRZ];

void _set(int ix, int a, int w) {
  ix += DRZ;
  drzL[ix] = ix-DRZ;
  drzP[ix] = ix-DRZ;
  drzW[ix] = w;
  drzWA[ix] = (1LL * a * w) % MOD;
  ix /= 2;
  while(ix) {
    drzW[ix] = (drzW[2*ix] + drzW[2*ix+1]);
    drzWA[ix] = (drzWA[2*ix] + drzWA[2*ix+1])%MOD;
    drzL[ix] = drzL[2*ix];
    drzP[ix] = drzP[2*ix+1];
    ix /= 2;
  }
}

long long _getW(int l, int r, int ix = 1) {
  if(l <= drzL[ix] and drzP[ix] <= r) return drzW[ix];
  if(l > drzP[ix] or r < drzL[ix]) return 0;
  return _getW(l, r, 2*ix) + _getW(l, r, 2*ix+1);
}

long long _getWA(int l, int r, int ix = 1) {
  if(l <= drzL[ix] and drzP[ix] <= r) return drzWA[ix];
  if(l > drzP[ix] or r < drzL[ix]) return 0;
  return (_getWA(l, r, 2*ix) + _getWA(l, r, 2*ix+1))%MOD;
}

int _getMed(ll s, int ix = 1) {
  if(ix >= DRZ) return ix-DRZ;
  if(s <= drzW[2*ix]) return _getMed(s, 2*ix);
  else return _getMed(s-drzW[2*ix], 2*ix+1);
}

int main() {
  ios_base::sync_with_stdio(0);
  int n, q;
  cin >> n >> q;
  vector <int> A(n), W(n);
  for(int i=0; i<n; i++) cin >> A[i];
  for(int i=0; i<n; i++) cin >> W[i];
  for(int i=0; i<n; i++) _set(i, A[i]-i, W[i]);
  for(int i=n; i<DRZ; i++) _set(i, 1e9+7, 0);
  while(q--) {
    int l, r;
    cin >> l >> r;
    if(l < 0) {
      int ix = -(l+1);
      _set(ix, A[ix]-ix, r);
    } else {
      l--; r--;
      ll lW = _getW(0, l-1), rW = _getW(0, r);
      int med = _getMed((lW+rW+1)/2);
      int medA = A[med] - med;
      ll medW = _getW(0, med-1);
      // cerr << "M" << med << "\n";
      // cerr << "W" << lW << "  " << rW << " " << medW << "\n";
      // cerr << "R" << _getWA(med, r) << " " << _getWA(l, med-1) << "\n";
      ll ret = _getWA(med, r) - _getWA(l, med-1);
      if(ret < 0) ret += MOD;
      ret %= MOD;
      ret += (2LL * medW % MOD * medA) % MOD;
      ret %= MOD;
      ret -= (1LL * (lW + rW) % MOD * medA) % MOD;
      if(ret < 0) ret += MOD;
      cout << ret << "\n";
    }
  }
  return 0;
}