#include <bits/stdc++.h>
using namespace std;

#define FOR(i, a, b) for(int i = a; i < b; ++i)
#define REP(i, n) FOR(i, 0, n)
#define _ << " " <<
#define sz(x) ((int) x.size())
#define pb push_back

typedef long long ll;
typedef pair<int, int> point;

typedef long long ll;

const int MAXN = 2e5 + 333, B = 512, MAX = 2e5 + 333, MAXB = (2e5 + 333) / 512 + 10;

int last[MAXN];

int L[MAXB][MAX];
void upfen2(int x, int y, int v) {
   for(; y < MAX; y += y & -y) L[x][y] += v;
}
void upfen(int x, int y, int v) {
   x += 5; y += 5;
   for(; x < MAXB; x += x & -x) upfen2(x, y, v);
}

int gtfen2(int x, int y, int ret = 0) {
   for(; y; y -= y & -y) ret += L[x][y];
   return ret;
}
int gtfen(int x, int y, int ret = 0) {
   x += 5; y += 5;
   for(; x; x -= x & -x) ret += gtfen2(x, y);
   return ret;
}

void update(int x, int y, int v) {
   upfen(x >> 9, y, v);
}

int query(int x, int y, int up, int ret = 0) {
   int lf = (x >> 9) + 1, rt = (y >> 9) - 1;

   if(rt > lf) {
      ret += gtfen(rt, up) - gtfen(lf - 1, up);
   }
   else {
      for(int i = x; i <= y; ++i) if(last[i] <= up) ret += 1;
      return ret;
   }

   int xcpy = x;
   while(xcpy >> 9 != lf) {
      if(last[xcpy] <= up) ret += 1;
      xcpy ++;
   }
   int ycpy = y;
   while(ycpy >> 9 != rt) {
      if(last[ycpy] <= up) ret += 1;
      ycpy --;
   }

   return ret;
}


#define _ << " " <<

int zapravo[MAXN];

int main() {

  ios_base::sync_with_stdio(false); cin.tie(0);

  int n, m; cin >> n >> m;

  REP(i, n) {
    int x; cin >> x;
    zapravo[x] = i + 1;
  }

  REP(i, n) {
    cin >> last[i];
    last[i] = zapravo[last[i]];
    update(i, last[i], 1);
  }

  REP(i, m) {
    int type; cin >> type;
    if(type == 1) {
      int x, y, a, b; cin >> x >> y >> a >> b;
      a --; b --;

      cout << query(a, b, y) - (x > 1 ? query(a, b, x - 1) : 0) << '\n';
    }
    else {
      int x, y; cin >> x >> y; --x; --y;
      update(x, last[x], -1);
      update(x, last[y], +1);
      update(y, last[y], -1);
      update(y, last[x], +1);
      swap(last[x], last[y]);
    }

  }
}