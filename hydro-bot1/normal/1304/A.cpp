// Hydro submission #626779eb255d14008c299d4b@1650948587152
#include<bits/stdc++.h>
using namespace std;
int main()
{
    int t,x,y,a,b,i;
    cin>>t;
    for(i=0;i<t;i++)
    {
        cin>>x>>y>>a>>b;
        if((y-x)%(a+b)) printf("-1\n");
        else printf("%d\n",(y-x)/(a+b));
    }
    return 0;
}