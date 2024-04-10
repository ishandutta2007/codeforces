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

int n, q;
pair < pair < char, char >, char > Q[1<<20];

int dp(int len, char let){
  static int memo[200][300];
  static bool bio[200][300];
  if (len == n) return 1;
  int &r = memo[len][(int)let];
  if (bio[len][(int)let]++) return r;
  r = 0;

  REP(i,q) if (Q[i].y == let) r += dp(len+1, Q[i].x.x);
  return r;
}

int main(){
  ios_base::sync_with_stdio(false);

  cin >> n >> q;
  REP(i,q){
    string s;
    cin >> s;
    Q[i].x.x = s[0];
    Q[i].x.y = s[1];
    cin >> Q[i].y;
  }

  cout << dp(1, 'a') << endl;

  return 0;
}