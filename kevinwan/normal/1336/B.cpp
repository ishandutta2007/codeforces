#include<bits/stdc++.h>
using namespace std;
mt19937 rng(chrono::system_clock::now().time_since_epoch().count());
mt19937_64 rngll(rng());
typedef long long ll;
typedef pair<int,int>pii;
typedef pair<int,ll>pil;
typedef pair<ll,ll>pll;
const int mn=2e5+10;
const ll mod=1e9+7;
ll v[3][mn],n[3];
ll ans;
ll eval(ll a,ll b,ll c){
    return (a-b)*(a-b)+(b-c)*(b-c)+(c-a)*(c-a);
}
void solve(){
    for(int i=0,j=0,k=0;i<n[0];i++){
        while(j<n[1]&&v[1][j]<v[0][i])j++;
        while(k<n[2]&&v[2][k]<v[0][i])k++;
        if(j<n[1]&&k<n[2])ans=min(ans,eval(v[0][i],v[1][j],v[2][k]));
        if(j&&k<n[2])ans=min(ans,eval(v[0][i],v[1][j-1],v[2][k]));
        if(j<n[1]&&k)ans=min(ans,eval(v[0][i],v[1][j],v[2][k-1]));
        if(j&&k)ans=min(ans,eval(v[0][i],v[1][j-1],v[2][k-1]));
    }
}
int main(){
    int tc;
    scanf("%d",&tc);
    while(tc--){
        scanf("%lld%lld%lld",n,n+1,n+2);
        for(int j=0;j<3;j++)for(int i=0;i<n[j];i++)scanf("%lld",&v[j][i]);
        for(int j=0;j<3;j++)sort(v[j],v[j]+n[j]);
        ans=0x3f3f3f3f3f3f3f3f;
        solve();
        swap(v[0],v[1]),swap(n[0],n[1]);
        solve();
        swap(v[0],v[2]),swap(n[0],n[2]);
        solve();
        printf("%lld\n",ans);
    }
}