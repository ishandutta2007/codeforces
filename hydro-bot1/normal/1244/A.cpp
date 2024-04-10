// Hydro submission #626778259f31360077e129a6@1650948133452
#include<bits/stdc++.h>
using namespace std;
int main()
{
    int t,a,b,c,d,x,y,k,i;
    cin>>t;
    for(i=0;i<t;i++)
    {
        cin>>a>>b>>c>>d>>k;
        x=ceil(a*1.0/c);
        y=ceil(b*1.0/d);
        if(x+y>k)
        printf("-1\n");
        else printf("%d %d\n",x,y);
    }
    return 0;
}