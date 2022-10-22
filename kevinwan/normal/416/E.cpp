#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int>pii;
const int mn=5e2+10;
int d[mn][mn];
int o[mn][mn];
int num[mn];
int main(){
    int n,m;
    scanf("%d%d",&n,&m);
    memset(d,0x3f,sizeof(d));
    memset(o,0x3f,sizeof(o));
    for(int i=1;i<=n;i++)d[i][i]=0;
    for(int i=0;i<m;i++){
        int a,b,c;
        scanf("%d%d%d",&a,&b,&c);
        d[a][b]=d[b][a]=c;
        o[a][b]=o[b][a]=c;
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            for(int k=1;k<=n;k++){
                d[j][k]=min(d[j][k],d[j][i]+d[i][k]);
            }
        }
    }
    for(int i=1;i<=n;i++){
        memset(num,0,sizeof(num));
        for(int j=1;j<=n;j++){
            for(int k=1;k<=n;k++)if(o[k][j]!=0x3f3f3f3f&&d[i][k]+o[k][j]==d[i][j])num[j]++;
        }
        for(int j=i+1;j<=n;j++){
            int ans=0;
            for(int k=1;k<=n;k++)if(d[i][k]+d[k][j]==d[i][j]&&d[i][j]<0x3f3f3f3f)ans+=num[k];
            printf("%d ",ans);
        }
    }
}