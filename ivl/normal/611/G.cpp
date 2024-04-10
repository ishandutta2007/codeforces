#include <bits/stdc++.h>

#define FOR(i,a,b) for (int i = (int)(a); i < (int)(b); ++i)
#define REP(i,n) FOR(i,0,n)
#define pb push_back
#define pii pair < int, int >
#define x first
#define y second
#define ll long long
#define pll pair < ll, ll >

#define TRACE(x) cerr << #x << " = " << x << endl
#define _ << " _ " <<

using namespace std;

const int Mod = 1000000007;

int n;
pll in[2000005];

ll ccw(pll a, pll b, pll c){
  return a.x*(b.y-c.y) + b.x*(c.y-a.y) + c.x*(a.y-b.y);
}

ll sz(int a, int b, int c){
  return ccw(in[a], in[b], in[c]);
}

ll add(ll a, ll b){
  return (a+b)%Mod;
}

ll mul(ll a, ll b){
  a %= Mod;
  b %= Mod;
  return (a*b)%Mod;
}

void addr(ll &a, ll b){a = (a+b)%Mod;}

int main(){

  cin >> n;
  REP(i,n) scanf("%I64d%I64d", &in[i].x, &in[i].y);
  reverse(in, in+n);
  REP(i,n) REP(t,4) in[i+t*n] = in[i];

  ll all = 0;
  REP(i,n) all += in[i].x * in[i+1].y - in[i+1].x * in[i].y;

  ll R = 0;
  
  int p1 = 0, p2 = 0;
  ll sx = in[0].x, sy = in[0].y, sum = 0, sum2 = 0;

  int cnt = 0;
  REP(ttt,n){
    // max expand
    while (sum + sz(p1, p2, p2+1) <= all/2){
      sum += sz(p1, p2, p2+1); ++p2;
      sx += in[p2].x;
      sy += in[p2].y;
      sum2 = add(sum, sum2);
    } R = add(R, mul(all,p2-p1-1)-2*sum2);
    if (sum == all/2) ++cnt;

    //TRACE(sz(p1, p2, p2+1));
    //TRACE(p1 _ p2 _ sum _ sum2);

    ll temp = mul(p2-p1+1, in[p1].x * in[p1+1].y - in[p1+1].x * in[p1].y);
    addr(temp, mul(in[p1+1].x, sy) - mul(sx, in[p1+1].y));
    addr(temp, mul(-in[p1].x, sy) + mul(sx, in[p1].y));
    addr(sum2, -temp);

    sum -= sz(p1, p1+1, p2);
    sx -= in[p1].x;
    sy -= in[p1].y;
    ++p1;
    //TRACE(p1 _ p2 _ sum _ sum2);

  }
  //addr(R, -cnt/2 * (all));
  cout << (R%Mod + Mod) % Mod << endl;
  
  return 0;
}