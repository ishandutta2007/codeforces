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

int main(){
  int n, p, q;
  cin >> n >> p >> q;
  string s;
  cin >> s;

  REP(a,101){
    if (n-a*p < 0) continue;
    if ((n-a*p)%q) continue;

    cout << a+(n-a*p)/q << endl;
    REP(i,a){REP(j,p) cout << s[j+i*p]; cout << endl;}
    REP(i,(n-a*p)/q){REP(j,q) cout << s[j+i*q+a*p]; cout << endl;}
    
    return 0;
  } cout << -1 << endl;
  
  return 0;
}