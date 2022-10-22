#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int nax = 1e6;
int mem[nax];
ll e;
int f(ll n, int win) {
  if (n > e) return win;
  if (!mem[n]) {
    mem[n] = (!f(n+1, win) || !f(n*2, win))+1;
  }
  return mem[n]-1;
}

struct Range {
  ll l, r;
  int w[2];
  int f(ll p) {
    return w[p%2];
  }
};

int f3(ll s, int win) {
  Range cur = {e+1, e*2, win, win};
  while (s < cur.l) {
    Range nxt = {(cur.l +1)/2, cur.r/2};
    assert(nxt.r+1 == cur.l);
    nxt.w[0] = nxt.w[1] = !cur.f(0);
    nxt.w[nxt.r%2] |= !cur.f(cur.l%2);
    nxt.w[!(nxt.r%2)] |= !nxt.w[nxt.r%2];
    cur = nxt;
  }
  return cur.f(s);
}

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  /*
  for (int k : {0,1}) {
    for (e = 1; e < 160; e++) {
      fill_n(mem, nax, 0);
      for (int i = 1; i < e; i++) {
	assert(f(i,k) == f3(i,k));
	cout << f3(i, k);
      }
    }
    cout << endl;
    }*/

  int t;
  cin >> t;
  int lose = 1, win = 0;
  while (t--) {
    ll s;
    cin >> s >> e;
    int nlose =
      (lose && f3(s, 0)) ||
      (win && !f3(s, 0));
    int nwin =
      (lose && f3(s, 1)) ||
      (win && !f3(s, 1));
    lose = nlose;
    win = nwin;
  }
  cout << win << ' ' << lose << endl;
}