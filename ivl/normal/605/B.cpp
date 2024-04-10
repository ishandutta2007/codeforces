#include <bits/stdc++.h>

#define FOR(i,a,b) for (int i = (int)(a); i < (int)(b); ++i)
#define REP(i,n) FOR(i,0,n)
#define ll long long
#define pb push_back
#define pii pair < int, int >
#define x first
#define y second

#define TRACE(x) cerr << #x << " = " << x << endl
#define _ << " _ " <<

using namespace std;

int n, m;
int a[100005], b[100005];

vector < int > vs, vr;
int cnt[100005];

pii sol[100005];

void imp(){cout << -1 << endl; exit(0);}

int main(){
  cin >> n >> m;
  REP(i,m) scanf("%d%d", a+i, b+i);

  REP(i,m) if (b[i]) vs.pb(i); else vr.pb(i);
  sort(vs.begin(), vs.end(), [&](int x, int y){return a[x] < a[y];});
  sort(vr.begin(), vr.end(), [&](int x, int y){return a[x] < a[y];});
  reverse(vr.begin(), vr.end());
  
  REP(i,vs.size()) cnt[i] = i, sol[vs[i]] = {i+1, i+2};

  int poin = (int)vs.size()-1;
  for (auto x : vr){ //TRACE(vs.size());
    while (poin >= 0 && (cnt[poin] <= 0 || a[vs[poin]] > a[x])) --poin;
    if (poin < 0) imp();
    sol[x] = {cnt[poin]--, poin+2};
  }

  REP(i,m) printf("%d %d\n", sol[i].x, sol[i].y);
  
  return 0;
}