#include <bits/stdc++.h>
using namespace std;

#define FOR(i, a, b) for(int i = a; i < b; ++i)
#define REP(i, n) FOR(i, 0, n)
#define pb push_back
#define _ << " " <<
#define sz(x) ((int) x.size())

typedef long long ll;
typedef pair<int, int> point;

int main() {
  ios_base::sync_with_stdio(false); cin.tie(0);

  int n; cin >> n;

  string a, b; cin >> a >> b;
  ll sol = 0;

  ll zeros = 0;
  ll zerosa = 0;

  REP(i, n) {
    if(a[i] == '0' && b[i] == '0') zeros ++;
    if(a[i] == '0') zerosa ++;
  }

  REP(i, n) {
    if(a[i] == '1') {
      if(b[i] == '1') {
        sol += zeros;
      }
      else {
        sol += zerosa;
      }
    }
  }

  cout << sol;
}