// Hydro submission #62592130cc64917dc46654ae@1650008379032
#include<bits/stdc++.h>
using namespace std;
int t[100];
int main()
{
    int n,s,h,m,i;
    cin>>n>>s;
    for(i=0;i<n;i++)
    {
        cin>>h>>m;
        t[i]=h*60+m;
        if(!i&&t[i]>s)
        {
            printf("0 0\n");
            return 0;
        }
        else if(i&&t[i]-t[i-1]>=s*2+2)
        {
            printf("%d %d\n",(t[i-1]+s+1)/60,(t[i-1]+s+1)%60);
            return 0;
        }
    }
    printf("%d %d\n",(t[n-1]+s+1)/60,(t[i-1]+s+1)%60);
    return 0;
}