#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
const ld PI = acosl(-1.);

const int N = 100;
int f[N][N][N][3];
//int where[N][N][N][3];

int myabs(int x) {
  if (x < 0) return -x;
  return x;
}

vector<int> posv, posk, poso;
int compute(int nv, int nk, int no, int pos) {
  int ans = nv + nk + no;
  ans -= upper_bound(posv.begin(), posv.begin() + nv, pos) - posv.begin();
  ans -= upper_bound(posk.begin(), posk.begin() + nk, pos) - posk.begin();
  ans -= upper_bound(poso.begin(), poso.begin() + no, pos) - poso.begin();
  return ans;
}

int main() {
  int n; cin >> n;
  string s;
  cin >> s;

  for (int i = 0; i < n; ++i) {
    if (s[i] == 'V') {
      posv.push_back(i);
    } else if (s[i] == 'K') {
      posk.push_back(i);
    } else {
      poso.push_back(i);
    }
  }

  int nv = posv.size(), nk = posk.size(), no = poso.size();
  memset(f, 63, sizeof(f));
  if (nv) f[1][0][0][0] = 0;
  if (nk) f[0][1][0][1] = 0;
  if (no) f[0][0][1][2] = 0;

  int cost[3];
  for (int v = 0; v <= nv; ++v)
    for (int k = 0; k <= nk; ++k)
      for (int o = 0; o <= no; ++o) {
        cost[0] = v < nv ? compute(v, k, o, posv[v]) : 1e6;
        cost[1] = k < nk ? compute(v, k, o, posk[k]) : 1e6;
        cost[2] = o < no ? compute(v, k, o, poso[o]) : 1e6;

        for (int who = 0; who < 3; ++who) {
          if (f[v][k][o][who] > 1e6) continue;
          for (int whom = 0; whom < 3; ++whom) {
            int newv = v;
            int newk = k;
            int newo = o;
            if (whom == 0) ++newv;
            if (whom == 1) ++newk;
            if (whom == 2) ++newo;

            if (who == 0 && whom == 1) continue;
            if (cost[whom] > 1e5) continue;
            int ncost = f[v][k][o][who] + cost[whom];
            if (ncost < f[newv][newk][newo][whom]) {
              f[newv][newk][newo][whom] = ncost;
//              where[newv][newk][newo][whom] = who;
              //cerr << v << " " << k << " " << o << " " << who << " --> "  << whom <<  ": " << f[v][k][o][who] << endl;
            }
          }
        }
      }

  int ans = 1e9;
  int bwho = 0;
  for (int i = 0; i < 3; ++i) {
      ans = min(ans, f[nv][nk][no][i]);
  //    bwho = i;
  }
  cout << ans << endl;
  return 0;

  /*
  string ss;
  while (nv || nk || no) {
    //cerr << "Current: " << nv << " " << nk << " " << " " << no << " " << f[nv][nk][no][bwho] << endl;
    int whom = where[nv][nk][no][bwho];
    if (whom == 0) ss += "V";
    if (whom == 1) ss += "K";
    if (whom == 2) ss += "O";

    if (bwho == 0) --nv;
    if (bwho == 1) --nk;
    if (bwho == 2) --no;
    //cerr << whom << " -- > " << bwho << endl;
    bwho = whom;
  }
  reverse(ss.begin(), ss.end());
  cerr << ss << endl;
  */

  return 0;
}