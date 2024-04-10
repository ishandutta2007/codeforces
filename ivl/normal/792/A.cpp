#include <bits/stdc++.h>

#define FOR(i,a,b) for (int i = (int)(a); i < (int)(b); ++i)
#define REP(i,n) FOR(i,0,n)
#define pb push_back
#define x first
#define y second

#define TRACE(x) cerr << #x << " = " << x << endl
#define _ << " _ " <<

using namespace std;

typedef pair<int, int> pii;
typedef long long ll;

int n;
int a[200005];

int main(){
  ios_base::sync_with_stdio(false);

  cin >> n;
  REP(i,n) cin >> a[i];
  sort(a, a+n);
  int dis = 2e9+5;
  int cnt = -1;
  REP(i,n-1){
    if (a[i+1]-a[i] < dis) dis = a[i+1]-a[i], cnt = 0;
    if (a[i+1]-a[i] == dis) ++cnt;
  }
  cout << dis << " " << cnt << endl;

  return 0;
}