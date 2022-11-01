#include <bits/stdc++.h>

#define FOR(i,a,b) for (int i = (int)(a); i < (int)(b); ++i)
#define REP(i,n) FOR(i,0,n)
#define pb push_back
#define pii pair < int, int >
#define x first
#define y second
#define ll long long

#define TRACE(x) cerr << #x << " = " << x << endl
#define _ << " _ " <<

using namespace std;

int n;
string s;

const int Mod = 1000000007;

int dp(int p, int pr);
int dp2(int p, int pr){
  static int memo[5005][5005];
  static bool bio[5005][5005];
  int &r = memo[p][pr];
  if (bio[p][pr]++) return r;
  if (p > n) return 0;
  return r = (dp(p,pr) + dp2(p+1,pr))%Mod;
}

int bla[5005][5005];

int dp(int p, int pr){
  static int memo[5005][5005];
  static bool bio[5005][5005];
  int &r = memo[p][pr];
  if (bio[p][pr]++) return r;
  r = 0;
  if (p == n) return r=1;
  if (!s[p]) return r;

  ll rr = 0;

  int pn = p+p-pr-1;
  if (pn >= n) return r;
  /*bool y = true;
  REP(i,p-pr){
    if (s[pr+i] == s[p+i]) continue;
    if (s[pr+i] > s[p+i]) break;
    y = false; break;
    }*/
  if (bla[pr][p] > 0) rr += dp(pn+1, p);

  rr += dp2(pn+2, p);
  return r = rr%Mod;
  
}

int main(){

  cin >> n >> s;
  for (auto &x : s) x -= '0';

  for (int i = n; i >= 0; --i)
    for (int j = n; j >= 0; --j)
      if (s[i] != s[j]) bla[i][j] = (s[i] < s[j]) * (j - i);
      else bla[i][j] = bla[i+1][j+1] - 1;
      
  ll r = 0;
  REP(i,n) r += dp(i+1, 0);// TRACE(i+1 _ dp(i+1, 0));
  cout << r%Mod << endl;

  return 0;
}