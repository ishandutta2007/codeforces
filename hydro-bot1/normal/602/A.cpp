// Hydro submission #62ef215174879b352565da7b@1659838802193
#include<bits/stdc++.h>
using namespace std;
long long x,y;
int main()
{
    int n,m,a,b,c,i;
    cin>>a>>n;
    for(i=1;i<=a;i++)
    {
        cin>>c;
        x=x*n+c;
    }
    cin>>b>>m;
    for(i=1;i<=b;i++)
    {
        cin>>c;
        y=y*m+c;
    }
    if(x==y) printf("=\n");
    else printf(x>y?">\n":"<\n");
    return 0;
}