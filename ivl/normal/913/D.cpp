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

int n, T;
pair<pii, int> at[200005];

bool check(int num){
  int cnt = 0, sum = 0;
  REP(i,n)
    if (at[i].x.x >= num){
      sum += at[i].x.y;
      ++cnt;
      if (cnt == num) break;
    }
  if (cnt != num) return false;
  if (sum > T) return false;
  return true;
}

int main(){
  ios_base::sync_with_stdio(false);

  cin >> n >> T;
  REP(i,n) cin >> at[i].x.x >> at[i].x.y, at[i].y = i;
  sort(at, at+n, [](pair<pii, int> x, pair<pii, int> y){return x.x.y < y.x.y;});

  int lo = 0, hi = n, mid;
  while (lo != hi){
    mid = (lo+hi+1)/2;
    if (check(mid)) lo = mid;
    else hi = mid-1;
  }

  cout << lo << endl << lo << endl;
  if (lo == 0) return 0;
  vector<int> all;
  int cnt = 0;
  REP(i,n)
    if (at[i].x.x >= lo){
      cout << at[i].y+1 << " ";
      ++cnt;
      if (cnt == lo) break;
    } cout << endl;

  return 0;
}