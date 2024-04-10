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


int a[mn];
void solve() {
  int n;
  cin >> n;
  for(int i=1;i<=n;i++)cin >> a[i];
  map<int,int> best;
  best[0]=0;
  int ans=0;
  for(int i=1;i<=n;i++){
    a[i]^=a[i-1];
    if(best.find(a[i])!=best.end()){
      ans=max(ans,best[a[i]]+1);
    }
    best[a[i]]=ans;
  }
  printf("%d\n",n-ans);
}

int main(){
  cin.tie(0);
  cin.sync_with_stdio(false);
  int tc = 1;
  cin >> tc;
  while(tc--)solve();
}