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

const int Mod = 998244353;
int add(int a, int b){a += b; return a<Mod ? a : a-Mod;}
int mul(int a, int b){return (int)((ll)a*b%Mod);}
int pot(int a, int b){
  int r = 1;
  while (b){
    if (b&1) r = mul(r, a);
    a = mul(a, a), b >>= 1;
  } return r;
}
int inv(int a){return pot(a, Mod-2);}

int fact[1000005];
int finv[1000005];

int choose(int a, int b){
  return mul(fact[a], mul(finv[b], finv[a-b]));
}

int n;

// p = nesto + tocka + padajuce
// sljedeca = nesto + tocka' + rastuce, tocka' je iz padajuce, min koja je veca od tocka
// tocka' + rastuce se ne ponasa nimalo ko p (valjda)
// dakle matchamo p sa nesto iz sljedeca
// broj matcheva = #nesto + 1 = n - #padajuce
// sto ako je cijeli padajuc ?
// a bo bumo to kasnije popravili

int main(){
  ios_base::sync_with_stdio(false);

  fact[0] = 1;
  REP(i,1e6+4) fact[i+1] = mul(fact[i], i+1);
  REP(i,1e6+5) finv[i] = inv(fact[i]);

  cin >> n;

  int sol = 1;
  FOR(droplen,1,n)
    sol = add(sol, mul(choose(n, droplen+1), mul(fact[n-droplen-1], mul(droplen, n-droplen))));

  cout << sol << endl;
  
  return 0;
}