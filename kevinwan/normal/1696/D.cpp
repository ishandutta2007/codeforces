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
const ll inf = 0x3f3f3f3f3f3f3f3f;
const int iinf = 0x3f3f3f3f;

const int mn = 1e6+10;
int dp[mn];

int a[mn];
void solve() {
  int n;
  cin >> n;
  for(int i=0;i<n;i++){
    cin >> a[i];
  }
  vector<pii> lo {make_pair(a[0],0)}, hi {make_pair(-a[0],0)};
  vector<int> ilo , ihi;
  ilo.push_back(0),ihi.push_back(0);
  for(int i=1;i<n;i++) {
    if(a[i]>a[i-1]){
      int hl=lower_bound(all(hi),make_pair(-a[i],0))-hi.begin();
      //cerr << hl << " ";
      int lim = hl>0?ihi[hl-1]:-1;
      //cerr << lim << " ";
      int ind = *upper_bound(all(ilo),lim);
      //cerr << ind << endl;
      dp[i]=dp[ind]+1;
    }
    else {
      int llim = lower_bound(all(lo),make_pair(a[i],0))-lo.begin();
      int lim = llim>0?ilo[llim-1]:-1;
      int ind = *upper_bound(all(ihi),lim);
     // cerr << ind << endl;
      dp[i]=dp[ind]+1;
    }
    while(lo.size()&&lo.back().first>a[i])lo.pop_back(),ilo.pop_back();
    while(hi.size()&&hi.back().first>-a[i])hi.pop_back(),ihi.pop_back();
    lo.emplace_back(a[i],i),ilo.push_back(i);
    hi.emplace_back(-a[i],i),ihi.push_back(i);
  }
  printf("%d\n",dp[n-1]);
 // cerr << endl;
}

int main(){
  cin.tie(0);
  cin.sync_with_stdio(false);
  int tc;
  cin >> tc;
  while(tc--)solve();
}