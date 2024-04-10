#include <bits/stdc++.h>

using namespace std;

typedef long long     LL;
typedef pair<int,int> pii;

double PI  = acos(-1);
double EPS = 1e-7;
int INF    = 1000000000;
LL INFLL   = 1000000000000000000LL;

#define fi            first
#define se            second
#define mp            make_pair
#define pb            push_back

#define input(in)     freopen(in,"r",stdin)
#define output(out)   freopen(out,"w",stdout)

#define MIN(a, b)     (a) = min((a), (b))
#define MAX(a, b)     (a) = max((a), (b))

#define RESET(a, b)   memset(a,b,sizeof(a))
#define ALL(a)        (a).begin(), (a).end()
#define SIZE(a)       (int)a.size()
#define SORT(a)       sort(ALL(a))
#define UNIQUE(a)     (a).erase( unique( ALL(a) ), (a).end() )
#define FOR(a, b, c)  for (int (a)=(b); (a)<=(c); (a)++)
#define FORD(a, b, c) for (int (a)=(b); (a)>=(c); (a)--)
#define FORIT(a, b)   for (__typeof((b).begin()) a=(b).begin(); a!=(b).end(); a++)
// ----- //

bool cek(int x) {
  int dir = 0;
  int prev = -1;
  while(x) {
    int p = x%10;
    if (dir == 0 && prev != -1) {
      if (p > prev) dir = 1;
      else if (p < prev) dir = -1;
      else return 0;
    }
    if (dir == 1) {
      if (p > prev);
      else return 0;
    }
    if (dir == -1) {
      if (p < prev);
      else return 0;
    }
    x/=10;
    prev = p;
    dir = -dir;
  }
  return 1;
}

bool cekblock(int x) {
  int dir = 0;
  int prev = -1;
  int u = 7;
  while(u--) {
    int p = x%10;
    if (dir == 0 && prev != -1) {
      if (p > prev) dir = 1;
      else if (p < prev) dir = -1;
      else return 0;
    }
    if (dir == 1) {
      if (p > prev);
      else return 0;
    }
    if (dir == -1) {
      if (p < prev);
      else return 0;
    }
    x/=10;
    prev = p;
    dir = -dir;
  }
  return 1;
}

#define MGC 10000000
int num[2][10][760000];
int mapping[2][MGC];

int main() {
  long long dv,k, m, lim = 1;
  cin >> dv >> k;
  m = 14;
  while(m--) lim *= 10;
  RESET(num, 0);
  RESET(mapping, 0);
  int co = 0;
  vector<int> haha[2];
  vector<pii> data[2];
  FOR(a,0,MGC-1) {
    if (cekblock(a)) {
      int i = a/1000000;
      int j = (a-i*1000000)/100000;
      if (i > j) {
        haha[0].pb(a%dv);
        data[0].pb(mp(a%dv,i));
      }
      else {
        haha[1].pb(a%dv);
        data[1].pb(mp(a%dv,i));
      }
      co++;
    }
  }
  SORT(haha[0]);
  UNIQUE(haha[0]);
  SORT(haha[1]);
  UNIQUE(haha[1]);
  RESET(mapping,-1);
  FOR(a,0,SIZE(haha[0])-1) {
    int i = haha[0][a];
    mapping[0][i] = a;
  }
  FOR(a,0,SIZE(data[0])-1) {
    num[0][data[0][a].se][mapping[0][data[0][a].fi]]++;
  }
  FOR(a,0,SIZE(haha[1])-1) {
    int i = haha[1][a];
    mapping[1][i] = a;
  }
  FOR(a,0,SIZE(data[1])-1) {
    num[1][data[1][a].se][mapping[1][data[1][a].fi]]++;
  }
  long long ways = 0;
  FOR(a,0,MGC-1) {
    if (a == 0) {
      for(int b=dv;b<MGC;b+=dv) {
        if (cek(b)) {
          ways++;
          if (ways == k) {
            long long ans = b;
            if ((LL)ans > lim) ans = -1;
            cout << ans << endl;
            goto lala;
          }
        }
      }
    }
    else if (cek(a)) {
      long long mod = ((LL)a*10000000)%dv;
      long long match = dv-mod;
      if (match == dv) match = 0;
      if (match >= MGC) continue;
      if (a < 10) {
        long long tmp = 0;
        if (mapping[0][match] != -1) {
          FOR(b,a+1,9)
            tmp += num[0][b][mapping[0][match]];
        }
        if (mapping[1][match] != -1) {
          FORD(b,a-1,0)
            tmp += num[1][b][mapping[1][match]];
        }
        if (ways+tmp >= k) {
          FOR(b,0,MGC-1) {
            if (cekblock(b)) {
              int i = b/1000000;
              int j = (b-i*1000000)/100000;
              if (((a < i && i > j) || (a > i && i < j)) && b%dv == match) {
                ways++;
                if (ways == k) {
                  long long ans = (LL)a*MGC+b;
                  if ((LL)ans > lim) ans = -1;
                  cout << ans << endl;
                  goto lala;
                }
              }
            }
          }
        }
        ways += tmp;
      }
      else {
        int p = a%100;
        int q = a%10;
        p /= 10;
        if (p > q) {
          long long tmp = 0;
          if (mapping[0][match] != -1) {
            FOR(b,q+1,9)
              tmp += num[0][b][mapping[0][match]];
          }

          if (ways+tmp >= k) {
            FOR(b,0,MGC-1) {
              if (cekblock(b)) {
                int i = b/1000000;
                int j = (b-i*1000000)/100000;
                if (q < i && i > j && b%dv == match) {
                  ways++;
                  if (ways == k) {
                    long long ans = (LL)a*MGC+b;
                    if ((LL)ans > lim) ans = -1;
                    cout << ans << endl;
                    goto lala;
                  }
                }
              }
            }
          }
          ways += tmp;
        }
        else {
          long long tmp = 0;
          if (mapping[1][match] != -1) {
            FORD(b,q-1,0)
              tmp += num[1][b][mapping[1][match]];
          }
          if (ways+tmp >= k) {
            FOR(b,0,MGC-1) {
              if (cekblock(b)) {
                int i = b/1000000;
                int j = (b-i*1000000)/100000;
                if (q > i && i < j && b%dv == match) {
                  ways++;
                  if (ways == k) {
                    long long ans = (LL)a*MGC+b;
                    if ((LL)ans > lim) ans = -1;
                    cout << ans << endl;
                    goto lala;
                  }
                }
              }
            }
          }
          ways += tmp;
        }
      }
    }
  }
  cout << "-1" << endl;
lala:;
}