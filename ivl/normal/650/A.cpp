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

int main(){
  //ios_base::sync_with_stdio(false);

  ll r = 0;

  map < int, int > mx, my;
  map < pii, int > m;
  
  int n;
  cin >> n;
  REP(i,n){
    int x, y;
    scanf("%d%d", &x, &y);
    r += mx[x]+my[y];
    ++mx[x], ++my[y];
    r -= m[{x,y}];
    ++m[{x,y}];
  } cout << r << endl;
  
  return 0;
}