#include "bits/stdc++.h"
 
using namespace std;
#define rep(i,a,b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
using ll = long long;
using lll = __int128;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
using vi = vector<int>;
using vll = vector<ll>;
const int mn = 1e5+10;
const ll inf = 0x3f3f3f3f3f3f3f3f;
const int iinf = 0x3f3f3f3f;
const ll mod = 998244353;
typedef pair<double,double> pdd;


double eps=1e-10;

double query(const vector<pdd> &poly){
  printf("? %d\n",sz(poly));
  for(pdd p: poly){
    printf("%.15lf %.15lf\n", p.first, p.second);
  }
  fflush(stdout);
  double res;
  cin >> res;
  return res;
}
void report(double x, double y){
  printf("! %.15lf %.15lf\n", x,y);
  fflush(stdout);
}

void solve() {
  int n,m;
  cin >> n >> m;
  vector<pdd> poly;
  poly.emplace_back(0,0);
  for(int i=0;i<n;i++){
    poly.emplace_back(i,m);
    poly.emplace_back(i+0.5/(i+1),m);
    poly.emplace_back(i+0.5/(i+1),eps);
    poly.emplace_back(i+1,eps);
  }
  double xres = query(poly);
  poly.clear();
  poly.emplace_back(0,0);
  for(int i=0;i<m;i++){
    poly.emplace_back(n,i);
    poly.emplace_back(n,i+0.5/(i+1));
    poly.emplace_back(eps,i+0.5/(i+1));
    poly.emplace_back(eps,i+1);
  }
  double yres = query(poly);
  int xr = 0.5/(xres-eps)-1;
  double xstart = xr-1+0.5/xr;
  xstart=max(0.,min(xstart,double(n-1)));
  if(xr==0)xstart=0;
  int yr = 0.5/(yres-eps)-1;
  double ystart = yr-1+0.5/yr;
  ystart=max(0.,min(ystart,double(m-1)));
  if(yr==0)ystart=0;
  double xq = query({{xstart,0},{xstart,m},{xstart+1,m},{xstart+1,0}});
  double yq = query({{0,ystart},{n,ystart},{n,ystart+1},{0,ystart+1}});
  report(xstart+1-xq,ystart+1-yq);
}
 
int main(){
  //cin.tie(0);
  //cin.sync_with_stdio(false);
  int tc=1;
  //cin >> tc;
  for(int tcc=1;tcc<=tc;tcc++){
    //printf("Case #%d: ",tcc);
    solve();
  }
}