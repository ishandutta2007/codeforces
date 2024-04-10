#include <bits/stdc++.h>

#define FOR(i,a,b) for (int i = (int)(a); i < (int)(b); ++i)
#define REP(i,n) FOR(i,0,n)
#define pb push_back
#define ll long long
#define x first
#define y second
#define pii pair < int, int >

#define TRACE(x) cerr << #x << " = " << x << endl
#define _ << " _ " <<

using namespace std;

const int Mod = 1000000007;

int m, d;
char a[2015];
char b[2015];
int l;

ll dp(bool aa, bool bb, int id, int x){
  static bool bio[2][2][2005][2005];
  static ll memo[2][2][2005][2005];
  ll &r = memo[aa][bb][id][x];
  if (bio[aa][bb][id][x]++) return r;
  r = 0;

  if (id >= l) return r = (!x && aa && bb);

  REP(bla,10){
    int xx = x + bla*m;
    int y = xx % 10;
    if ((l-id)%2 == 0 && y != d || (l-id)%2 == 1 && y == d) continue;
    bool aaa = aa, bbb = bb;
    if (y != a[id]) aaa = (a[id] < y);
    if (y != b[id]) bbb = (b[id] > y);
    r += dp(aaa, bbb, id+1, xx/10);
  } r %= Mod;
  return r;
  
}

int main(){

  scanf("%d%d%s%s", &m, &d, a, b);
  l = (int)strlen(a);
  reverse(a, a+l);
  reverse(b, b+l);
  REP(i,l) a[i] -= '0', b[i] -= '0';
  
  cout << dp(true, true, 0, 0) << endl;
  
  return 0;
}