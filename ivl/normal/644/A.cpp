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

int out[105][105];

int main(){

  int n, a, b;
  cin >> n >> a >> b;
  if (n > a*b){cout << -1 << endl; return 0;}

  REP(i,n) out[i/b][(i/b)%2 ? (i%b) : ((b-i%b-1)%b)] = i+1;
  REP(i,a){
    REP(j,b) cout << out[i][j] << " "; cout << endl;
  }

  return 0;
}