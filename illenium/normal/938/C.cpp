#include<bits/stdc++.h>
#define MAX 1e5+10
using namespace std;
typedef long long ll;

int main()
{
    int T;
    scanf("%d",&T);
    while(T--)
    {
        ll x;
        scanf("%lld",&x);
        if(x==0) printf("1 1\n");
        else if(x==1) printf("-1\n");
        else
        {
            int flag=0;
            for(ll n=1;n<MAX;n++)
            {
                if(n*n<=x) continue;  
                ll k=sqrt(n*n-x);
                ll m=n/k;
                if(k>0&&n*n-(n/m)*(n/m)==x)
                {
                    flag=1;
                    printf("%lld %lld\n",n,m);
                    break;
                }	
            }
            if(!flag) printf("-1\n");
        }
    }
    return 0;
}