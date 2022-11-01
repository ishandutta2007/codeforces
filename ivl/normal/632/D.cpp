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

int n, m;
int a[1000005];

int cnt[1000005];
int cnt2[1000005];

int main(){
  //ios_base::sync_with_stdio(false);

  cin >> n >> m;
  REP(i,n) scanf("%d", a+i);

  int r = 0, l = 1;
  REP(i,n) if (a[i] <= m) ++cnt[a[i]];
  FOR(i,1,m+1) for (int j = i; j <= m; j += i) cnt2[j] += cnt[i];
  REP(i,m+1) if (cnt2[i] > r) r = cnt2[i], l = i;

  cout << l << " " << r << endl;
  REP(i,n) if (l % a[i] == 0) printf("%d ", i+1); cout << endl;
  
  return 0;
}