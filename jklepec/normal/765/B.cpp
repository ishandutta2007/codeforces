#include <bits/stdc++.h>
using namespace std;

#define FOR(i, a, b) for(int i = a; i < b; ++i)
#define REP(i, n) FOR(i, 0, n)

#define _ << " " <<

typedef long long ll;
typedef pair<int, int> point;

int cookie = 1;
int bio[28];

int main() {
  string s; cin >> s;
  int n = s.size();

  REP(i, n) {
    REP(j, s[i] - 'a')
      if(!bio[j]) {
        cout << "NO";
        return 0;
      }
    bio[s[i] - 'a'] = cookie;
  }

  cout << "YES";
  return 0;
}