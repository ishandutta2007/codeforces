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

int a[mn],b[mn];

void solve() {
  int n;
  cin >> n;
  vi ex(n+1);
  for(int i=0;i<n;i++)cin>>a[i];
  rep(i,0,n)cin>>b[i];
  int i=n-1,j=n-1;
  while(i>=0){
    while(b[i]!=a[j]){
      if(ex[a[j]]>0){
        ex[a[j]]--;
        j--;
      }
      else{
        printf("NO\n");
        return;
      }
    }
    i--;
    j--;
    while(i>=0 && b[i]==b[i+1]){
      if(a[j]==b[i]){
        j--;
      }
      else ex[b[i]]++;
      i--;
    }
  }
  printf("YES\n");
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