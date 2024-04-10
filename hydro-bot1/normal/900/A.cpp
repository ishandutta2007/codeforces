// Hydro submission #62591e5837de167dd82bc9ab@1650007641266
#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n,i,x,y,s=0;
    cin>>n;
    for(i=0;i<n;i++)
    {
        cin>>x>>y;
        if(x<0) s++;
    }
    if(s<2||n-s<2) printf("Yes\n");
    else printf("No\n");
    return 0;
}