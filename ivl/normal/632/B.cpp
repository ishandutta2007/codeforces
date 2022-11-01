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

int n;
int p[500005];
string s;

ll solve(){
  ll cr = 0;
  REP(i,n) if (s[i] == 'B') cr += p[i];
  ll r = cr;
  REP(i,n){
    if (s[i] == 'B') cr -= p[i];
    else cr += p[i];
    r = max(r, cr);
  } return r;
}

int main(){

  cin >> n;
  REP(i,n) scanf("%d", p+i);
  cin >> s;

  ll r = solve();
  reverse(p, p+n);
  reverse(s.begin(), s.end());
  r = max(r, solve());
  cout << r << endl;
  
  return 0;
}