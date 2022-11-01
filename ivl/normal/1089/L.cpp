#include <algorithm>
#include <vector>
#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <cassert>

#define FOR(i,a,b) for (int i = (a); i < (b); ++i)
#define REP(i,n) FOR(i,0,n)

#define pb push_back
#define x first
#define y second

#define TRACE(x) cerr << #x << " = " << x << endl
#define _ << " _ " <<

using namespace std;

typedef pair<int, int> pii;
typedef long long ll;

int n, k;
int a[100005];
int b[100005];

int best[100005];
bool taken[100005];

int main(){

  cin >> n >> k;
  REP(i,n) cin >> a[i];
  REP(i,n) cin >> b[i];

  memset(best, -1, sizeof best);
  REP(i,n){
    if (best[a[i]] == -1 || b[best[a[i]]] < b[i])
      best[a[i]] = i;
  }

  int cnt = 0;
  FOR(i,1,k+1) if (best[i] != -1) ++cnt, taken[best[i]] = true;

  vector<int> all;
  REP(i,n) if (!taken[i]) all.pb(b[i]);
  sort(all.begin(), all.end());

  ll sum = 0;
  REP(i,k-cnt) sum += all[i];
  cout << sum << endl;

  return 0;
}