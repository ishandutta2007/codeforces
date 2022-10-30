// Hydro submission #625cec8bfa9408d417fea9b5@1650257036299
#include<bits/stdc++.h>
using namespace std;
void f(int b[],int p)
{
    b[p]^=1;
    if(p&&b[p])
    f(b,p-1);
}
int main()
{
    int a,b[4],s=0,i;
    cin>>a;
    for(i=0;i<4;i++)
    b[i]=a>>i&1;
    f(b,3);
    for(i=0;i<4;i++)
    s|=b[i]<<i;
    printf("%d\n",s);
    return 0;
}