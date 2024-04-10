#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=5e5+5;
int n;
ll k,h[N];
int main()
{
    int t;scanf("%d",&t);
    while(t--)
    {
        scanf("%d%lld",&n,&k);
        for(int i=1;i<=n;i++)
            scanf("%lld",&h[i]);
        h[0]=99999999999ll;
        bool flag=false;
        for(int i=2;i<=n;i++)
            if(h[i]>h[i-1])
        {
            ll sum=0;
            for(int j=i-1;j>=1;j--)
                if(h[j]<=h[i])
                sum+=h[i]-h[j];
            else break;
            if(sum>=k)
            {
                flag=true;
                for(int j=i-1,len=1;j>=1;j--,len++)
                {
                    ll x=min(h[i]-h[j],h[j-1]-h[j]);
                    ll s=x*len;
                    if(s>=k)
                    {
                        k=k-k/len*len;
                        if(k==0) k=len;
                        printf("%d\n",i-k);
                        break;
                    }
                    else k-=s;
                }
                break;
            }
            else
            {
                k-=sum;
                for(int j=i-1;j>=1;j--)
                    if(h[j]<=h[i]) h[j]=h[i];
                else break;
            }
        }
        if(!flag) printf("-1\n");
    }
}