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

int n, m;
int p[1<<20];
int p2[1<<20];
pii t[1<<20];

int main(){
  ios_base::sync_with_stdio(false);

  cin >> n >> m;
  REP(i,n) cin >> p[i], --p[i];
  REP(i,n) p2[p[i]] = i;
  REP(i,m){
    cin >> t[i].x >> t[i].y;
    t[i].x = p2[t[i].x-1];
    t[i].y = p2[t[i].y-1];
    if (t[i].x > t[i].y) swap(t[i].x, t[i].y);
  } sort(t, t+m, [](pii a, pii b){return a.y < b.y;});

  int limit = 0, poin = 0;
  ll r = 0;
  REP(i,n){
    while (poin < m && t[poin].y <= i) limit = max(limit, 1+t[poin++].x);
    r += i-limit+1;
  } cout << r << endl;
  
  return 0;
}