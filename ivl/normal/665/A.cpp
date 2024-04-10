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

  int a, ta;
  int b, tb;
  int h, m;
  char ctmp;
  cin >> a >> ta;
  cin >> b >> tb;
  cin >> h >> ctmp >> m;

  int t1 = h*60+m, t2 = t1+ta;
  int cnt = 0;

  for (int i = 5*60; i < 1440; i += b)
    if (i < t2 && i+tb > t1) ++cnt;

  cout << cnt << endl;

  return 0;
}