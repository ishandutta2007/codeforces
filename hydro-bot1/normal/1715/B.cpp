// Hydro submission #631f2f0932ae6c3198c90d3b@1662988042793
#include<bits/stdc++.h>
using namespace std;
long long a[100001];
int main()
{
    int t,n,b,i;
    long long k,s,mn;
    cin>>t;
    while(t--)
    {
        memset(a,0,sizeof(a));
        cin>>n>>k>>b>>s;
        s-=k*b;
        if(s<0) printf("-1");
        else
        {
            a[1]=k*b;
            for(i=1;i<=n;i++)
            {
                mn=min(s,k-1);
                a[i]+=mn,s-=mn;
            }
            if(s>0) printf("-1");
            else for(i=1;i<=n;i++)
            printf("%lld ",a[i]);
        }
        cout<<endl;
    }
    return 0;
}