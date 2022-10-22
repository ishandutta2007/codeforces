#include <bits/stdc++.h>
using namespace std;

#define FOR(i, a, b) for(int i = a; i < b; ++i)
#define REP(i, n) for(int i = 0; i < n; ++i)
#define _ << " " <<
typedef long long ll;

const int MAXN = 505;

int n;

bitset<MAXN> can[64][MAXN], rcan[64][MAXN], red[MAXN], stup[MAXN], rred[MAXN], rstup[MAXN];

bitset<MAXN> sol[MAXN], dummy[MAXN], baj[MAXN];

void Merge(bitset<MAXN> *x, bitset<MAXN> *y) {
   memset(dummy, 0, sizeof dummy);
   REP(i, n) {
      REP(j, n) {
         baj[i][j] = y[j][i];
      }
   }
   REP(i, n) {
      REP(j, n) {
         dummy[i][j] = (x[i] & baj[j]).any();
      }
   }
}

void check() {

   REP(i, MAXN) REP(j, MAXN) {
      sol[i].set(j);
   }

   int type = 1; ll ispis = 0;
   for(int exp = 63; exp >= 0; --exp) {
      if(type % 2)
         Merge(sol, can[exp]);
      else
         Merge(sol, rcan[exp]);
      bool ok = false;
      REP(i, n) REP(j, n) {
         if(dummy[i][j]) ok = true;
      }

      if(!ok) continue;

      type ++;
      memcpy(sol, dummy, sizeof sol);

      ispis += (ll) 1 << exp;
   }

   cout << (ispis > (ll)1e18 ? -1 : ispis);
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);

	int m; cin >> n >> m;
	REP(i, m) {
      int x, y, type; cin >> x >> y >> type;
      x -= 1; y -= 1;
      if(!type) {
         can[0][x].set(y);
      }
      else {
         rcan[0][x].set(y);
      }
	}

	FOR(lvl, 1, 64) {
      REP(i, n) {
         REP(j, n) {
            red[i][j] = can[lvl - 1][i][j];
            rred[i][j] = rcan[lvl - 1][i][j];
            stup[i][j] = can[lvl - 1][j][i];
            rstup[i][j] = rcan[lvl - 1][j][i];
         }
      }
      REP(i, n) REP(j, n) {
         can[lvl][i][j] = (red[i] & rstup[j]).any();
         rcan[lvl][i][j] = (rred[i] & stup[j]).any();
      }
	}

	REP(i, n) REP(j, n) {
      if(can[63][i][j]) {
         cout << -1 << endl;
         return 0;
      }
	}

	check();
}