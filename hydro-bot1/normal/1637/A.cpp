// Hydro submission #62972c111008115bd64b50f6@1654074386815
#include<bits/stdc++.h>
using namespace std;
int main()
{
    int t,n,a,b,i,j;
    cin>>t;
    bool f;
    for(i=0;i<t;i++)
    {
        cin>>n;b=0,f=true;
        for(j=0;j<n;j++)
        {
            cin>>a;
            if(a<b)
            f=false;
            b=a;
        }
        printf(f?"NO\n":"YES\n");
    }
    return 0;
}