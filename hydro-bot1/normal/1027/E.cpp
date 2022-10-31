// Hydro submission #6170a083e73a88bc078fdff0@1634771075892
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=505,mod=998244353;
int f[N][N],n,K,ans;
void add(int &x,int y){x=(x+y)%mod;}
int main(){
    scanf("%d%d",&n,&K);
    f[0][0]=1;
    for(int i=1;i<=n;i++){
        f[i][i]=1;
        for(int j=1;j<i;j++){
            for(int k=1;k<j;k++)add(f[i][j],f[i-k][j]);
            for(int k=0;k<=j;k++)add(f[i][j],f[i-j][k]);
        }
    }
    for(int i=1;i<=n;i++)for(int j=1;j<=n;j++)if(i*j<K)add(ans,1ll*f[n][i]*f[n][j]%mod);
    printf("%d",ans*2ll%mod);
    return 0;
}