#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int main()
{
    int t;scanf("%d",&t);
    while(t--)
    {
        ll x,y,a,b;scanf("%lld%lld%lld%lld",&x,&y,&a,&b);
        if((y-x)%(a+b)==0&&(y-x)/(a+b)>=0)
            printf("%d\n",(y-x)/(a+b));
        else printf("-1\n");
    }
}