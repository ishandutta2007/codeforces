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
const int mn = 5e5+10;
const ll inf = 0x3f3f3f3f3f3f3f3f;
const int iinf = 0x3f3f3f3f;
const ll mod = 998244353;

int a[mn];

void solve() {
  int n;
  cin >> n;
  for(int i=0;i<n;i++)cin>>a[i];
  int num=0;
  int eq=0,rig=-1;
  for(int i=0;i<n-1;i++){
    eq+=(a[i]==a[i+1]);
    if(a[i]==a[i+1])rig=i;
  }
  if(eq<=1){
    printf("0\n");
    return;
  }
  for(int i=0;i<n-2;i++){
    if(i>=rig-1){
      if(a[i]==a[i+1]&&a[i+1]==a[i+2]){
        num++;
      }
      break; 
    }
    if(a[i]==a[i+1]){
      num++;
      a[i+1]=a[i+2]=-num;
    }
  }
  printf("%d\n",num);
}

int main(){
  cin.tie(0);
  cin.sync_with_stdio(false);
  int tc=1;
  cin >> tc;
  while(tc--){
    solve();
  }
}