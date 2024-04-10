#include <bits/stdc++.h>
using namespace std;

#define FOR(i, a, b) for(int i = a; i < b; ++i)
#define REP(i, n) FOR(i, 0, n)
#define _ << " " <<
#define pb push_back

typedef long long ll;
typedef pair<int, int> pii;

const int MAXN = 3e5 + 5;

vector<vector<int> > a, b, sol;

int n, m;

int best = 1e9;

void solve() {

  vector<int> p;
  REP(i, 4) p.pb(i);

  do {
    if(p[0] > p[1] && p[2] > p[3]) {
      int tmp = 0;
      REP(i, n) {
        int l, r;
        if(i % 2) {
          l = p[0];
          r = p[1];
        }
        else {
          l = p[2];
          r = p[3];
        }

        int b1 = 0, b2 = 0;
        REP(j, m) {
          if(j % 2) {
            if(r != a[i][j]) b1 ++;
            if(l != a[i][j]) b2 ++;
          }
          else {
            if(l != a[i][j]) b1 ++;
            if(r != a[i][j]) b2 ++;
          }
        }

        if(b2 < b1) swap(l, r);

        REP(j, m) {
          if(j % 2)
          b[i][j] = r;
          else
          b[i][j] = l;
        }

        tmp += min(b1, b2);
      }

      if(tmp < best) {
        sol = b;
        best = tmp;
      }

      tmp = 0;
      REP(j, m) {
        int l, r;
        if(j % 2) {
          l = p[0];
          r = p[1];
        }
        else {
          l = p[2];
          r = p[3];
        }

        int b1 = 0, b2 = 0;
        REP(i, n) {
          if(i % 2) {
            if(r != a[i][j]) b1 ++;
            if(l != a[i][j]) b2 ++;
          }
          else {
            if(l != a[i][j]) b1 ++;
            if(r != a[i][j]) b2 ++;
          }
        }

        if(b2 < b1) swap(l, r);

        REP(i, n) {
          if(i % 2)
          b[i][j] = r;
          else
          b[i][j] = l;
        }

        tmp += min(b1, b2);
      }

      if(tmp < best) {
        sol = b;
        best = tmp;
      }
    }
  } while(next_permutation(p.begin(), p.end()));

}

char tt[4] = {'A', 'C', 'G', 'T'};
map<char,int> t = {{'A', 0}, {'C', 1}, {'G', 2}, {'T', 3}};

int main() {
  cin >> n >> m;

  vector<int> v;
  v.resize(m);

  REP(i, n) {
    a.pb(v);
    b.pb(v);
    sol.pb(v);
  }

  REP(i, n) {
    string s; cin >> s;
    REP(j, m) {
      a[i][j] = t[s[j]];
    }
  }

  solve();

  REP(i, n) {
    REP(j, m) {
      cout << tt[sol[i][j]];
    }
    cout << '\n';
  }
}