// Hydro submission #6253d32e48f78301327928fa@1649660722870
#include<bits/stdc++.h>
using namespace std;
int main()
{
    int c1,c2,c3,c4,n,m,a,b,i,sa=0,sb=0;
    cin>>c1>>c2>>c3>>c4>>n>>m;
    for(i=0;i<n;i++)
    {
        cin>>a;
        sa+=min(a*c1,c2);
    }
    for(i=0;i<m;i++)
    {
        cin>>b;
        sb+=min(b*c1,c2);
    }
    printf("%d\n",min(min(sa,c3)+min(sb,c3),c4));
    return 0;
}