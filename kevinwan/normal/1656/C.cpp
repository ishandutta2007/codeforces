#include "bits/stdc++.h"

using namespace std;
#define rep(i,a,b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
using ll = long long;
using pii = pair<int, int>;
using vi = vector<int>;

void solve() {
  int n;
  cin >> n;
  vi v;
  for(int i=0;i<n;i++){
    int x;
    cin >> x;
    v.push_back(x);
  }
  sort(all(v));
  v.erase(unique(all(v)), end(v));
  n = v.size();
  if(v[0]==1||(v.size()>=2&&v[1]==1)){
    for(int i=0;i<n-1;i++)if(v[i+1]==v[i]+1){
      printf("NO\n");
      return;
    }
    printf("YES\n");
  }
  else{
    printf("YES\n");
  }
}

int main(){
  cin.tie(0);
  ios::sync_with_stdio(false);
  int tc;
  cin>>tc;
  while(tc--){
    solve();
  }
}