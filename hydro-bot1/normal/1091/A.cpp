// Hydro submission #625ceb8e81ef68d42bcbacb6@1650256783271
#include<bits/stdc++.h>
using namespace std;
int main()
{
    int y,b,r;
    cin>>y>>b>>r;
    printf("%d\n",3*min(min(y+1,b),r-1));
    return 0;
}