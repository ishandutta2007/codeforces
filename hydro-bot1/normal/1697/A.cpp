// Hydro submission #62be563a12be0219046916b5@1656641082629
#include<bits/stdc++.h>
using namespace std;
int main()
{
    int t,n,m,a,s,i;
    cin>>t;
    while(t--)
    {
        cin>>n>>m;s=0;
        for(i=0;i<n;i++)
        cin>>a,s+=a;
        printf("%d\n",max(s-m,0));
    }
    return 0;
}