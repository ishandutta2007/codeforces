// Hydro submission #6274d04ebda16328ffbafe2d@1651822671309
#include<bits/stdc++.h>
using namespace std;
int main()
{
    int t,a,b,i;
    long long s;
    cin>>t;
    for(i=0;i<t;i++)
    {
        cin>>a>>b;s=1;
        if(b==1)
        {
            printf("NO\n");
            continue;
        }
        printf("YES\n");
        if(b==2) b=4;
        s*=a,s*=b;
        printf("%d %lld %lld\n",a,s-a,s);
    }
    return 0;
}