#include <bits/stdc++.h>

#define FOR(i,a,b) for (int i = (int)(a); i < (int)(b); ++i)
#define REP(i,n) FOR(i,0,n)
#define pb push_back
#define x first
#define y second

#define TRACE(x) cerr << #x << " = " << x << endl
#define _ << " _ " <<

using namespace std;

typedef long long ll;
typedef pair < int, int > pii;

int main(){
  ios_base::sync_with_stdio(false);

  int n;
  cin >> n;

  ll curr = 2;
  ll level = 1;
  REP(i,n){
    ll target = level*(level+1);
    cout << target*(level+1) - curr/level << endl;
    curr = target;
    ++level;
  }

  return 0;
}