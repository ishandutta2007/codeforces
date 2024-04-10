#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int mn=5010;
const ll mod = 998244353;

ll a[mn];
ll ch[mn][mn];
void solve(){
    int n,k;
    cin>>n>>k;
    string s;
    cin>>s;
    for(int i=0;i<n;i++)a[i+1]=a[i]+(s[i]-'0');
    bool first=1;
    ll ans=0;
    for(int i=0,j=0;i<=n;i++){
        if(a[i]-a[j]<k)continue;
        else if(a[i]-a[j]>k){
            while(a[i]-a[j]>k)j++;
        }
        ans+=ch[i-j][k];
        if(!first)ans-=ch[max(0,i-1-j)][max(0LL,a[i-1]-a[j])];
        ans%=mod;
        first=0;
    }
    if(first)ans=1;
    if(ans<0)ans+=mod;
    printf("%lld\n",ans);
}

int main() {
    cin.tie(0);
    cin.sync_with_stdio(0);
    ch[0][0]=1;
    for(int i=1;i<mn;i++){
        ch[i][0]=1;
        for(int j=1;j<=i;j++){
            ch[i][j]=(ch[i-1][j-1]+ch[i-1][j])%mod;
        }
    }
    int tc;
    tc=1;
    while(tc--){
        solve();
    }
}