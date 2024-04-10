#include <cstdio>
#include <algorithm>
using namespace std;

int n,k,a[100001];
int main(){
    scanf("%d%d",&n,&k);
    for(int i=1;i<=n;i++){
        scanf("%d",a+i);
    }
    sort(a+1,a+n+1);
    int lim=unique(a+1,a+n+1)-a-1;
    for(int i=1;i<=lim&&i<=k;i++)printf("%d\n",a[i]-a[i-1]);
    for(int i=1;i<=k-lim;i++)printf("%d\n",0);
}