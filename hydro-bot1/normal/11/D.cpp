// Hydro submission #62df4ef425d42d051620a68c@1658801909254
#include<cmath>
#include<stack>
#include<queue>
#include<cstdio>
#include<vector>
#include<string>
#include<cstring>
#include<iostream>
#include<algorithm>
using namespace std;
const int N=22;
int n,m,st;
long long ans;
int v[N][N]={0};
long long dp[1<<20][20]={0};
int main(){
    scanf("%d%d",&n,&m);
    while(m--){
        int a,b;
        scanf("%d%d",&a,&b);
        v[a][b]=v[b][a]=1;
    }
    for(int i=0;i<n;i++)dp[1<<i][i] = 1;
    for(int i=1;i<(1<<n);i++){
        for(int j=0;j<n;j++){
            if(dp[i][j]==0)continue;
            for(int k=0;k<n;k++){
                if(i&(1<<k)){
                    st=k;
                    break;
                }
            }
            if(v[j+1][st+1] and __builtin_popcount(i)>2) ans+=dp[i][j];
            for(int k=st+1;k<n;k++)
                if(!(i&(1<<k)) and v[j+1][k+1]) dp[i|(1<<k)][k] += dp[i][j];
        }
    }
    cout<<ans/2;
}