// Hydro submission #6274c955997df5291339c88d@1651820886187
#include<bits/stdc++.h>
using namespace std;
int main()
{
    int t,l,r,i;
    cin>>t;
    for(i=0;i<t;i++)
    {
        cin>>l>>r;
        if(r<l*2) printf("-1 -1\n");
        else printf("%d %d\n",l,l*2);
    }
    return 0;
}