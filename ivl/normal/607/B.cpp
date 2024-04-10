#include <bits/stdc++.h>

#define FOR(i,a,b) for (int i = (int)(a); i < (int)(b); ++i)
#define REP(i,n) FOR(i,0,n)
#define ll long long
#define pb push_back
#define pii pair < int, int >
#define x first
#define y second

#define TRACE(x) cerr << #x << " _ " << x << endl
#define _ << " _ " <<

using namespace std;

const int oo = 1000000000;

int n;
int c[505];

void minaj(int &a, int b){if (a > b) a = b;}

int dp(int a, int b){
  static bool bio[505][505];
  static int memo[505][505];
  if (a >= b) return 1;
  int &r = memo[a][b];
  if (bio[a][b]++) return r;
  r = oo;

  if (c[a] == c[b]) minaj(r, dp(a+1, b-1));
  FOR(i,a,b) minaj(r, dp(a, i)+dp(i+1, b));
  return r;
}

int main(){
  ios_base::sync_with_stdio(false);

  cin >> n;
  REP(i,n) cin >> c[i];
  cout << dp(0, n-1) << endl;

  return 0;
}