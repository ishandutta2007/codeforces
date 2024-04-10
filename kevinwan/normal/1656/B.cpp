#include "bits/stdc++.h"

using namespace std;
#define rep(i,a,b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
using ll = long long;
using pii = pair<int, int>;
using vi = vector<int>;

void solve() {
  int n, k;
  set<int>s;
  cin >> n >> k;
  for(int i=0;i<n;i++){
    int x;
    cin >> x;
    s.insert(x);
  }
  for(int x:s){
    if(s.count(x-k)){
      printf("YES\n");
      return;
    }
  }
  printf("NO\n");
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