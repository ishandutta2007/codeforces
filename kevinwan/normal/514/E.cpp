//Oshvleiki Svlaiyoska Ranasku sachi
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef double ld;
typedef pair<int,int>pii;
typedef pair<ll,ll>pll;
mt19937 rng(chrono::system_clock::now().time_since_epoch().count());
const int mn=2e5+10;
const ll mod=1e9+7;
ll t[101][101];
void mult(ll c[101][101],ll a[101][101],ll b[101][101]){
    memset(t,0,sizeof(t));
    for(int i=0;i<101;i++)for(int j=0;j<101;j++)for(int k=0;k<101;k++)t[i][k]+=a[i][j]*b[j][k],t[i][k]%=mod;
    memcpy(c,t,sizeof(t));
}
ll a[101][101],ans[101][101];
int main(){
    int n,m;
    scanf("%d%d",&n,&m);
    for(int i=1;i<101;i++)a[i][i-1]=1;
    for(int i=0;i<n;i++){
        int x;
        scanf("%d",&x);
        a[0][x-1]++;
        a[0][x]--;
    }
    a[0][0]++;
    for(int i=0;i<101;i++)ans[i][i]=1;
    for(;m;m>>=1,mult(a,a,a))if(m&1)mult(ans,a,ans);
    if(ans[0][0]<0)ans[0][0]+=mod;
    printf("%lld",ans[0][0]);
}