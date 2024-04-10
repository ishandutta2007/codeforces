// Hydro submission #631f2f4132ae6c3198c90d6a@1662988098256
#include<bits/stdc++.h>
using namespace std;
int main()
{
    int t,n,m,sx,sy,d;
    cin>>t;
    while(t--)
    {
        cin>>n>>m>>sx>>sy>>d;
        printf(min(sx-1,m-sy)>d||min(sy-1,n-sx)>d?"%d\n":"-1\n",n+m-2);
    }
    return 0;
}