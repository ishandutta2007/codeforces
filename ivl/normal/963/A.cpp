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

const int Mod = 1e9 + 9;

int mul(int a, int b){return (int)((ll)a*b%Mod);}

int pot(int a, int b){
  int r = 1;
  while (b){
    if (b&1) r = mul(r, a);
    a = mul(a, a), b >>= 1;
  } return r;
}

int inv(int a){return pot(a, Mod-2);}

int n, a, b, k;
string s;

int main(){
  ios_base::sync_with_stdio(false);

  cin >> n >> a >> b >> k;
  cin >> s;

  ll sol = 0;
  REP(i,k) sol += (s[i] == '+' ? +1 : -1) * mul(pot(a, k-1-i), pot(b, i));
  sol %= Mod;
  if (sol < 0) sol += Mod;

  int num = (n+1) / k;
  int aa = pot(a, k);
  int bb = pot(b, k);
  int sol2;
  if (aa != bb) sol2 = mul((pot(aa, num) - pot(bb, num)), inv(aa - bb));
  else sol2 = mul(num, pot(aa, num-1));
  if (sol2 < 0) sol2 += Mod;

  cout << mul((int)sol, (int)sol2) << endl;

  return 0;
}