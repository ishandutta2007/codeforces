// Hydro submission #62591f2d37de167dd82bcc26@1650007854316
#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n,i,a,mx=-1000000;
    cin>>n;
    for(i=0;i<n;i++)
    {
        cin>>a;
        if(sqrt(a)*int(sqrt(a))!=a)
        mx=max(mx,a);
    }
    printf("%d\n",mx);
    return 0;
}