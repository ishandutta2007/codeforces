// Hydro submission #62591f17cc64917dc466526f@1650007832386
#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n,m,i,s=1;
    cin>>n>>m;
    if(n>26) printf("%d\n",m);//2$^27>10$^8
    else printf("%d\n",m%(1<<n));
    return 0;
}