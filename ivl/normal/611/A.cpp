#include <bits/stdc++.h>

#define FOR(i,a,b) for (int i = (int)(a); i < (int)(b); ++i)
#define REP(i,n) FOR(i,0,n)
#define pb push_back
#define pii pair < int, int >
#define x first
#define y second
#define ll long long

#define TRACE(x) cerr << #x << " = " << x << endl
#define _ << " _ " <<

using namespace std;

int main(){
  int start = 4;
  int x;
  string s;
  cin >> x >> s >> s;
  if (s == "week"){
    int r = 0;
    REP(i,366){
      if (start == x-1) ++r;
      start = (start+1)%7;
    } cout << r << endl;
  } else {
    if (x <= 29) cout << 12 << endl;
    else if (x == 30) cout << 11 << endl;
    else cout << 7 << endl;
  }
  return 0;
}