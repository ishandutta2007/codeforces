#include <bits/stdc++.h>

#define FOR(i,a,b) for (int i = (int)(a); i < (int)(b); ++i)
#define REP(i,n) FOR(i,0,n)
#define pb push_back
#define x first
#define y second

#define TRACE(x) cerr << #x << " = " << x << endl
#define _ << " _ " <<

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

int n, m;
pii all[100005];

int pref[100005];

int loga[100005];
int Set(int p, int v){ p += 2;
  for (; p < 100005; p += p&-p)
    loga[p] = max(loga[p], v);
}
int Ask(int p){ p += 2;
  int r = 0;
  for (; p; p -= p&-p)
    r = max(r, loga[p]);
  return r;
}

vector<int> build(){
  memset(loga, 0, sizeof loga);
  vector<int> out(m);
  REP(i,m){
    int x = Ask(pref[i+1]) + 1;
    out[i] = x;
    Set(pref[i+1], x);
  }
  return out;
}

int main(){
  ios_base::sync_with_stdio(false);

  cin >> n >> m;
  REP(i,n) cin >> all[i].x >> all[i].y;

  REP(i,n) ++pref[all[i].x], --pref[all[i].y+1];
  REP(i,m) pref[i+1] += pref[i];

  auto right = build(); reverse(pref+1, pref+m+1);
  auto left = build(); reverse(left.begin(), left.end());

  int maks = 0;
  REP(i,m) maks = max(maks, right[i] + left[i]);
  cout << maks-1 << endl;

  return 0;
}