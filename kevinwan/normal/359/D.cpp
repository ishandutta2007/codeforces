#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int mn=6e5+10;
int g[mn][19],s[mn][19],a[mn],gc[mn],sm[mn],pgc[mn],psm[mn];
vector<int> num;
int main()
{
    cin.tie(0);
    cin.sync_with_stdio(0);
    int n,i,j;
    cin>>n;
    memset(s,0x3f,sizeof(s));
    for(i=0;i<n;i++){
        cin>>a[i];
        g[i][0]=s[i][0]=a[i];
    }
    for(i=1;i<19;i++)for(j=0;j<n;j++)s[j][i]=min(s[j][i-1],s[j+(1<<i-1)][i-1]),g[j][i]=__gcd(g[j][i-1],g[j+(1<<i-1)][i-1]);
    int cur=0;
    memset(sm,0x3f,sizeof(sm));
    for(i=18;i>=0;i--){
        memcpy(pgc,gc,sizeof(pgc));
        memcpy(psm,sm,sizeof(sm));
        bool suc=0;
        for(j=0;j+cur+(1<<i)<=n;j++){
            pgc[j]=__gcd(pgc[j],g[j+cur][i]);
            psm[j]=min(psm[j],s[j+cur][i]);
            if(pgc[j]==psm[j])suc=1;
        }
        if(suc){
            cur+=(1<<i);
            memcpy(gc,pgc,sizeof(gc));
            memcpy(sm,psm,sizeof(sm));
        }
    }
    for(i=0;i+cur<=n;i++)if(gc[i]==sm[i])num.push_back(i);
    printf("%d %d\n",num.size(),cur-1);
    for(int x:num)printf("%d ",x+1);
}