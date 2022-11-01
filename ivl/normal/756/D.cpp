#include <bits/stdc++.h>

#define FOR(i,a,b) for (int i = (int)(a); i < (int)(b); ++i)
#define REP(i,n) FOR(i,0,n)
#define pb push_back
#define x first
#define y second

#define TRACE(x) cerr << #x << " = " << x << endl
#define _ << " _ " <<

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

const int Mod = 1e9+7;
int add(int x, int y){x += y; if (x >= Mod) return x-Mod; return x;}
int mul(int x, int y){return (int)((ll)x*y%Mod);}
int sub(int x, int y){x -= y; if (x < 0) return x+Mod; return x;}

int n;
string s;

vector<int> red;

typedef int poly[5005];
poly all[33];
poly sum;

int choose[5005][5005];

int main(){
  ios_base::sync_with_stdio(false);

  REP(i,5005) REP(j,5005){
    if (i < j) choose[i][j] = 0;
    else if (j == 0 || j == i) choose[i][j] = 1;
    else choose[i][j] = add(choose[i-1][j], choose[i-1][j-1]);
  }

  cin >> n >> s;
  // n = 1000;
  // REP(i,n) s.pb('a' + (i%26));
  for (int i = 0, j = 0; i < n; i = j){
    while (j < n && s[i] == s[j]) ++j;
    red.pb(s[i]-'a');
  }

  all[26][0] = 1;
  sum[0] = 1;

  for (auto x : red){
    poly &a = all[x];
    poly tmp;
    tmp[0] = 0;
    REP(i,5004) tmp[i+1] = sub(sum[i], a[i]);
    REP(i,5005) sum[i] = sub(sum[i], a[i]);
    REP(i,5005) a[i] = tmp[i];
    REP(i,5005) sum[i] = add(sum[i], a[i]);
  }

  // REP(i,5) TRACE(sum[i]);

  int sol = 0;
  FOR(i,1,5005) sol = add(sol, mul(sum[i], choose[n-1][i-1]));
  cout << sol << endl;
  
  return 0;
}