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
int t[5005];

int cnt[5005];
int id;

int out[5005];

int main(){
  ios_base::sync_with_stdio(false);

  cin >> n;
  REP(i,n) cin >> t[i];

  REP(i,n){
    memset(cnt, 0, sizeof cnt);
    id = 0;
    FOR(j,i,n){
      ++cnt[t[j]];
      if (cnt[t[j]] > cnt[id]) id = t[j];
      if (cnt[t[j]] == cnt[id] && t[j] < id) id = t[j];
      ++out[id];
    }
  }

  FOR(i,1,n+1) cout << out[i] << " "; cout << endl;
  
  return 0;
}