#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll k[300001];
int main(){
    int n,i;
    ll x=0,c,ans=0;
    scanf("%d",&n);
    for(i=0;i<n;i++){
        scanf("%lld",&c);
        ll rem=min(c/2,x);
        x-=rem;
        c-=2*rem;
        ans+=rem;
        ans+=c/3;
        c%=3;
        x+=c;
    }
    printf("%lld",ans);
}