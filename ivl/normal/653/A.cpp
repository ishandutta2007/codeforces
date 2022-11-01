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
int a[1<<20];
int cnt[1<<20];

int main(){
  ios_base::sync_with_stdio(false);

  cin >> n;
  REP(i,n) cin >> a[i], ++cnt[a[i]];

  REP(i,1<<10) if (cnt[i] && cnt[i+1] && cnt[i+2]){cout << "YES\n"; return 0;}
  cout << "NO\n";

  return 0;
}