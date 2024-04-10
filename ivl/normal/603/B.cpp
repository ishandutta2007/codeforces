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
int p, k;

ll mul(ll a, ll b){return (a*b)%Mod;}
ll add(ll a, ll b){a+=b; if (a>=Mod) return a-Mod; return a;}
ll pot(ll a, ll x){
  ll r = 1;
  while (x){
    if (x&1) r = mul(r, a);
    a = mul(a, a);
    x >>= 1;
  } return r;
}

bool bio[1000005];
void run(int id){
  while (!bio[id]++) id = (int)(((ll)id*k)%p);
}

int main(){
  cin >> p >> k;

  if (k == 0){
    cout << pot(p, p-1) << endl;
    return 0;
  }

  int cnt = 0;
  REP(i,p) if (!bio[i]) ++cnt, run(i);

  cout << pot(p, cnt - (k != 1)) << endl;
  
  return 0;
}