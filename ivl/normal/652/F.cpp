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

#define int ll

int n, m;
pair < int, char > sd[1<<20];
int per[1<<20];
int inv[1<<20];

int out[1<<20];

pair < int, char > simul(int id, int t){
  REP(i,n) sd[i].x *= 2;
  m *= 2;
  t *= 2;
  auto c = sd[id];
  int ct = 0;
  queue < int > Ql, Qr;
  FOR(i,1,n) if (sd[(i+id)%n].y == 'L') Ql.push(sd[(i+id)%n].x);
  for (int i = n-1; i > 0; --i) if (sd[(i+id)%n].y == 'R') Qr.push(sd[(i+id)%n].x);

  while (true){
    while (c.x < 0) c.x += m;
    while (c.x >= m) c.x -= m;
    if (c.y == 'R'){
      if (Ql.empty()) break;
      int cc = Ql.front()-ct;
      Ql.pop();
      while (cc < 0) cc += m;
      while (cc <= c.x) cc += m;
      if (c.x+(t-ct) < cc-(t-ct)) break;
      int d = cc-c.x;
      c.x += d/2;
      cc -= d/2;
      ct += (d+1)/2;
      c.y = 'L';
      Qr.push(cc-ct);
    } else {
      if (Qr.empty()) break;
      int cc = Qr.front()+ct;
      Qr.pop();
      while (cc >= m) cc -= m;
      while (cc >= c.x) cc -= m;
      if (c.x-(t-ct) > cc+(t-ct)) break;
      int d = -cc+c.x;
      c.x -= d/2;
      cc += d/2;
      ct += (d+1)/2;
      c.y = 'R';
      Ql.push(cc+ct);
    }
  }

  if (c.y == 'R') c.x += t-ct;
  else c.x -= t-ct;
  c.x %= m;
  if (c.x < 0) c.x += m;
  REP(i,n) sd[i].x /= 2;
  m /= 2;
  c.x /= 2;
  return c;
}

#undef int
int main(){
#define int ll
  ios_base::sync_with_stdio(false);

  ll t;
  cin >> n >> m >> t;
  REP(i,n) cin >> sd[i].x >> sd[i].y, sd[i].x %= m;

  REP(i,n) per[i] = i;
  sort(per, per+n, [&](int a, int b){return sd[a] < sd[b];});
  REP(i,n) inv[per[i]] = i;
  sort(sd, sd+n);

  auto x = simul(0, m);
  int p = (int)(lower_bound(sd, sd+n, x)-sd);
  assert(p != n);
  int id = (p*(t/m))%n;
  x = simul(id, t%m);

  REP(i,n){
    if (sd[i].y == 'R') sd[i].x += t%m;
    if (sd[i].y == 'L') sd[i].x -= t%m;
    if (sd[i].x < 0) sd[i].x += m;
    sd[i].x %= m;
  } sort(sd, sd+n);

  id = (int)(lower_bound(sd, sd+n, x)-sd);
  assert(id != n);
  REP(i,n) out[i] = sd[(i+id)%n].x;
  REP(i,n) if (out[i] == 0) out[i] = m;
  REP(i,n) cout << out[inv[i]] << " "; cout << endl;
  
  return 0;
}