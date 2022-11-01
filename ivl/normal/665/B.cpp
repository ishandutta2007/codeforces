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

int n, m, k;
vector < int > p;

int main(){

  cin >> n >> m >> k;
  p.resize(k);
  REP(i,k) cin >> p[i];

  int cnt = 0;
  REP(ttt,n*m){
    int x;
    cin >> x;
    int pos = -1;
    REP(i,k) if (p[i] == x) pos = i;
    assert(pos != -1);
    cnt += pos+1;
    p.erase(p.begin() + pos);
    p.insert(p.begin(), x);
  } cout << cnt << endl;
  
  return 0;
}