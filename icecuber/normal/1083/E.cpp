#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

#define x first
#define y second

struct Rec {
  ll x, y, a;
};
bool operator<(Rec a, Rec b) {
  return a.y < b.y;
}

pair<ll,ll> deq[1000001];
int dlen = 0, d0 = 0;

double cross(pair<ll,ll> a, pair<ll,ll> b) {
  return 1.*(b.x-a.x)/(b.y-a.y);
}

ll query(ll x) {
  while (d0+1 < dlen && x < cross(deq[d0+1],deq[d0])) d0++;
  return deq[d0].x-deq[d0].y*x;
  ll r = 0;
  for (int i = 0; i < dlen; i++)
    r = max(r,deq[i].x-deq[i].y*x);
  return r;
}

void add(ll v, ll y) {
  if (v < deq[dlen-1].x) return;
  while (dlen >= 2 && cross({v,y},deq[dlen-2]) > cross(deq[dlen-1],deq[dlen-2])) dlen--;
  deq[dlen++] = {v,y};
}

Rec r[1000000];
int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int n;
  cin >> n;
  for (int i = 0; i < n; i++)
    cin >> r[i].x >> r[i].y >> r[i].a;
  sort(r,r+n);
  deq[dlen++] = {0,0};
  for (int i = 0; i < n; i++) {
    ll v = query(r[i].x)+r[i].x*r[i].y-r[i].a;
    add(v,r[i].y);
  }
  cout << query(0) << endl;
}