// Hydro submission #625cef2bfa9408d417feac27@1650257707681
#include<bits/stdc++.h>
using namespace std;
int main()
{
    int t,x,y,z,i;
    cin>>t;
    for(i=0;i<t;i++)
    {
        cin>>x>>y>>z;
        if(x-y+z<=0)
        printf("0\n");
        else if(x-y-z>0)
        printf("%d\n",z+1);
        else printf("%d\n",(x-y+z+1)/2);
    }
    
    return 0;
}