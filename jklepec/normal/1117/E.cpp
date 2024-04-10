#include <bits/stdc++.h>
using namespace std;
#define FOR(i, a, b) for(int i = a; i < b; ++i)
#define REP(i, n) FOR(i, 0, n)
#define _ << " " <<
#define pb push_back
#define fi first
#define se second

typedef double lf;
typedef long long ll;
typedef pair<int, int> pii;

const int mod = 1e9 + 7;
int add(int x, int y) {x += y; if(x >= mod) return x - mod; return x;}
int sub(int x, int y) {x -= y; if(x < 0) return x + mod; return x;}
int mul(int x, int y) {return (ll) x * y % mod;}

vector<vector<int> > original;
vector<vector<int> > groups;

int n;

void solve(int sz) {
  string ask(n, '$');
  for(auto x: original) {
    int m = x.size();
    REP(i, m) {
      char let = 'a' + i / sz;
      ask[x[i]] = let;
    }
  }

  cout << "? " << ask << endl;
  string get; cin >> get;

  vector<vector<int> > ngroups, noriginal;
  REP(j, groups.size()) {
    vector<int> x = groups[j];
    vector<int> y = original[j];

    REP(k, 26) {
      vector<int> v1, v2;
      int m = x.size();
      REP(i, m) {
        if(get[x[i]] == 'a' + k) {
          v1.pb(x[i]);
        }
        if(ask[y[i]] == 'a' + k) {
          v2.pb(y[i]);
        }
      }
      if(v1.size() != 0) {
        ngroups.pb(v1);
        noriginal.pb(v2);
      }
    }
  }
  original = noriginal;
  groups = ngroups;
}

int main() {
  ios_base::sync_with_stdio(false); cin.tie(0);

  vector<int> v;
  string org; cin >> org;
  n = org.size();
  REP(i, n) v.pb(i);
  groups.pb(v);
  original.pb(v);

  solve(676);
  solve(26);
  solve(1);

  string ret(n, '$');
  REP(i, groups.size()) {
    ret[original[i][0]] = org[groups[i][0]];
  }

  cout << "! " << ret << endl;
}