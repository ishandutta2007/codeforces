#include <bits/stdc++.h>

#define FOR(i,a,b) for (int i = (int)(a); i < (int)(b); ++i)
#define REP(i,n) FOR(i,0,n)
#define pb push_back
#define ll long long
#define pii pair < int, int >
#define x first
#define y second

#define TRACE(x) cerr << #x << " = " << x << endl
#define _ << " _ " <<

using namespace std;

const int Mod = 1000000007;

int n, m;
string s;
int k;

int limit, DEL;

ll dp(int id, int del, bool used){
  if (id > k || del > k || del < 0) return 0;
  if (id == k && used) return !del;
  static bool bio[2005][2005][2];
  static ll memo[2005][2005][2];
  ll &r = memo[id][del][used];
  if (bio[id][del][used]++) return r;

  r += dp(id+1, del+1, used);
  r += dp(id+1, del-1, used);
  if (!used && del >= limit) r += dp(id, del+DEL, true);
  r %= Mod;
  return r;
}

int main(){
  cin >> n >> m >> s;
  k = n-m;

  REP(i,m){
    if (s[i] == '(') ++DEL;
    else --DEL;
    limit = max(limit, -DEL);
  }

  cout << dp(0, 0, false) << endl;
  
  return 0;
}