// remote judge
#include<bits/stdc++.h>
using namespace std;
const int N=1005;
char c[N][N];
int n,m;
int d[N][N];
int main(){
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;++i)
        scanf("%s",c[i]+1);
    for(int i=n;i>=1;--i)
        for(int j=1;j<=m;++j)
            if(c[i][j]==c[i+1][j])
                d[i][j]=d[i+1][j]+1;
            else
                d[i][j]=1;
    long long ans=0;
    for(int i=1;i<=n;++i)
        for(int j=1,k=0;j<=m;++j,ans+=k){
            int h=d[i][j];
            if(i+h*3-1<=n&&d[i+h][j]==h&&d[i+h*2][j]>=h){
                if(k&&c[i][j]==c[i][j-1]&&d[i][j]==d[i][j-1]&&c[i+h][j]==c[i+h][j-1]&&c[i+h*2][j]==c[i+h*2][j-1])
                    ++k;
                else
                    k=1;
            }else
                k=0;
        }
    printf("%lld\n",ans);
    return 0;
}