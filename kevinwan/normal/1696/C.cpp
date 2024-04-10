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
int a[mn];
vector<pll> red(vector<ll> &a,int m){
  vector<pll>ans;
  for(ll x:a){
    ll num=1;
    while(x%m==0){
      num*=m,x/=m;
    }
    if(!ans.size()||ans.back().first!=x)ans.emplace_back(x,num);
    else ans.back().second+=num;
  }
  return ans;
}
void solve() {
  int n,m;
  cin>>n>>m;
  unordered_map<ll,ll>rec;
  vector<ll>a,b;
  for(int i=0;i<n;i++){
    ll x;
    cin >> x;
    a.push_back(x);
  }
  
  int k;
  cin >> k;
  for(int i=0;i<k;i++){
    ll x;
    cin >> x;
    b.push_back(x);
  }
  printf("%s\n",red(a,m)==red(b,m)?"Yes":"No");
}

int main(){
  cin.tie(0);
  cin.sync_with_stdio(false);
  int tc;
  cin >> tc;
  while(tc--)solve();
}