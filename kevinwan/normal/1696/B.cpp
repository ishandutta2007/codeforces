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
void solve() {
  int n;
  cin >> n;
  int z=0;
  for(int i=0;i<n;i++)cin>>a[i],z|=a[i];
  if(z==0){printf("0\n");return;}
  int num=0;
  for(int i=0;i<n;i++){
    if(a[i]>0&&(i==0||a[i-1]==0))num++;
  }
  if(num==1)printf("1\n");
  else printf("2\n");
}

int main(){
  cin.tie(0);
  cin.sync_with_stdio(false);
  int tc;
  cin >> tc;
  while(tc--)solve();
}