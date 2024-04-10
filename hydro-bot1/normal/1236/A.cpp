// Hydro submission #626777ee255d14008c299995@1650948079446
#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n,a,b,c,s,i;
    cin>>n;
    for(i=0;i<n;i++)
    {
        cin>>a>>b>>c;s=0;
        while(b&&c>1)
        s+=3,b--,c-=2;
        while(a&&b>1)
        s+=3,a--,b-=2;
        printf("%d\n",s);
    }
    return 0;
}