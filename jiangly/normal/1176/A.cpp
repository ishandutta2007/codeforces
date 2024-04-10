// remote judge
#include<bits/stdc++.h>
using namespace std;
int main(){
    int q;
    scanf("%d",&q);
    for(int i=0;i<q;++i){
        long long n;
        scanf("%lld",&n);
        int ans=0;
        for(;n%2==0;n/=2)
            ++ans;
        for(;n%3==0;n/=3)
            ans+=2;
        for(;n%5==0;n/=5)
            ans+=3;
        if(n==1)
            printf("%d\n",ans);
        else
            puts("-1");
    }
    return 0;
}