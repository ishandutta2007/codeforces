#include "bits/stdc++.h"

using namespace std;
#define rep(i,a,b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
using ll = long long;
using pii = pair<int, int>;
using vi = vector<int>;

int main(){
  cin.tie(0);
  ios::sync_with_stdio(false);
  int tc;
  cin>>tc;
  while(tc--){
  int n;
  int x;
  cin >> n;
  int mi=INT_MAX, ma=INT_MIN,mii,mai;
  for(int i=0;i<n;i++){
    cin >> x;
    if(x<mi)mi=x,mii=i;
    if(x>ma)ma=x,mai=i;
  }
  printf("%d %d\n", mii+1, mai+1);
  }
}