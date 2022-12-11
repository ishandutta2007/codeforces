#include<iostream>
#include<cmath>
#include<cstring>
#include<algorithm>
#include<cstdio>
using namespace std;
int pd[3000100],l,r,s,prime[101],len,tot,x[3000100],dis[3000100];
void dfs(int k1,int k2){
    if (k2>tot){
        x[++len]=k1; return;
    }
    for (long long i=k1;i<=r;i=i*prime[k2]) dfs(i,k2+1);
}
int main(){
    scanf("%d%d%d",&l,&r,&s);
    for (int i=2;i<=s;i++)
        if (pd[i]==0){
            prime[++tot]=i; for (int j=i;j<=s;j+=i) pd[j]=1;
        }
    dfs(1,1); sort(x+1,x+len+1);
    memset(pd,0x00,sizeof pd);
    memset(dis,0x3f,sizeof dis); dis[1]=0;
    for (int i=1;i<=s;i++){
        for (int j=1;j<=len;j++){
            if (dis[j]<=s) pd[j]=1; dis[j]++;
        }
        int now=1;
        for (int j=1;j<=len;j++){
            while (now<=len&&x[now]<1ll*x[j]*i) now++;
            if (now>len) break;
            dis[now]=min(dis[now],dis[j]+1);
        }
    }
    int ans=0;
    for (int i=1;i<=len;i++) if (pd[i]==1&&x[i]>=l&&x[i]<=r) ans++;
    cout<<ans<<endl; return 0;
}