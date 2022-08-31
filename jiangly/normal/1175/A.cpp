// remote judge
#include<bits/stdc++.h>
using namespace std;
int main(){
    int t;
    scanf("%d",&t);
    for(;t>0;--t){
        long long n,k;
        scanf("%I64d%I64d",&n,&k);
        long long ans=0;
        for(;n>0;n/=k)
            ans+=n%k+1;
        printf("%I64d\n",ans-1);
    }
    return 0;
}