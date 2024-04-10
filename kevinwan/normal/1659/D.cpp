#include "bits/stdc++.h"

using namespace std;
#define rep(i,a,b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
using ll = long long;
using lll = __int128;
using pii = pair<int, int>;
using vi = vector<int>;
using vll = vector<ll>;
const int mn = 2e5+10;
const ll inf = 0x3f3f3f3f3f3f3f3f;
const int iinf = 0x3f3f3f3f;
const ll mod = 1e9+7;



void solve() {
  int n;
  cin >> n;
  vi c(n);
  for(int i=0;i<n;i++)cin >> c[i];
  vi a(n);
  ll k=0;
  for(int i=0;i<n;i++)k+=c[i];
  k/=n;
  deque<int> zeros;
  for(int i=n-1;i>=0;i--){
    int fp=k-1<zeros.size()?zeros[k-1]:n;
    if(c[i]==fp)a[i]=1,k--;
    else a[i]=0,zeros.push_front(i);
  }
  for(int i=0;i<n;i++)printf("%d ",a[i]);
  printf("\n");
}

int main(){
  cin.tie(0);
  cin.sync_with_stdio(false);
  int tc;
  cin >> tc;
  while(tc--){
    solve();
  }
}