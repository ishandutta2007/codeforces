// Hydro submission #625506f417cd4d0a417647f8@1649739509998
#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n,x,i,s=0;
    cin>>n>>x;
    for(i=1;i<=n;i++)
    if(x%i==0&&x/i<=n)
    s++;printf("%d\n",s);
    return 0;
}