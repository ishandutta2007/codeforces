#include <bits/stdc++.h>

#define FOR(i,a,b) for (int i = (int)(a); i < (int)(b); ++i)
#define REP(i,n) FOR(i,0,n)
#define x first
#define y second
#define pb push_back

#define TRACE(x) cerr << #x << " = " << x << endl
#define _ << " _ " <<

using namespace std;

typedef long long ll;
typedef pair < int, int > pii;

int n, c;
int x, y;

int f(pii a, pii b){
  if (a.x < 0 && b.x < 0) return 0;
  if (a.y < 0 && b.y < 0) return 0;
  if (a.x >= n && b.x >= n) return 0;
  if (a.y >= n && b.y >= n) return 0;

  if (a.x > b.x) swap(a, b);
  if (a.y > b.y) a.y = n-1-a.y, b.y = n-1-b.y;

  if (a.x < 0) a.y -= a.x, a.x = 0;
  if (a.y < 0) a.x -= a.y, a.y = 0;

  if (b.x >= n) b.y -= b.x-n+1, b.x = n-1;
  if (b.y >= n) b.x -= b.y-n+1, b.y = n-1;

  return max(0, b.x-a.x+1);
  
}

int main(){
  ios_base::sync_with_stdio(false);

  cin >> n >> x >> y >> c;
  --x, --y;

  pii l, r, u, d;
  l = r = u = d = {x, y};
  int t = 0, s = 1;
  while (s < c){
    ++t;
    --l.y;
    ++r.y;
    --u.x;
    ++d.x;
    s += f(l, u);
    s += f(r, u);
    s += f(l, d);
    s += f(r, d);
    s -= f(l, l);
    s -= f(r, r);
    s -= f(d, d);
    s -= f(u, u);
  } cout << t << endl;
  
  return 0;
}