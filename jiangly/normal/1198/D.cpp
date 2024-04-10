#include<bits/stdc++.h>
using namespace std;
const int N=50+5;
int n;
char s[N][N];
int dp[N][N][N][N];
int main(){
    scanf("%d",&n);
    for(int i=1;i<=n;++i){
        scanf("%s",s[i]+1);
    }
    for(int lx=1;lx<=n;++lx){
        for(int x1=1;x1+lx-1<=n;++x1){
            for(int ly=1;ly<=n;++ly){
                for(int y1=1;y1+ly-1<=n;++y1){
                    int x2=x1+lx-1;
                    int y2=y1+ly-1;
                    int &val=dp[x1][x2][y1][y2];
                    if(x1==x2&&y1==y2){
                        val=(s[x1][y1]=='#');
                    }else{
                        val=max(x2-x1+1,y2-y1+1);
                        for(int i=x1;i<x2;++i){
                            val=min(val,dp[x1][i][y1][y2]+dp[i+1][x2][y1][y2]);
                        }
                        for(int i=y1;i<y2;++i){
                            val=min(val,dp[x1][x2][y1][i]+dp[x1][x2][i+1][y2]);
                        }
                    }
                }
            }
        }
    }
    printf("%d\n",dp[1][n][1][n]);
    return 0;
}