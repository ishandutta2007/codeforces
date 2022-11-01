#include <bits/stdc++.h>

#define FOR(i,a,b) for (int i = (int)(a); i < (int)(b); ++i)
#define REP(i,n) FOR(i,0,n)
#define pb push_back
#define ll long long
#define pii pair < int, int >
#define x first
#define y second

#define TRACE(x) cerr << #x << " = " << x << endl
#define _ << " _ " <<

using namespace std;

void imp(){
  cout << -1 << endl;
  exit(0);
}

int d, n, m;
int x[200005], p[200005];

int main(){

  cin >> d >> n >> m;
  REP(i,m) scanf("%d%d", x+i, p+i);

  vector < pii > sweep;
  REP(i,m) sweep.pb({x[i], p[i]}), sweep.pb({x[i]+n, -p[i]});
  sweep.pb({d, 0});

  sort(sweep.begin(), sweep.end());
  int pos = 0, can = n;
  multiset < ll > ref;
  ll R = 0;
  for (auto t : sweep){
    int x = t.x, y = t.y;
    if (can+pos >= x) can -= x-pos, pos = x;
    else pos += can, can = 0;
    if (x != pos){
      if (ref.empty()) imp();
      R += (x-pos) * *ref.begin();
      pos = x;
    }
    if (y == 0) break;
    if (y > 0) ref.insert(y);
    if (y < 0) ref.erase(ref.find(-y));
  } cout << R << endl;
  
  return 0;
}