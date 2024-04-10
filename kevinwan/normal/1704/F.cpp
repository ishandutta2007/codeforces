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

int val[mn];
bool vis[mn];

void solve() {
  int n;
  cin >> n;
  string s;
  cin >> s;
  int score = 0;
  int num = 0;
  for(int i=0;i<n;i++){
    if(s[i]=='R'){
      int scn=0;
      if(i==0||s[i-1]=='R')scn++;
      if(i==n-1||s[i+1]=='R')scn++;
      score+=scn-1;
    }
    else{
      int scn=0;
      if(i==0||s[i-1]=='B')scn++;
      if(i==n-1||s[i+1]=='B')scn++;
      score-=scn-1;
    }
  }
  for(int i=1;i<=max(100,n);i++)val[i]=0;
  for(int i=1;i<=100;i++){
    int mt=0;
    for(int j=0;j<=i-2;j++){
      int t=val[j]^val[i-2-j];
      vis[t]=1;
      mt=max(mt,t);
    }
    for(int j=0;vis[j];j++,val[i]++);
    for(int j=0;j<=mt;j++)vis[j]=0;
  }
  for(int i=101;i<=n;i++)val[i]=val[i-34];
  int l=1;
  for(int i=1;i<n;i++,l++){
    if(s[i]!=s[i-1]);
    else num^=val[l],l=0;
  }
  num^=val[l];
  printf("%s\n",score>0||(score==0&&(num>0))?"Alice":"Bob");
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