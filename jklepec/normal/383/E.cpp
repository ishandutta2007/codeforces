#include <bits/stdc++.h>
using namespace std;
#define FOR(i, a, b) for(int i = a; i < b; ++i)
#define REP(i, n) FOR(i, 0, n)
#define pb push_back
#define _ << " " <<
#define sz(x) ((int) x.size())

typedef long long ll;
typedef pair<int, int> point;

const int MAXN = (1 << 24), MAX = 24;

int A[MAXN], F[MAXN];

int main() {
  ios_base::sync_with_stdio(false); cin.tie(0);

  int n; cin >> n;

  REP(i, n) {
    string s; cin >> s;

    vector<int> v;
    for(auto c: s) {
      v.pb(c - 'a');
    }

    sort(v.begin(), v.end());
    v.erase(unique(v.begin(), v.end()), v.end());

    FOR(m, 1, (1 << sz(v))) {
      int submask = 0;
      REP(j, sz(v)) {
        if((1 << j) & m) {
          submask ^= (1 << v[j]);
        }
      }
      if(__builtin_popcount(m) % 2) {
        A[submask] ++;
      }
      else {
        A[submask] --;
      }
    }
  }



  REP(i, (1 << MAX)) {
    F[i] = A[i];
  }

  REP(i, MAX) REP(mask, (1 << MAX)) {
    if(mask & (1<<i)) {
      F[mask] += F[mask ^ (1 << i)];
    }
  }

  int sol = 0;
  REP(i, (1 << MAX)) {
    sol ^= F[i] * F[i];
  }

  cout << sol << endl;
}