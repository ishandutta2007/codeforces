#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll mod=1e9+7;
ll ch[51][51];
ll dp[2][51][51];
int main(){
    int n,w;
    scanf("%d%d",&n,&w);
    ch[0][0]=1;
    for(int i=1;i<=n;i++){
        ch[i][0]=1;
        for(int j=1;j<=i;j++)ch[i][j]=(ch[i-1][j-1]+ch[i-1][j])%mod;
    }
    w/=50;
    int a=0,b=0,x;
    for(int i=0;i<n;i++){
        scanf("%d",&x);
        if(x==50)a++;
        else b++;
    }
    dp[0][0][0]=1;
    //cout<<a<<endl<<b<<endl<<w<<endl;
    for(int i=1;i<=4*n;i++){
        memset(dp[i&1],0,sizeof(dp[i&1]));
        if(i&1){
            for(int j=0;j<=a;j++){
                for(int k=0;k<=b;k++){
                    for(int l=0;l<=min(j,w);l++){
                        for(int m=0;m<=min(k,(w-l)/2);m++){
                            if(l==0&&m==0)continue;
                            if(i==3&&j==1&&k==1&&l==0&&m==1){
                                //cout<<"HAIL";
                            }
                            dp[i&1][j][k]+=dp[i&1^1][j-l][k-m]*ch[a-(j-l)][l]%mod*ch[b-(k-m)][m];
                            dp[i&1][j][k]%=mod;
                        }
                    }
                }
            }
        }
        else{
            for(int j=0;j<=a;j++){
                for(int k=0;k<=b;k++){
                    for(int l=0;l<=w&&l+j<=a;l++){
                        for(int m=0;m<=(w-l)/2&&k+m<=b;m++){
                            if(l==0&&m==0)continue;
                            if(i==2&&j==1&&k==0&&l==1&&m==0){
                                //cout<<ch[j+l][l]<<endl;
                            }
                            dp[i&1][j][k]+=dp[i&1^1][j+l][k+m]*ch[j+l][l]%mod*ch[k+m][m];
                            dp[i&1][j][k]%=mod;
                        }
                    }
                }
            }
        }
        if(dp[i&1][a][b]){
            printf("%d\n%lld",i,dp[i&1][a][b]);
            return 0;
        }
    }
    printf("-1\n0");
}