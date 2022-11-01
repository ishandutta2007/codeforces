#include <bits/stdc++.h>

#define FOR(i,a,b) for (int i = (int)(a); i < (int)(b); ++i)
#define REP(i,n) FOR(i,0,n)
#define pb push_back
#define x first
#define y second

#define TRACE(x) cerr << setw(3) << setfill('0') << __LINE__ << ": " << #x << " = " << x << endl
#define _ << " _ " <<

using namespace std;

typedef long long ll;
typedef pair < int, int > pii;

int main(){
  ios_base::sync_with_stdio(false);

  int n, k;
  cin >> n >> k;

  int tmp = 4*60-k;
  int curr = 5;
  int sol = 0;
  while (curr <= 5*n && tmp-curr >= 0)
    tmp -= curr,
      ++sol,
      curr += 5;

  cout << sol << endl;

  return 0;
}