// Hydro submission #6274cfaa997df5291339da57@1651822509276
#include<bits/stdc++.h>
using namespace std;
int main()
{
    int t,i,s;
    long long n;
    cin>>t;
    for(i=0;i<t;i++)
    {
        cin>>n;s=0;
        if(n%2050)
        {
            printf("-1\n");
            continue;
        }
        n/=2050;
        while(n)
        {
            s+=n%10;
            n/=10;
        }
        printf("%d\n",s);
    }
    return 0;
}