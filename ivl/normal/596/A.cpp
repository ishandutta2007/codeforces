#include <bits/stdc++.h>

#define FOR(i,a,b) for (int i = (int)(a); i < (int)(b); ++i)
#define REP(i,n) FOR(i,0,n)
#define pii pair < int, int >
#define x first
#define y second

using namespace std;

void imp(){cout << -1 << endl; exit(0);}

int n;
pii pt[10];

int main(){
  cin >> n;
  REP(i,n) cin >> pt[i].x >> pt[i].y;
  if (n <= 1) imp();
  if (n == 2 && (pt[0].x == pt[1].x || pt[0].y == pt[1].y)) imp();
  pii a = {1001, 1001}, b = {-1001, -1001};
  REP(i,n){
    pii t = pt[i];
    if (a.x > t.x) a.x = t.x;
    if (a.y > t.y) a.y = t.y;
    if (b.x < t.x) b.x = t.x;
    if (b.y < t.y) b.y = t.y;
  } if (a.x == b.x || a.y == b.y) imp();
  cout << (b.x-a.x) * (b.y-a.y) << endl;
  return 0;
}