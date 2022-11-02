#include<bits/stdc++.h>
typedef long long ll;
ll a,b;

ll func(ll X) {
    if(!X) return 0;
    ll i,j,k,ret=0,len=0,cnt=0;
    for(i=X;i>0;i/=2) len++;
    for(i=2,j=0;X>=i;i*=2,j++) ret+=j;
    for(i=X,j=len-1,k=0;i>0;i/=2,k++) if(i%2==0) {j=k;cnt++;}
    if(j==len-1) ret+=len-1;
    else ret+=len-2-j;
    return ret+(cnt==1);
}

int main()
{
    ll i,j;
    scanf("%lld%lld",&a,&b);
    a--;
    printf("%lld",func(b)-func(a));
}