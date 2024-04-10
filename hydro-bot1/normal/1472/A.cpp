// Hydro submission #6274ccb2bda16328ffbaf98e@1651821746744
#include<bits/stdc++.h>
using namespace std;
int main()
{
    int t,w,h,n,s,i;
    cin>>t;
    for(i=0;i<t;i++)
    {
        cin>>w>>h>>n;s=0;
        while((w*h>>s&1)==0) s++;
        printf(1<<s<n?"NO\n":"YES\n");
    }
    return 0;
}