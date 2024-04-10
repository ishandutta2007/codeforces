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

  ll r = 0;
  REP(t,31){
    int b = 1<<t;
    map < int, int > M;
    REP(i,n) if (a[i] < b) r += M[a[i]], ++M[b-a[i]];
  } cout << r << endl;

  return 0;
}