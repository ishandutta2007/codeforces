#include <bits/stdc++.h>

#define FOR(i,a,b) for (int i = (int)(a); i < (int)(b); ++i)
#define REP(i,n) FOR(i,0,n)
#define pii pair < int, int >
#define pb push_back
#define x first
#define y second
#define ll long long

#define TRACE(x) cerr << #x << " = " << x << endl
#define _ << " _ " <<

using namespace std;

int n, k;
vector < pii > sweep;

vector < pii > vec;

bool intersect(pii a, pii b){
  if (b.x <= a.x && a.x <= b.y) return true;
  if (b.x <= a.y && a.y <= b.y) return true; swap(a, b);
  if (b.x <= a.x && a.x <= b.y) return true;
  if (b.x <= a.y && a.y <= b.y) return true; swap(a, b);
  return false;
}

pii join(pii a, pii b){return {min(a.x, b.x), max(a.y, b.y)};}

int main(){

  cin >> n >> k;
  REP(i,n){
    int a, b;
    scanf("%d%d", &a, &b);
    sweep.pb({a, -1});
    sweep.pb({b, 1});
  } sort(sweep.begin(), sweep.end());

  int prev = -1, cnt = 0;
  for (auto x : sweep){
    if (cnt >= k) vec.pb({prev, x.x});
    cnt -= x.y;
    prev = x.x;
  }

  vector < pii > sol;
  for (auto x : vec){
    while (!sol.empty()){
      if (!intersect(x, sol.back())) break;
      x = join(x, sol.back());
      sol.pop_back();
    } sol.pb(x);
  } cout << sol.size() << endl;
  for (auto x : sol) printf("%d %d\n", x.x, x.y);
  
  return 0;
}