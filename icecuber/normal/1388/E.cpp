#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int nax = 2e3;

ll x0[nax], x1[nax], y[nax];

struct Rat {
  ll p, q;
  Rat(ll p_, ll q_) {
    p = p_, q = q_;
    if (q < 0) p *= -1, q *= -1;
  }
};
bool operator<(Rat a, Rat b) {
  return a.p*b.q < b.p*a.q;
}

struct Hull {
  vector<array<ll,2>> cp;
  double prvf;
  Hull(vector<array<ll,2>> p) {
    prvf = -1e100;
    assert(p.size());
    cp.push_back(p[0]);
    for (auto [nx,ny] : p)
      if (ny < cp.back()[1] || (ny == cp.back()[1] && nx > cp.back()[0]))
	cp.back() = {nx,ny};
    while (1) {
      double cx = cp.back()[0], cy = cp.back()[1];
      double minf = 1e100;
      array<ll,2> np;
      for (auto [nx,ny] : p) {
	if (ny > cy) {
	  double f_ = (cx-nx)/(ny-cy);
	  if (f_ < minf) {
	    minf = f_;
	    np = {nx,ny};
	  }
	}
      }
      if (minf == 1e100) break;
      cp.push_back(np);
    }
    //cout << p.size() << ' ' << cp.size() << endl;
  }
  int curi = 0;
  double query(Rat r) {
    double f = -r.p*1./r.q;
    assert(f >= prvf);
    prvf = f;
    double ret = -1e100;
    /*for (int i = 0; i < (int)cp.size(); i++) {
      ret = max(ret, cp[i][0]+cp[i][1]*f);
      }*/
    ret = cp[curi][0]+cp[curi][1]*f;
    while (curi+1 < (int)cp.size() && cp[curi+1][0]+cp[curi+1][1]*f > ret) {
      ret = cp[curi+1][0]+cp[curi+1][1]*f;
      curi++;
    }
    return ret;
  }
};

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int n;
  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> x0[i] >> x1[i] >> y[i];
  }
  vector<array<Rat,2>> forbid;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      if (y[i] <= y[j]) continue;
      forbid.push_back({
	  Rat(x0[i]-x1[j], y[i]-y[j]),
	    Rat(x1[i]-x0[j], y[i]-y[j])});
    }
  }
  sort(forbid.begin(), forbid.end());

  vector<Rat> cand;
  Rat reach(-1, 0);
  for (auto [l,r] : forbid) {
    if (!(l < reach)) {
      if (reach.q)
	cand.push_back(reach);
      cand.push_back(l);
    }
    reach = max(reach, r);
  }
  if (reach.q) cand.push_back(reach);
  if (forbid.empty()) cand.push_back({0,1});

  vector<array<ll,2>> p;
  for (int i = 0; i < n; i++) {
    p.push_back({x0[i],y[i]});
    p.push_back({x1[i],y[i]});
  }
  Hull ma(p);
  for (auto&[px,py] : p)
    px *= -1, py *= -1;
  Hull mi(p);

  reverse(cand.begin(), cand.end());
  double ans = 1e100;
  for (Rat r : cand) {
    ans = min(ans, ma.query(r)+mi.query(r));
  }
  cout << setprecision(20) << ans << endl;
}