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
const ll mod=1e9+7;

const int mn=1e5+10;


ll fib[128];
int u[128];
ll getf(ll x){
  int r=0;
  while(fib[r+1]<=x)r++;
  return r;
}
void solve() {
  int n;
  cin >> n;
  fib[1]=fib[2]=1;
  for(int i=3;fib[i-1]<1e18;i++)fib[i]=fib[i-1]+fib[i-2];
  ll sum=0;
  memset(u,0,sizeof(u));
  vector<vi> vs;
  for(int i=0;i<n;i++){
    ll x;
    vi v;
    cin >> x;
    sum += x;
    int r = getf(x);
    for(int i=r;i>0;i--)if(x>=fib[i]){
      v.push_back(i);
      x-=fib[i];
      u[i]++;
    }
    vs.push_back(v);
  }
  int lim = getf(sum+1)-2;
  bool fail = (fib[lim+2]-1!=sum);
  int bad = -1;
  for(int i=1;i<=lim;i++){
    if(u[i]>=2){
      if(bad==-1&&u[i]==2)bad=i;
      else fail = 1;
    }
  }
  if(u[lim+1]==1)bad=lim+1;
  if(bad!=-1){
    bool found = 0;
    for(int i=0;i<n;i++)if(vs[i].back()==bad&&bad%2==0)found=1;
    fail |= !found;
    for(int i=1;i<=lim;i++)if(i!=bad){
      if(i%2==1&&i<bad){
        fail |= u[i]!=0;
      }
      else {
        fail |= u[i]!=1;
      }
    }
  }
  printf("%s\n",fail?"NO":"YES");
}

int main(){
  cin.tie(0);
  cin.sync_with_stdio(false);
  int tc = 1;
  cin >> tc;
  while(tc--)solve();
}