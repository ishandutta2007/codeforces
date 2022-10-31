// Hydro submission #62590d4ecc64917dc466452c@1650003279382
#include<bits/stdc++.h>
using namespace std;
int s,t;
int main()
{
    int n,k,a,i;
    cin>>n>>k;
    for(i=0;i<n;i++)
    {
        cin>>a;
        s+=min(a+t,8);
        t=max(a+t-8,0);
        if(s>=k)
        {
            printf("%d\n",i+1);
            return 0;
        }
    }
    printf("-1\n");
    return 0;
}