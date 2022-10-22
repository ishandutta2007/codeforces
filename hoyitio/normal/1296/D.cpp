#include<bits/stdc++.h>
#define LL long long
#define PB push_back
#define PII pair<int,int>
using namespace std;
const int INF=0x3f3f3f3f;
const int N=1e6+10,M=N*400,mod=1e9+7;
LL n,a,b,k;
LL ans[N];
int main()
{
    cin>>n>>a>>b>>k;
    for(int i=1;i<=n;i++){
        LL x;
        scanf("%lld",&x);
        x%=(a+b);
        if(x==0)x=a+b;
        if(x<=a){
            ans[i]=0;
            continue;
        }
        x-=a;
        ans[i]=x/a+(x%a>0);
    }
    sort(ans+1,ans+1+n);
    int as=0;
    for(int i=1;i<=n;i++){
        if(k>=ans[i]){
            k-=ans[i];
            as++;
        }
    }
    cout<<as;
    return 0;
}
/*
*/