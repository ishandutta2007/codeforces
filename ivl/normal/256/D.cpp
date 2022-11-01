#include <bits/stdc++.h>

#define FOR(i,a,b) for (int i = (int)(a); i < (int)(b); ++i)
#define REP(i,n) FOR(i,0,n)
#define x first
#define y second
#define pb push_back

#define TRACE(x) cerr << #x << " = " << x << endl
#define _ << " _ " <<

using namespace std;

typedef long long ll;
typedef pair < int, int > pii;

const int Mod = 777777777;
const ll Mod2 = (ll)Mod * Mod;

int n, k;

inline int add(int a, int b){a += b; if (a >= Mod) return a-Mod; return a;}
inline int mul(int a, int b){return (int)(((ll)a*b)%Mod);}

int choose[1005][1005];

const int MAX = 300;

int memo[MAX][MAX][MAX];
int dp(int left, int big, int pos){
  if (big == 0) return left == 0 && pos == 0;
  
  if (memo[left][big][pos] != -1) return memo[left][big][pos];

  ll rr = 0;

  REP(i,pos+1) if (i != big){
    rr += (ll)choose[pos][i] * dp(left, big-1, pos-i);
    if (rr >= Mod2) rr -= Mod2;
  }
  if (left >= big) rr += (ll)choose[left][big] * dp(left-big, big-1, pos);
  return memo[left][big][pos] = (int)(rr%Mod);
  
}

int main(){
  ios_base::sync_with_stdio(false);

  memset(memo, -1, sizeof memo);

  choose[0][0] = 1;
  FOR(i,1,1000) REP(j,1000){
    if (j == 0) choose[i][j] = 1;
    else choose[i][j] = add(choose[i-1][j-1], choose[i-1][j]);
  }

  cin >> n >> k;
  cout << mul(choose[n][k], dp(n-k, n, k)) << endl;

  return 0;
}