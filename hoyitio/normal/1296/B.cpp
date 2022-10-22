#include<bits/stdc++.h>
#define LL long long
#define PB push_back
using namespace std;
const int INF=0x3f3f3f3f;
const int N=1e6+10,M=N*400,mod=1e9+7;
int main()
{
    int t;
    cin>>t;
    while(t--){
        int n;
        scanf("%d",&n);
        LL ans=0;
        while(n>=10){
            ans+=n/10*10;
            n=n%10+n/10;
        }
        ans+=n;
        printf("%lld\n",ans);

    }
    return 0;
}
/*
*/