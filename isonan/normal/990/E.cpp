#include <cstdio>
#include <algorithm>
using namespace std;

int n,m,k,a[1000010],st[1000010],cnt,mx;
int main(){
    scanf("%d%d%d",&n,&m,&k);
    n++;
    int tem=0;
    for(int i=1;i<=n;i++)st[i]=i;
    for(int i=1;i<=m;i++){
        scanf("%d",&tem);
        tem++;
        if(tem==1){
            puts("-1");
            return 0;
        }
        st[tem]=-1;
        if(st[tem]==st[tem-1])cnt++;
        else cnt=1;
        if(mx<cnt)mx=cnt;
    }
    for(int i=2;i<=n;i++)st[i]=max(st[i],st[i-1]);
    for(int i=1;i<=k;i++)scanf("%d",a+i);
    if(mx>=k){
        puts("-1");
        return 0;
    }
    if(st[1]==-1){
        puts("-1");
        return 0;
    }
    long long ans=1000000000000000000ll;
    for(int i=mx+1;i<=k;i++){
        int cnt=1,tot=0;
        while(cnt<n){
            cnt=st[cnt]+i;
            tot++;
        }
        ans=min(ans,(long long)tot*a[i]);
    }
    printf("%I64d",ans);
}