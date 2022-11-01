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

const int offset = (1<<15);

int n, k;
pii pt[offset];
int q;

int Start[offset];
int End[offset];
int Q[offset];
ll Ans[offset];

vector < pii > T[offset*2];
void Add(int id, int lo, int hi, int slo, int shi, pii v){
  if (lo > shi || hi < slo) return;
  if (lo >= slo && hi <= shi){
    T[id].pb(v);
    return;
  }
  int m = (lo+hi)/2;
  Add(id*2, lo, m, slo, shi, v);
  Add(id*2+1, m+1, hi, slo, shi, v);
}

class klasa{
public:
  ll val[1005];
  klasa(){memset(val, 0, sizeof val);}
  ll operator[](int x){return val[x];}
  void add(pii t){
    for (int i=k; i>=0; --i){
      if (i+t.x > k) continue;
      val[i+t.x] = max(val[i+t.x], val[i]+t.y);
    }
  }
  const static int p = 10000019;
  const static int Mod = 1000000007;
  ll mul(ll a, ll b){return (a*b)%Mod;}
  ll add(ll a, ll b){
    a += b;
    if (a >= Mod) return a-Mod;
    return a;
  }
  ll calc(){
    ll r = 0;
    ll pp = 1;
    FOR(m,1,k+1){
      r = add(r, mul(pp, val[m]));
      pp = mul(pp, p);
    } return r;
  }
};

vector < klasa > VV = {klasa()};
void Run(int id, int lo, int hi){
  VV.pb(VV.back());
  for (auto x : T[id]) VV.back().add(x);

  if (lo == hi){
    if (Q[lo] != -1) Ans[lo] = VV.back().calc();
    VV.pop_back();
    return;
  }

  int m = (lo+hi)/2;
  Run(id*2, lo, m);
  Run(id*2+1, m+1, hi);
  VV.pop_back();
}

int main(){
  memset(End, -1, sizeof End);
  memset(Start, -1, sizeof Start);
  memset(Q, -1, sizeof Q);
  cin >> n >> k;
  REP(i,n){
    cin >> pt[i].y >> pt[i].x;
    Start[i] = 0;
  }

  cin >> q;
  int count = n;
  REP(i,q){
    int type;
    cin >> type;
    if (type == 1){
      cin >> pt[count].y >> pt[count].x;
      Start[count++] = i+1;
    }
    if (type == 2){
      int x;
      cin >> x;
      End[x-1] = i+1;
    }
    if (type == 3){
      Q[i+1] = 0;
    }    
  }

  REP(i,offset) if (End[i] == -1) End[i] = offset*3;
  REP(i,offset) if (Start[i] != -1) Add(1, 0, offset-1, Start[i], End[i],pt[i]);

  Run(1,0,offset-1);
  REP(i,offset) if (Q[i] != -1) cout << Ans[i] << endl;
  
  return 0;
}