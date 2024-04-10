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

int n;
int a[5005];

int main(){
  cin >> n;
  REP(i,n) cin >> a[i];
  sort(a, a+n);

  ll big = 0;
  unordered_map < int, ll > M1;
  REP(i,n) REP(j,i) ++M1[a[i] - a[j]], ++big;

  unordered_map < int, ll > M2;
  for (auto aa : M1)
    for (auto b : M1)
      M2[aa.x+b.x] += aa.y*b.y;

  ll bla = 0;
  for (auto aa : M1)
    for (auto b : M2)
      if (aa.x-b.x > 0)
	bla += aa.y*b.y;

  cout << setprecision(30) << (double)bla / big / big / big << endl;
  
  return 0;
}