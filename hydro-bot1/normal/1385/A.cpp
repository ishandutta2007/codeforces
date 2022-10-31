// Hydro submission #6274c92d997df5291339c851@1651820846389
#include<bits/stdc++.h>
using namespace std;
int main()
{
    int t,x[3],i;
    cin>>t;
    for(i=0;i<t;i++)
    {
        cin>>x[0]>>x[1]>>x[2];
        sort(x,x+3);
        if(x[1]==x[2])
        printf("YES\n%d %d %d\n",x[0],x[0],x[1]);
        else printf("NO\n");
    }
    return 0;
}