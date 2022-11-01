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

int n;
int p[200005];
int b[200005];

bool bio[200005];

int main(){
  ios_base::sync_with_stdio(false);

  cin >> n;
  REP(i,n) cin >> p[i], --p[i];
  REP(i,n) cin >> b[i];

  int sol = 0;
  REP(i,n) if (!bio[i]){
    ++sol;
    for (int x = i; !bio[x]++; x = p[x]);
  }

  if (sol == 1) sol = 0;

  int tmp = 0;
  REP(i,n) tmp += b[i];
  if (tmp%2 == 0) ++sol;

  cout << sol << endl;
  
  return 0;
}