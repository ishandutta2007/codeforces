// Hydro submission #6274d104997df5291339de07@1651822853059
#include<bits/stdc++.h>
using namespace std;
int main()
{
    int t,n,a,s,i,j;
    cin>>t;
    for(i=0;i<t;i++)
    {
        cin>>n;s=0;
        for(j=0;j<n;j++)
        {
            cin>>a;
            s+=a;
        }
        if(s<n) printf("1\n");
        else printf("%d\n",s-n);
    }
    return 0;
}