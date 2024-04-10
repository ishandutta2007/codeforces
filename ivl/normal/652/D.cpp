#include <bits/stdc++.h>

#define FOR(i,a,b) for (int i = (int)(a); i < (int)(b); ++i)
#define REP(i,n) FOR(i,0,n)
#define ll long long
#define pb push_back
#define pii pair < int, int >
#define x first
#define y second

#define TRACE(x) cerr << #x << " _ " << x << endl
#define _ << " _ " <<

using namespace std;

int n;
pair < pii, int > a[1<<20];
int out[1<<20];

const int bla = 1<<20;
int loga[bla];
void Add(int t){ ++t;
  for (; t < bla; t += t&-t) ++loga[t];
}
int Get(int t){ ++t;
  int r = 0;
  for (; t; t -= t&-t) r += loga[t];
  return r;
}

int main(){
  ios_base::sync_with_stdio(false);

  cin >> n;
  REP(i,n){
    cin >> a[i].x.x >> a[i].x.y;
    a[i].y = i;
  }
  vector < int > sazm;
  REP(i,n) sazm.pb(a[i].x.x), sazm.pb(a[i].x.y);
  sort(sazm.begin(), sazm.end());
  sazm.erase(unique(sazm.begin(), sazm.end()), sazm.end());
  REP(i,n) a[i].x.x = (int)(lower_bound(sazm.begin(), sazm.end(), a[i].x.x)-sazm.begin());
  REP(i,n) a[i].x.y = (int)(lower_bound(sazm.begin(), sazm.end(), a[i].x.y)-sazm.begin());

  sort(a, a+n, [](pair < pii, int > x, pair < pii, int > y){return x.x.y < y.x.y;});
  REP(i,n){
    out[a[i].y] = i-Get(a[i].x.x-1);
    Add(a[i].x.x);
  }

  REP(i,n) cout << out[i] << endl;

  return 0;
}