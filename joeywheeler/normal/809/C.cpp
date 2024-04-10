#include <bits/stdc++.h>
#define FO(i,a,b) for (int i = (a); i < (b); i++)
#define sz(v) int(v.size())

using namespace std;

typedef long long ll;
#define MOD 1000000007ll

ll a, b, k;

ll nmc[32][2][2][2];
ll smc[32][2][2][2];

ll nm(int bi, int la, int lb, int lk) {
  if (bi == -1) {
    return la && lb && lk;
  }
  ll &res = nmc[bi][la][lb][lk];
  if (res != -1) return res;
  res = 0;
  
  int ad = (a>>bi)&1;
  int bd = (b>>bi)&1;
  int kd = (k>>bi)&1;
  if (la) ad = 1;
  if (lb) bd = 1;
  if (lk) kd = 1;

  FO(ma,0,ad+1) FO(mb,0,bd+1) if ((ma^mb) <= kd) {
    res += nm(bi-1,
        la || (ma < ad),
        lb || (mb < bd),
        lk || ((ma^mb) < kd)
        );
    if (res >= MOD) res -= MOD;
  }
  return res;
}

ll sm(int bi, int la, int lb, int lk) {
  if (bi == -1) {
    return 0;
  }
  ll &res = smc[bi][la][lb][lk];
  if (res != -1) return res;
  res = 0;


  int ad = (a>>bi)&1;
  int bd = (b>>bi)&1;
  int kd = (k>>bi)&1;
  if (la) ad = 1;
  if (lb) bd = 1;
  if (lk) kd = 1;

  FO(ma,0,ad+1) FO(mb,0,bd+1) if ((ma^mb) <= kd) {
    res += sm(bi-1,
        la || (ma < ad),
        lb || (mb < bd),
        lk || ((ma^mb) < kd)
        );
    res += (((ll)(ma^mb))<<bi) * nm(bi-1,
        la || (ma < ad),
        lb || (mb < bd),
        lk || ((ma^mb) < kd)
        );
    res %= MOD;
  }
  return res;
}


ll qsm(ll x, ll y) {
  memset(nmc,-1,sizeof nmc);
  memset(smc,-1,sizeof smc);
  a = x;
  b = y;

  ll num = sm(31, 0, 0, 0) + nm(31, 0, 0, 0);
  return num;
}

int main() {
  int q; scanf("%d", &q);
  FO(_,0,q) {
    ll x1, y1, x2, y2;
    scanf("%lld %lld %lld %lld %lld", &x1, &y1, &x2, &y2, &k);
    x1--; y1--;

    ll res = qsm(x2,y2) - qsm(x2,y1) - qsm(x1,y2) + qsm(x1,y1);
    res %= MOD;
    if (res < 0) res += MOD;

    printf("%lld\n", res);
  }
}