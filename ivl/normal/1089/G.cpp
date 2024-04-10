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

vector<int> svi;

int calc(int k){
  int sum = 0;
  REP(i,7) sum += svi[i];
  int sol = (k / sum) * 7;
  k %= sum;
  if (k == 0){
    for (int i = 6; svi[i] == 0; --i)
      --sol;
  } else {
    for (int i = 0; k != 0; ++i)
      k -= svi[i], ++sol;
  } return sol;
}

int k;

void solve(){
  cin >> k;
  svi = vector<int>(7);
  REP(i,7) cin >> svi[i];
  int sol = 1e9;
  REP(i,7){
    sol = min(sol, calc(k));
    svi.insert(svi.begin(), svi.back());
    svi.pop_back();
  } cout << sol << endl;
}

int main(){
  ios_base::sync_with_stdio(false);

  int t;
  cin >> t;
  REP(i,t) solve();

  return 0;
}