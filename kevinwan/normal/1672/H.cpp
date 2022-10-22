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

int beg[mn],len[mn];
int p1[mn],p2[mn],num[mn],ft[mn];
void solve() {
  int n,q;
  cin >> n >> q;
  string s;
  cin >> s;
  for(int i=1;i<n;i++){
    if(s[i]!=s[i-1])beg[i]=beg[i-1];
    else{
      len[beg[i-1]]=i-beg[i-1];
      beg[i]=i;
    }
  }
  len[beg[n-1]]=n-beg[n-1];
  for(int i=0;i<n;i++){
    if(beg[i]==i){
      if(len[i]%2==1){
        if(s[i]=='1')p1[i]++;
        else p1[i]--;
      }
      else{
        if(s[i]=='1')p2[i]++;
        else p2[i]--;
      }
      num[i]=1;
    }
    if(i>=1){
      p1[i]+=p1[i-1];
      p2[i]+=p2[i-1];
      num[i]+=num[i-1];
    }
  }
  ft[n]=n;
  for(int i=n-1;i>=0;i--){
    if(beg[i]==i&&len[i]%2==0){
      ft[i]=i;
    }
    else ft[i]=ft[i+1];
  }
  while(q--){
    int l,r;
    cin >> l >> r;
    l=beg[l-1], r=beg[r-1];
    int tot = num[r]-(l>=1?num[l-1]:0);
    int n1 = p1[r]-(l>=1?p1[l-1]:0);
    int n2 = p2[r]-(l>=1?p2[l-1]:0);
    if(n2==0&&ft[l]<=r){
      int t=s[ft[l]]-'0';
      if(t==1&&n1<=0)n2=2;
      if(t==0&&n1>=0)n2=2;
    }
    printf("%d\n",(tot+abs(n1)+abs(n2))/2);
  }
}
 
int main(){
  cin.tie(0);
  cin.sync_with_stdio(false);
  int tc=1;
  //cin >> tc;
  while(tc--){
    solve();
  }
}