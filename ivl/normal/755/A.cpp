#include <bits/stdc++.h>

#define FOR(i,a,b) for (int i = (int)(a); i < (int)(b); ++i)
#define REP(i,n) FOR(i,0,n)
#define x first
#define y second
#define pb push_back

#define TRACE(x) cerr << #x << " = " << x << endl
#define _ << " _ " <<

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

bool prime(int x){
  for (int i = 2; i*i <= x; ++i)
    if (x%i == 0)
      return false;
  return true;
}

int main(){
  ios_base::sync_with_stdio(false);

  int n;
  cin >> n;
  FOR(m,1,1001) if (!prime(n*m+1)){cout << m << endl; return 0;}
  assert(false);
  
  return 0;
}