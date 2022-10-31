// Hydro submission #62972a711008115bd64b4faa@1654073970004
#include<bits/stdc++.h>
using namespace std;
int main()
{
    int t,i;
    double n;
    cin>>t;
    for(i=0;i<t;i++)
    {
        cin>>n;
        n+=0.00001;
        printf("%d\n",int(pow(n,1.0/2))+int(pow(n,1.0/3))-int(pow(n,1.0/6)));
    }
    return 0;
}