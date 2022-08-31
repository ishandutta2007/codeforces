// remote judge
#include<bits/stdc++.h>
using namespace std;
int main(){
#ifndef ONLINE_JUDGE
    freopen("CF1183C.in","r",stdin);
    freopen("CF1183C.out","w",stdout);
#endif
    int q;
    scanf("%d",&q);
    for(;q--;){
        int n,k,a,b;
        scanf("%d%d%d%d",&k,&n,&a,&b);
        if((long long)b*n>=k){
            printf("-1\n");
        }else{
            printf("%d\n",min(n,(k-b*n-1)/(a-b)));
        }
    }
    return 0;
}