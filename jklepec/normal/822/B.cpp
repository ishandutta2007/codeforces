#include <bits/stdc++.h>
using namespace std;

#define FOR(i, a, b) for(int i = a; i < b; ++i)
#define REP(i, n) FOR(i, 0, n)
#define _ << " " <<

typedef long long ll;
typedef pair<int, int> point;



int main() {
  int n, m ; cin >> n >>m;

  string s, t;
  cin >> s >> t;

  int best = s.size() + 1, ind = 0;

  REP(i, t.size() - s.size() + 1) {
    int k = 0;
    REP(j, s.size()) {
      if(s[j] != t[i + j]) k++;
    }

    if(k < best) {
      best = k;
      ind = i;
    }
  }

  cout << best << endl;

  REP(i, s.size()) {
    if(s[i] != t[i + ind]) cout << i + 1 << " ";
  }
}