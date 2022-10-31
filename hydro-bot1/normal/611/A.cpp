// Hydro submission #6255078317cd4d0a4176486e@1649739652063
#include<bits/stdc++.h>
using namespace std;
string a,b;
int main()
{
    int x;
    cin>>x>>a>>b;
    if(b[0]=='m')
    {
        if(x<30)
        printf("12\n");
        else if(x<31) printf("11\n");
        else printf("7\n");
        return 0;
    }
    else
    {
        if(x>4&&x<7)
        printf("53\n");
        else
        printf("52\n");
        return 0;
    }
    return 0;
}