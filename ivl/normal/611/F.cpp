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

pii operator+(pii a, pii b){return {a.x+b.x, a.y+b.y};}
void operator+=(pii &a, pii b){a = {a.x+b.x, a.y+b.y};}

const int oo = 1000000000;
const ll ool = (ll)oo * oo;
const int Mod = oo+7;

int n, h, w;
char in[500005];

map < char, pii > M = {
  {'U', { 0,  1}},
  {'L', {-1,  0}},
  {'R', { 1,  0}},
  {'D', { 0, -1}}
};
pii ex[2][2];

ll del[2][500005];

int main(){

  REP(i,500005) del[0][i] = del[1][i] = ool;

  cin >> n >> h >> w;
  scanf("%s", in);

  pii t = {0, 0};
  REP(i,n){
    t += M[in[i]];
    if (t.x < ex[0][0].x) ex[0][0] = {t.x, i};
    if (t.x > ex[0][1].x) ex[0][1] = {t.x, i};
    if (t.y < ex[1][0].x) ex[1][0] = {t.y, i};
    if (t.y > ex[1][1].x) ex[1][1] = {t.y, i};

    if (t.x < 0 && del[0][-t.x-1] == ool) del[0][-t.x-1] = i+1;
    if (t.x > 0 && t.x <= w && del[0][w-t.x] == ool) del[0][w-t.x] = i+1;
    if (t.y < 0 && del[1][-t.y-1] == ool) del[1][-t.y-1] = i+1;
    if (t.y > 0 && t.y <= h && del[1][h-t.y] == ool) del[1][h-t.y] = i+1;
  }

  if (t.x == 0 && t.y == 0){
    if ((ex[0][1].x-ex[0][0].x+1) <= w && (ex[1][1].x-ex[1][0].x+1) <= h){cout << -1 << endl; return 0;}
  }

  if (t.x < 0) REP(i,w) if (del[0][i] == ool) del[0][i] = n+del[0][i+t.x];
  if (t.x > 0) for (int i = w-1; i >= 0; --i) if (del[0][i] == ool) del[0][i] = n+del[0][i+t.x];

  if (t.y < 0) REP(i,h) if (del[1][i] == ool) del[1][i] = n+del[1][i+t.y];
  if (t.y > 0) for (int i = h-1; i >= 0; --i) if (del[1][i] == ool) del[1][i] = n+del[1][i+t.y];

  //REP(i,w) TRACE(del[0][i]);
  //REP(i,h) TRACE(del[1][i]);
  
  ll cnt[] = {w, h};
  vector < pll > sweep;
  REP(i,w) sweep.pb({del[0][i], 0});
  REP(i,h) sweep.pb({del[1][i], 1});
  sort(sweep.begin(), sweep.end());
  ll r = 0;
  for (auto x : sweep){
    r += (cnt[!x.y] * x.x) % Mod;
    --cnt[x.y];
    //TRACE(cnt[0] _ cnt[1] _ x.x _ x.y);
  } cout << r % Mod << endl;

  return 0;
}