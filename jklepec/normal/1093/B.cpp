#include <bits/stdc++.h>
using namespace std;

#define FOR(i, a, b) for(int i = a; i < b; ++i)
#define REP(i, n) FOR(i, 0, n)
#define _ << " " <<
#define sz(x) ((int) x.size())
#define pb push_back

typedef long long ll;
typedef pair<int, int> pii;

int a[26];

int main() {
  int t; cin >> t;
  while(t --) {
    string s; cin >> s;

    int n = s.size();

    sort(s.begin(), s.end());
    if(s[0] == s[n - 1]) {
      cout << -1 << endl;
    }
    else {
      cout << s << endl;
    }
  }
}