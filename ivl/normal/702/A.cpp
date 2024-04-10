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

int n;
int a[100005];

int main(){
  ios_base::sync_with_stdio(false);

  cin >> n;
  REP(i,n) cin >> a[i];

  int r = 1;
  int cr = 1;
  FOR(i,1,n){
    if (a[i] > a[i-1]) ++cr; else cr = 1;
    r = max(r, cr);
  } cout << r << endl;

  return 0;
}