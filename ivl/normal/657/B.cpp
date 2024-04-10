#include <bits/stdc++.h>

#define FOR(i,a,b) for (int i = (int)(a); i < (int)(b); ++i)
#define REP(i,n) FOR(i,0,n)
#define ll long long
#define pb push_back
#define pii pair < int, int >
#define x first
#define y second

#define TRACE(x) cerr << #x << " = " << x << endl
#define _ << " _ " <<

using namespace std;

int n, k;
ll a[1<<20];

const int BLA = 1<<21;
bitset < BLA > B1, B2;

void Add(bitset < BLA > &B, ll v, int p){
  while (v){
    if (v&1){
      int pp = p;
      while (B[pp]) B[pp++] = 0;
      B[pp] = 1;
    }
    v /= 2, ++p;
  }
}

int main(){
  ios_base::sync_with_stdio(false);

  cin >> n >> k;
  REP(i,n+1) cin >> a[i];
  REP(i,n+1){
    if (a[i] > 0) Add(B1, a[i], i);
    else Add(B2, -a[i], i);
  }

  bool poz = true;
  for (int i = BLA-1; i >= 0; --i)
    if (B1[i] != B2[i]){poz = B1[i]; break;}

  if (!poz) swap(B1, B2);
  for (int i = BLA-1; i >= 0; --i)
    if (B2[i]){
      int ii = i;
      while (!B1[ii]) B1[ii++] = 1;
      B1[ii] = 0;
    }

  int lo = 0, hi = BLA-1;
  while (!B1[lo]) ++lo;
  while (!B1[hi]) --hi;
  
  if (hi-lo > 50){cout << 0 << endl; return 0;}

  ll P = 0;
  FOR(i,lo,hi+1) if (B1[i]) P |= (1LL << (i-lo));
  if (!poz) P = -P;
  int deg = lo;
  int sol = 0;
  
  while (abs(P) <= 4LL*k && deg >= 0){

    if (deg <= n && -k <= a[deg]-P && a[deg]-P <= k)
      if (deg != n || a[deg] != P) ++sol;
    
    P *= 2;
    --deg;
  } cout << sol << endl;
  
  return 0;
}