// Hydro submission #62591b2f37de167dd82bc0d7@1650006839264
#include<bits/stdc++.h>
using namespace std;
int main()
{
    int k,r,mx,i;
    cin>>k;
    for(i=0;i<k;i++)
    {
        cin>>r;
        mx=max(mx,r);
    }
    printf("%d\n",max(mx-25,0));
    return 0;
}