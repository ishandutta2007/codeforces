#include <bits/stdc++.h>
using namespace std;

#define FOR(i, a, b) for(int i = a; i < b; ++i)
#define REP(i, n) FOR(i, 0, n)

string s[110];

int main() {
  int n; cin >> n;
  string a;
  cin >> a;
  int uk = 0;
  REP(i, n) cin >> s[i];
  REP(i, n) {
    if(s[i] == "") continue;
    if(s[i].substr(0, 3) == a) {
      int found = -1;
      REP(j, n) {
        if(s[j] == "") continue;
        if(s[j].substr(0, 3) == s[i].substr(5, 3)) {
          s[j] = "";
          found = i;
          break;
        }
      }
      if(found == -1) uk ++;
    }
  }
  if(!uk) {
    cout << "home";
  }
  else {
    cout << "contest";
  }
}