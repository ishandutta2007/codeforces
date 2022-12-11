#include<iostream>
#include<cstdio>
#include<cmath>
#include<cstring>
#include<algorithm>
using namespace std;
int x[600000],n,pd[600000];
int main(){
    scanf("%d",&n);
    memset(x,0x00,sizeof x);
    for (int i=1;i<=n;i++) scanf("%d",&x[i]);
    sort(x+1,x+n+1);
    int ans=n,now=n/2;
    memset(pd,0x00,sizeof pd);
    for (int i=n;i>=n/2;i--){
        if (pd[i]) continue;
        while (now&&x[now]*2>x[i]) now--;
        if (now==0) break; ans--; pd[now]=1; now--;
    }
    cout<<ans<<endl; return 0;
}