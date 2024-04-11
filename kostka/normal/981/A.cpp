//Bartek Kostka
//  You are not prepared!

#include "bits/stdc++.h"

using namespace std;

#define x first
#define y second
#define SZ(x) int(x.size())
#define ll long long
#define pii pair <int, int>
#define vi vector <int>

bool check(string s) {
  string t = s;
  reverse(t.begin(), t.end());
  return s != t;
}

int main()
{
  ios_base::sync_with_stdio(0);
  string s;
  cin >> s;
  int res = 0;
  int n = SZ(s);
  for(int i=0; i<n; i++) {
    for(int j=1; j<=n-i; j++) {
      if(check(s.substr(i, j))) res = max(res, j);
    }
  }
  cout << res << "\n";
  return 0;
}