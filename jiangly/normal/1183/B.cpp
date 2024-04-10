// remote judge
#include<bits/stdc++.h>
using namespace std;
int main(){
#ifndef ONLINE_JUDGE
    freopen("CF1183B.in","r",stdin);
    freopen("CF1183B.out","w",stdout);
#endif
    int q;
    scanf("%d",&q);
    for(;q--;){
        int n,k;
        scanf("%d%d",&n,&k);
        int mn=1e8,mx=0;
        for(;n--;){
            int a;
            scanf("%d",&a);
            mn=min(mn,a);
            mx=max(mx,a);
        }
        if(mx-mn>k*2){
            printf("-1\n");
        }else{
            printf("%d\n",mn+k);
        }
    }
    return 0;
}