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

const int MAXA = 17, MAX = 1 << 17;

queue<int> q[MAXA];

int n, p;
string s;

int A[MAXA][MAXA];
int cnt[MAXA];

int mini[MAXA];

bool cmp(const int &A, const int &B) {
  return q[A].front() < q[B].front();
}

int adj[MAX][MAXA][MAXA];
int ok[MAX];

int main() {
  ios_base::sync_with_stdio(false); cin.tie(0);

  cin >> n >> p >> s;
  REP(i, p) REP(j, p) cin >> A[i][j];

  REP(i, n) {
    q[s[i] - 'a'].push(i);
    cnt[s[i] - 'a'] ++;
  }
  REP(i, p) {
    q[i].push(n);
  }

  REP(i, n) {
    REP(j, p) {
      if(q[j].front() == i) q[j].pop();
    }

    vector<int> ind;
    REP(j, p) {
      ind.pb(j);
    }
    sort(ind.begin(), ind.end(), cmp);

    int msk = 0;
    REP(j, p) {
      if(q[ind[j]].front() == n) break;

      adj[msk][s[i] - 'a'][ind[j]] = 1;
      adj[msk][ind[j]][s[i] - 'a'] = 1;

      if(ind[j] + 'a' == s[i]) break;

      msk += (1 << ind[j]);
    }
  }

  REP(i, (1 << p)) {
    ok[i] = 1;
  }

  FOR(msk, 1, (1 << p)) {
    REP(k, p) if((1 << k) & msk) REP(i, p) REP(j, p) {
      adj[msk][i][j] |= adj[msk ^ (1 << k)][i][j];
    }
    REP(i, p) REP(j, p) {
      if((1 << i) & msk || (1 << j) & msk) adj[msk][i][j] = 0;
    }
    REP(i, p) REP(j, p) {
      if(adj[msk][i][j] && !A[i][j]) ok[msk] = 0;
    }
  }

  int sol = n;
  FOR(msk, 1, (1 << p)) {
    if(!ok[msk]) continue;
    ok[msk] = 0;
    REP(i, p) {
      if(((1 << i) & msk) && ok[msk ^ (1 << i)]) ok[msk] = 1;
    }
    if(!ok[msk]) continue;

    int tmp = n;
    REP(i, p) {
      if((1 << i) & msk) tmp -= cnt[i];
    }
    sol = min(sol, tmp);
  }

  cout << sol << endl;
}