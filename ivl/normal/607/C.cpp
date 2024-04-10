#include <bits/stdc++.h>

#define FOR(i,a,b) for (int i = (int)(a); i < (int)(b); ++i)
#define REP(i,n) FOR(i,0,n)
#define ll long long
#define pb push_back
#define pii pair < int, int >
#define x first
#define y second

#define TRACE(x) cerr << #x << " _ " << x << endl
#define _ << " _ " <<

using namespace std;

const int P = 101;
const int Mod = 1000000009;

class mint{
public:
  ll x;
  mint(ll y = 0){y %= Mod; if (y < 0) y += Mod; x = y;}
};
mint operator+(mint a, mint b){return mint(a.x+b.x);}
mint operator-(mint a, mint b){return mint(a.x-b.x);}
mint operator*(mint a, mint b){return mint(a.x*b.x);}

int n;
string a, b;

mint h1[1<<20];
mint h2[1<<20];

mint pot[1<<20];
mint segm(mint *h, int lo, int hi){
  return h[hi+1] - h[lo] * pot[hi-lo+1];
}

void imp(){cout << "NO\n"; exit(0);}

int main(){
  ios_base::sync_with_stdio(false);

  pot[0] = 1;
  FOR(i,1,1<<20) pot[i] = pot[i-1] * P;

  cin >> n >> a >> b;
  reverse(b.begin(), b.end());
  --n;
  map < char, char > ch = {{'N', 'S'}, {'S', 'N'}, {'W', 'E'}, {'E', 'W'}};
  REP(i,n) b[i] = ch[b[i]];

  REP(i,n) h1[i+1] = h1[i] * P + a[i];
  REP(i,n) h2[i+1] = h2[i] * P + b[i];

  //REP(i,n) if (segm(h1, 0, i).x == segm(h2, n-1-i, n-1).x) imp();
  REP(i,n) if (segm(h1, n-1-i, n-1).x == segm(h2, 0, i).x) imp();
  cout << "YES\n";
  
  return 0;
}