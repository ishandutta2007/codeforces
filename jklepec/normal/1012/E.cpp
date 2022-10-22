#include <bits/stdc++.h>
using namespace std;

#define FOR(i, a, b) for(int i = a; i < b; ++i)
#define REP(i, n) FOR(i, 0, n)
#define pb push_back
#define _ << " " <<
#define sz(x) ((int) x.size())

typedef long long ll;
typedef pair<int, int> point;

const int MAXN = 2e5 + 5;

vector<int> circuit;
vector<int> e[MAXN];

void calc(int v) {
  stack<int> s;

  while(true) {
    if(sz(e[v]) == 0) {
      circuit.pb(v);

      if(!sz(s)) {
        break;
      }

      v = s.top();
      s.pop();
    }
    else {
      s.push(v);
      int u = e[v].back();
      e[v].pop_back();
      v = u;
    }
  }
}

int a[MAXN];
int b[MAXN];
int c[MAXN];

vector<int> comp;
unordered_map<int, int> act;
unordered_map<ll, vector<int> > pos;

bool bio[MAXN];

void dfs(int v) {
  if(bio[v]) return;
  bio[v] = true;
  for(auto w: e[v]) {
    dfs(w);
  }
}

vector<vector<int> > ans;
vector<vector<int> > sol;

int s;

void solve(vector<int> &start) {
  int uk = 0;
  for(auto x: start) {
    calc(x);
    uk += sz(circuit) - 1;
    reverse(circuit.begin(), circuit.end());
    ans.pb(circuit);
    circuit.clear();
  }
  if(uk > s) {
    cout << -1;
    exit(0);
  }

  for(auto v: ans) {

    vector<int> nv;
    REP(i, sz(v) - 1) {
      int x = v[i];
      int y = v[i + 1];

      assert(sz(pos[(ll) x * MAXN + y]) > 0);

      nv.pb(pos[(ll) x * MAXN + y].back());
      pos[(ll) x * MAXN + y].pop_back();
    }

    sol.pb(nv);
  }
}

int main() {

  int n; cin >> n >> s;

  REP(i, n) {
    cin >> a[i];
    comp.pb(a[i]);
  }

  sort(comp.begin(), comp.end());
  comp.erase(unique(comp.begin(), comp.end()), comp.end());

  REP(i, sz(comp)) {
    act[comp[i]] = i;
  }

  REP(i, n) {
    a[i] = act[a[i]];
    b[i] = a[i];
  }

  sort(b, b + n);

  REP(i, n) {
    if(a[i] != b[i]) {
      e[b[i]].pb(a[i]);
      pos[(ll) b[i] * MAXN + a[i]].pb(i);
    }
  }

  vector<int> start;
  REP(i, n) {
    if(!bio[b[i]] && sz(e[b[i]])) {
      dfs(b[i]);
      start.pb(b[i]);
    }
  }

  if(sz(start) <= 2) {
    solve(start);
  }
  else {
    int uk = 0;
    for(auto x: start) {
      calc(x);
      uk += sz(circuit) - 1;
      circuit.clear();
    }

    if(uk > s) {
      cout << -1;
      return 0;
    }

    REP(i, n) {
      e[i].clear();
    }
    REP(i, n) {
      if(a[i] != b[i]) {
        e[b[i]].pb(a[i]);
      }
    }


    int can = s - uk;
    can = min(sz(start), can);

    vector<int> out;
    REP(i, can) {
      int x = start[sz(start) - i - 1];
      out.pb(pos[(ll) x * MAXN + e[x].back()].back());
    }

    if(sz(out) > 1) {
      sol.pb(out);
    }

    REP(i, can - 1) start.pop_back();

    REP(i, n) {
      c[i] = a[i];
    }

    REP(i, n) e[i].clear();
    REP(i, n) {
      if(a[i] != b[i]) {
        pos[(ll) b[i] * MAXN + a[i]].pop_back();
      }
    }

    REP(i, sz(out)) {
      c[out[(i + 1) % sz(out)]] = a[out[i]];
    }

    REP(i, n) {
      if(c[i] != b[i]) {
        e[b[i]].pb(c[i]);
        pos[(ll) b[i] * MAXN + c[i]].pb(i);
      }
    }

    solve(start);
  }

  cout << sz(sol) << endl;
  for(auto v: sol) {
    cout << sz(v) << "\n";
    for(auto x: v) cout << x + 1 << " ";
    cout << "\n";
  }

}