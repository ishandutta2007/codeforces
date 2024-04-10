// Hydro submission #62591fbdcc64917dc46652c1@1650007998470
#include<bits/stdc++.h>
using namespace std;
int main()
{
    int x,y;
    cin>>x>>y;
    printf(y==1&&!x||y>1&&y-x<2&&(x-y)%2?"Yes\n":"No\n");
    return 0;
}