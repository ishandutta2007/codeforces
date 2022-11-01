#include <bits/stdc++.h>

#define FOR(i,a,b) for (int i = (int)(a); i < (int)(b); ++i)
#define REP(i,n) FOR(i,0,n)
#define ll long long
#define pb push_back
#define pii pair < int, int >
#define x first
#define y second

#define TRACE(x) cerr << #x << " = " << x << endl
#define _ << " _ " <<

using namespace std;

int n;
string s[500005];

bool cmp(const string &a, const string &b){
  return a+b < b+a;
}

int main(){
  ios_base::sync_with_stdio(false);
  
  cin >> n;
  REP(i,n) cin >> s[i];

  sort(s, s+n, cmp);
  REP(i,n) cout << s[i]; cout << endl;
  
  return 0;
}