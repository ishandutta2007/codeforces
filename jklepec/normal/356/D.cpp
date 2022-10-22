#include <bits/stdc++.h>
using namespace std;

#define FOR(i, a, b) for(int i = a; i < b; ++i)
#define REP(i, n) FOR(i, 0, n)
#define pb push_back
#define _ << " " <<
#define sz(x) ((int) x.size())

typedef long long ll;
typedef pair<int, int> point;

const int MAXN = 70005;

point a[MAXN];
int coin[MAXN], nxt[MAXN];

int sol[MAXN], bag[MAXN];

int first[MAXN];
bitset<MAXN> sums;

int main() {
  ios_base::sync_with_stdio(false); cin.tie(0);

  int n, s; cin >> n >> s;

  REP(i, n) {
    cin >> a[i].first;
    a[i].second = i;
  }

  sort(a, a + n, greater<point>());

  REP(i, n + 1) {
    nxt[i] = -1;
  }

  int par = -1;

  bitset<MAXN> ldp;
  ldp.set(0);

  for(int i = n - 1; i >= 0; --i) {
    bitset<MAXN> news = ((ldp << a[i].first) & sums) ^ (ldp << a[i].first);

    for (int j = news._Find_first(); j < MAXN; j = news._Find_next(j))
      first[j] = i + 1;

    sums |= news;
    if(!i) {
      if((ldp << a[i].first).test(s) != true) {
        cout << -1;
        return 0;
      }
    }
    ldp = ((ldp << a[i].first) | ldp);
  }


  FOR(i, 1, n + 1) {
    if(i == 1 || first[s] == i) {
      s -= a[i - 1].first;
    }
    else {
      nxt[par] = i - 1;
      coin[par] = a[par].first - a[i - 1].first;
    }

    par = i - 1;
  }

  REP(i, n) {
    sol[a[i].second] = coin[i];
    bag[a[i].second] = nxt[i];

    if(nxt[i] == -1) {
      sol[a[i].second] += a[i].first;
    }
  }


  REP(i, n) {
    cout << sol[i] << " ";
    if(bag[i] != -1) {
      cout << 1 << " ";
      cout << a[bag[i]].second + 1 << "\n";
    }
    else {
      cout << 0 << "\n";
    }
  }
}