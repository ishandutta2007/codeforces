#include<cstdio>
#include<algorithm>
#include<cstring>
#include<iostream>
#include<cstdlib>
#include<vector>
#include<string>
#include<queue>
#include<map>
typedef long long ll;
#define mo 1000000007
int A,B,q;

ll su(ll l,ll r){
    ll x1=A+(l-1)*B,x2=A+(r-1)*B;
    return 1ll*(x1+x2)*(r-l+1)/2;
}
ll x(ll i){
    return A+(i-1)*B;
}
int main()
{
    scanf("%d%d%d",&A,&B,&q);
    while(q--){
        int l,t,m;
        scanf("%d%d%d",&l,&t,&m);
        int lef=l,rig=l+t+5,mid;
        while(lef<=rig){
            mid=lef+rig>>1;
            if(x(mid)<=t && su(l,mid)<=1ll*t*m)lef=mid+1;
            else rig=mid-1;
        }
        if(rig==l-1)printf("-1\n");
        else printf("%d\n",rig);
    }
    return 0;
}