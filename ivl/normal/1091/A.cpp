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
typedef pair<int, int> pii;

int main(){
  ios_base::sync_with_stdio(false);

  int y, b, r;
  cin >> y >> b >> r;
  y = min(y, min(b-1, r-2));
  cout << y*3+3 << endl;
  
  return 0;
}