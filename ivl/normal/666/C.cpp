#include <bits/stdc++.h>

#define FOR(i,a,b) for (int i = (int)(a); i < (int)(b); ++i)
#define REP(i,n) FOR(i,0,n)
#define ll long long
#define pb push_back
#define pair < int, int >
#define x first
#define y second

#define TRACE(x) cerr << #x << " = " << x << endl
#define _ << " _ " <<

using namespace std;

const int Mod = 1000000007;

int mul(int a, int b){return (int)(((ll)a*b)%Mod);}
int add(int a, int b){a += b; if (a >= Mod) return a-Mod; return a;}
int inv(int a){
  int x = Mod-2;
  int r = 1;
  while (x){
    if (x & 1) r = mul(r, a);
    a = mul(a, a);
    x >>= 1;
  } return r;
}
int pot(int a, int x){
  int r = 1;
  while (x){
    if (x & 1) r = mul(r, a);
    a = mul(a, a);
    x >>= 1;
  } return r;
}

int ga;
int fact[1<<18];
int finv[1<<18];

int choose(int a, int b){
  if (a < 0 || a < b) return 0;
  return mul(mul(fact[a], finv[b]), finv[a-b]);
}

vector < int > Calc(int l){
  vector < int > out(100005,0);
  FOR(i,1,100005){
    if (i < l) continue;
    //if (i == l){out[i] = 1; continue;}
    out[i] = add(choose(i-1, l-1), mul(ga, out[i-1]));
  }
  return out;
}

int m;
int l;
map < int, vector < int > > Msol;

int main(){
  ios_base::sync_with_stdio(false);

  ga = mul(26, inv(25));
  fact[0] = 1;
  FOR(i,1,1<<18) fact[i] = mul(i, fact[i-1]);
  REP(i,1<<18) finv[i] = inv(fact[i]);

  cin >> m;
  {string s; cin >> s; l = (int)s.size();}
  Msol[l] = Calc(l);

  REP(i,m){
    int t;
    cin >> t;
    if (t == 1){
      string s;
      cin >> s;
      l = (int)s.size();
      if (Msol.count(l) == 0) Msol[l] = Calc(l);
    } else {
      int n;
      cin >> n;
      if (n < l) cout << 0 << endl;
      else cout << mul(pot(25, n-l), Msol[l][n]) << endl;
    }
  }
  
  return 0;
}