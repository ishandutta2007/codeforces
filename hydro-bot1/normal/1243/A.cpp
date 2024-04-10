// Hydro submission #62ef221674879b352565dbc8@1659838998911
#include<bits/stdc++.h>
using namespace std;
int s[1002];
int main()
{
    int t,n,a,i;
    cin>>t;
    while(t--)
    {
        cin>>n;
        memset(s,0,sizeof(s));
        for(i=1;i<=n;i++)
        cin>>a,s[a]++;
        for(i=n;i>=1;i--)
        {
            s[i]+=s[i+1];
            if(s[i]>=i)
            {
                printf("%d\n",i);
                break;
            }
        }
    }
    return 0;
}