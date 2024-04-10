// Hydro submission #6253c3c148f7830132791bd0@1649656770420
#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n,x,y,i;
    cin>>n>>x>>y;
    for(i=0;;i++)
    if((x+i)*1.0/n>=y/100.0)
    {
        printf("%d\n",i);
        return 0;
    }
    return 0;
}