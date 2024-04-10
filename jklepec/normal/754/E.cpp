#include <bits/stdc++.h>
using namespace std;

#define rep(i, n) for(int i = 0; i < n; ++i)
typedef long long ll;
typedef pair<int, int> point;

const int MAXN = 405, B = 60;

char c[MAXN][MAXN], mat[MAXN][MAXN];

ll red[MAXN][MAXN][7], bit[MAXN][26][7];

void setbit(int x, int y, int s) {
   bit[x][s][y / B] |= 1LL << (y % B);
}
bool calc(int qr, int j, int i) {
   if((1LL << (i % B)) & red[qr][j][i / B]) return true;
   return false;
}

/*
5 7
qcezchs
hhedywq
wikywqy
qckrqzt
bqexcxz
3 2
??
yw
?q
*/

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);

   int n, m; cin >> n >> m;
   rep(i, n) rep(j, m) {
      cin >> c[i][j];
   }
   rep(i, n) rep(j, m) rep(s, 26) {
      if(c[i][j] - 'a' == s) setbit(j, i, s);
   }

   int r, s; cin >> r >> s;
   rep(i, r) rep(j, s) {
      cin >> mat[i][j];
   }

   rep(redak, r) rep(j, m) {
      rep(i, 7) red[redak][j][i] = (ll) (1LL << 60) - 1;
      rep(stupac, s) {
         if(mat[redak][stupac] == '?') continue;
         rep(i, 7) {
            red[redak][j][i] &= bit[(j + stupac) % m][mat[redak][stupac] - 'a'][i];
         }
      }
   }

   rep(i, n) {
      rep(j, m) {
         bool mogu = true;
         rep(redak, r) {
            mogu &= calc(redak, j, (i + redak) % n);
         }
         cout << mogu;
      }
      cout << endl;
   }
}