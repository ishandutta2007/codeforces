// Hydro submission #625ced97fa9408d417feaa99@1650257303403
#include<bits/stdc++.h>
using namespace std;
int main()
{
    int x,y,z;
    cin>>x>>y>>z;
    if(!z&&x==y) printf("0\n");
    else if(x>y+z) printf("+\n");
    else if(y>x+z) printf("-\n");
    else printf("?\n");
    return 0;
}