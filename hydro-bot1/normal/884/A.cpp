// Hydro submission #62591c8037de167dd82bc525@1650007168195
#include<bits/stdc++.h>
using namespace std;
int a[100],s;
int main()
{
    int i,n,t;
    cin>>n>>t;
    for(i=0;i<n;i++)
    cin>>a[i];
    for(i=0;i<n;i++)
    {
        s+=86400-a[i];
        if(s>=t)
        {
            printf("%d\n",i+1);
            return 0;
        }
    }
    return 0;
}