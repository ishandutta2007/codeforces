// Hydro submission #6253c60348f7830132791d00@1649657347923
#include<bits/stdc++.h>
using namespace std;
int main()
{
    int a,b,n,m,s=0;
    cin>>n>>m;
    for(a=0;a<=min(m,n);a++)
    for(b=0;b<=min(m,n);b++)
    if(a*a+b==n&&b*b+a==m)
    s++;printf("%d\n",s);
    return 0;
}