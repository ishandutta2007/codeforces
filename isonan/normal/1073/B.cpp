#include <cstdio>
#include <algorithm>

using namespace std;
int n,a[200001],b[200001],cnt,pos[200001];
int main(){
    scanf("%d",&n);
    for(int i=1;i<=n;i++)scanf("%d",a+i),pos[a[i]]=i;
    for(int i=1;i<=n;i++){
        int tem;
        scanf("%d",&tem);
        if(pos[tem]<=cnt)printf("0 ");
        else printf("%d ",pos[tem]-cnt);
        cnt=max(cnt,pos[tem]);
    }
}