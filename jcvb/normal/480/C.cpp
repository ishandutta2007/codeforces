#include<cstring>
#include<cstdlib>
#include<algorithm>
#include<iostream>
#include<cstdio>
#define mo 1000000007
using namespace std;
int n,a,b,k;
int f[2][5005]={0};
int l[5005],r[5005];
inline void upd(int &a,int b){
    a+=b;
    if(a>=mo)a-=mo;
    if(a<0)a+=mo;
}
int main()
{
    scanf("%d%d%d%d",&n,&a,&b,&k);
    for (int x=1;x<=n;x++)if(x!=b){
        if(x<b){
            r[x]=b-1;if(r[x]==x)r[x]--;
            l[x]=max(1,x-(b-x-1));
            if(l[x]==x)l[x]++;
        }else{
            l[x]=b+1;if(l[x]==x)l[x]++;
            r[x]=min(n,x+(x-b-1));
            if(r[x]==x)r[x]--;
        }
        if(l[x]>r[x])r[x]=l[x]-1;
    }
    f[0][a]=1;
    for (int j=1;j<=k;j++){
        for (int i=1;i<=n;i++)f[j&1][i]=0;
        for (int i=1;i<=n;i++)if(l[i]<=r[i]){
            if(l[i]<=i-1){
                upd(f[j&1][l[i]],f[!(j&1)][i]);
                upd(f[j&1][i],-f[!(j&1)][i]);
            }
            if(i+1<=r[i]){
                upd(f[j&1][i+1],f[!(j&1)][i]);
                upd(f[j&1][r[i]+1],-f[!(j&1)][i]);
            }
        }
        for (int i=2;i<=n;i++)upd(f[j&1][i],f[j&1][i-1]);
    }
    int ans=0;
    for (int i=1;i<=n;i++)if(i!=b)upd(ans,f[k&1][i]);
    ans=(ans%mo+mo)%mo;
    printf("%d\n",ans);
    return 0;
}