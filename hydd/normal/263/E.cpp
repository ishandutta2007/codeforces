#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int n,m,k; ll a[2100][2100];
ll calc(int x1,int y1,int x2,int y2){
    return a[x2][y2]-a[x1-1][y2]-a[x2][y1-1]+a[x1-1][y1-1];
}
int main(){
    scanf("%d%d%d",&n,&m,&k);
    for (int i=1;i<=n;i++)
        for (int j=1;j<=m;j++)
            scanf("%lld",&a[i+j][i-j+m]);
    for (int i=1;i<=n+m;i++)
        for (int j=1;j<=n+m;j++)
            a[i][j]+=a[i-1][j]+a[i][j-1]-a[i-1][j-1];
    ll ans=-1; int ansx,ansy;
    for (int i=k;i<=n-k+1;i++)
        for (int j=k;j<=m-k+1;j++){
            int x=i+j,y=i-j+m; ll res=0;
            for (int d=0;d<k;d++) res+=calc(x-d,y-d,x+d,y+d);
            if (res>ans) ans=res,ansx=i,ansy=j;
        }
    printf("%d %d\n",ansx,ansy);
    return 0;
}
/*
 * 
 * */