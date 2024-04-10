// Hydro submission #6253afe9ca530601467146d9@1649651689548
#include<bits/stdc++.h>
using namespace std;
int main()
{
    int p1,p2,p3,p4,a,b,i,s=0;
    cin>>p1>>p2>>p3>>p4>>a>>b;
    for(i=a;i<=b;i++)
    if(i==i%p1%p2%p3%p4) s++;
    printf("%d\n",s);
    return 0;
}