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

int n;
int f[200005];
int g[200005];

int main(){

  cin >> n;
  REP(i,n) scanf("%d", f+i), --f[i], g[f[i]] = i;
  ll r = 0;
  REP(i,n-1) r += abs(g[i]-g[i+1]);
  cout << r << endl;
  
  return 0;
}