#include<iostream>
#include<cstdio>
#include<cmath>
#include<cstring>
#include<algorithm>
using namespace std;
int w[13][13],mo=1e9+7,k,now[13][13],ans,a,b,n,m,next[13][13][2],L[1024],num[15];
int dfs(int x,int y){
    if (y>m){x++; y=1;}
    if (x>n) return 1; int ans=0,pd=-1;
    now[x][y]=now[x-1][y]|now[x][y-1]; int k1=((1<<k)-1)-now[x][y];
    if (w[x][y]){
        if ((1<<w[x][y]-1)&k1){now[x][y]|=1<<w[x][y]-1; num[w[x][y]]++; ans+=dfs(x,y+1); now[x][y]^=1<<w[x][y]-1; num[w[x][y]]--;} 
    } else for (;k1;k1-=k1&(-k1)){
        now[x][y]|=k1&(-k1); int k5=L[k1&(-k1)]; num[k5]++; 
        if (num[k5]==1){if (pd==-1) pd=dfs(x,y+1); ans=(ans+pd)%mo;} else ans=(ans+dfs(x,y+1))%mo; 
        now[x][y]^=k1&(-k1); num[k5]--;}
    return ans;
}
int main(){
    scanf("%d%d%d",&n,&m,&k); if (k<n+m-1){cout<<0<<endl; return 0;}
    for (int i=1;i<=n;i++) for (int j=1;j<=m;j++) {scanf("%d",&w[i][j]); if (w[i][j]) num[w[i][j]]++;}
    for (int i=1;i<=k;i++) L[1<<i-1]=i;
    memset(now,0x00,sizeof now); cout<<dfs(1,1)<<endl; return 0;
}