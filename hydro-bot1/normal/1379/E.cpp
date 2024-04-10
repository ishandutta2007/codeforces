// Hydro submission #617c9f0763b6465eb4e57c19@1635557128139
#include<bits/stdc++.h>
using namespace std;
const int N=1e5+5;
int n,k,f[N];
bool chk(int x){return x-(x&-x)==0;}
int main() {
    scanf("%d%d",&n,&k);
    if(n%2==0)return puts("NO"),0;
    if(n==9&&k==2)return puts("NO"),0;
    if(k>max(0,(n-3)/2))return puts("NO"),0;
    if(k==0&&!chk(n+1))return puts("NO"),0;
    if(k==1&&chk(n+1))return puts("NO"),0;
    puts("YES");
    if(!k){
        for(int i=1;i<=n;i++)printf("%d ",i/2);
        return 0;
    }
    int t=(k-1)*2;
    for(int i=1;i<=n-t;i++)f[i]=i/2;
    if(t){
        f[1]=n-t+1;
        for(int i=n-t+1;i<=n;i+=2)f[i]=i+2,f[i+1]=i;
        f[n-1]=0;
        if(chk(n-t+1))f[n-t]=f[n-t-1]=n;
    }
    for(int i=1;i<=n;i++)printf("%d ",f[i]);
    return 0;
}