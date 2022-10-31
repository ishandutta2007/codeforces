// Hydro submission #629729e51008115bd64b4f53@1654073829545
#include<bits/stdc++.h>
using namespace std;
int main()
{
    int t,x,y,i;
    cin>>t;
    for(i=0;i<t;i++)
    {
        cin>>x>>y;
        if((x+y)%2)
        printf("-1 -1\n");
        else if(x%2||y%2)
        printf("%d %d\n",x/2,y/2+1);
        else printf("%d %d\n",x/2,y/2);
    }
    return 0;
}