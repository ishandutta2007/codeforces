#include<bits/stdc++.h>
using namespace std;
typedef pair<int,int>pii;
typedef long long ll;
typedef pair<ll,ll>pll;
typedef __int128 lll;
const ll mod=1e9+7;
const int mn=1e5+200;
ll a[103][mn];
ll ch[mn][103];
int main(){
    cin.tie(0);
    cin.sync_with_stdio(0);
    int n,k;
    cin>>n>>k;
    for(int i=1;i<=n;i++)cin>>a[0][i];
    ch[0][0]=1;
    for(int i=1;i<mn;i++){
        ch[i][0]=1;
        for(int j=1;j<103;j++)ch[i][j]=(ch[i-1][j-1]+ch[i-1][j])%mod;
    }
    while(k--){
        int l,r,c;
        cin>>l>>r>>c;
        r++,c++;
        a[c][l]++;
        for(int i=0;i<c;i++)a[c-i][r]-=ch[r-l+i-1][i],a[c-i][r]%=mod;
    }
    for(int i=102;i;i--){
        for(int j=1;j<=n;j++)a[i][j]+=a[i][j-1],a[i][j]%=mod;
        for(int j=1;j<=n;j++)a[i-1][j]+=a[i][j],a[i-1][j]%=mod;
    }
    for(int i=1;i<=n;i++){
        if(a[0][i]<0)a[0][i]+=mod;
        printf("%lld ",a[0][i]);
    }
}