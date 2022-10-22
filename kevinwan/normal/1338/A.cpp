#include<bits/stdc++.h>
using namespace std;
typedef pair<int,int>pii;
mt19937 rng(423978);
typedef long long ll;
typedef pair<ll,ll>pll;
const ll mod=998244353;
const int mn=1<<18;
ll a[mn];
int main(){
    int tc;
    scanf("%d",&tc);
    while(tc--){
        int n;
        scanf("%d",&n);
        ll ans=0,mo=0xc0c0c0c0c0c0c0c0;
        for(int i=0;i<n;i++){
            scanf("%lld",a+i);
            mo=max(mo,a[i]);
            ans=max(ans,mo-a[i]);
        }
        if(ans==0)printf("0\n");
        else{
            ans=64-__builtin_clzll(ans);
            printf("%lld\n",ans);
        }
    }
}