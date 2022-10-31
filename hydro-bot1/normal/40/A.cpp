// Hydro submission #6247f793993deab65610775d@1648883604001
#include<bits/stdc++.h>
using namespace std;
int main()
{
    double s,x,y;
    cin>>x>>y;
    s=sqrt(x*x+y*y);
    if(s==int(s))
    printf("black\n");
    else if(x*y<0)
    {
        if(int(s)%2)
        printf("black\n");
        else
        printf("white\n");
    }
    else if(x*y>0)
    {
        if(int(s)%2)
        printf("white\n");
        else
        printf("black\n");
    }
    else printf("black\n");
    return 0;
}