#include <bits/stdc++.h>

#define FOR(i,a,b) for (int i = (int)(a); i < (int)(b); ++i)
#define REP(i,n) FOR(i,0,n)

using namespace std;

int main(){
  int n;
  string s;
  cin >> n >> s;
  int ind = -1;
  REP(i,n-1) if (s[i] != s[i+1]) ind = i;
  if (ind == -1) cout << "NO" << endl;
  else cout << "YES" << endl << s.substr(ind, 2) << endl;
  return 0;
}