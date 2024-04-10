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
const int mn = 1e6+10;
const ll inf = 0x3f3f3f3f3f3f3f3f;
const int iinf = 0x3f3f3f3f;
const ll mod = 998244353;

string s[11];

void solve() {
  string t;
  cin >> t;
  int n;
  cin >> n;
  for(int i=0;i<n;i++)cin >> s[i];
  int at = 0;
  vector<pii> ans;
  while(at < t.size()) {
    int best = at;
    pii bestval;
    for(int i=0;i<n;i++) {
      for(int j=at;j>=0&&j+s[i].size()>at;j--){
        if(j+s[i].size()>t.size())continue;
        bool good = 1;
        for(int k=0;k<s[i].size();k++){
          if(t[j+k]!=s[i][k]) good = 0;
        }
        if (good && j+s[i].size()>best) {
          best = j+s[i].size();
          bestval = {i,j};
        }
      }
    }
    if(best == at) break;
    at = best;
    ans.push_back(bestval);
  }
  if(at!=t.size()) {
    printf("-1\n");
    return;
  }
  printf("%d\n",(int)ans.size());
  for (pii p : ans) {
    printf("%d %d\n",p.first+1, p.second+1);
  }
}
 
int main(){
  cin.tie(0);
  cin.sync_with_stdio(false);
  int tc;
  cin >> tc;
  for(int tcc=1;tcc<=tc;tcc++){
    //printf("Case #%d: ",tcc);
    solve();
  }
}