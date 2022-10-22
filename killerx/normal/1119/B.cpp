#include<bits/stdc++.h>
using namespace std;
const int N=1<<10;
int n,h,a[N];
int main(){
    scanf("%d%d",&n,&h);
    for(int i=1;i<=n;++i)scanf("%d",a+i);
    int ans=0;
    for(int i=1;i<=n;++i){
        sort(a+1,a+1+i);
        int nw=0,cnt=0;
        for(int j=1+(i%2);j<=i;j+=2){
            if(nw+a[j+1]<=h)nw+=a[j+1],cnt+=2;else break;
        }
        if(i%2)if(nw+a[1]<=h)nw+=a[1],cnt++;
        if(cnt==i)ans=i;else break;
    }
    printf("%d\n",ans);
    return 0;
}