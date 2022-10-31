// Hydro submission #62550d8817cd4d0a41764d74@1649741200340
#include<bits/stdc++.h>
using namespace std;
int k2,k3,k5,k6,s,t;
int main()
{
    cin>>k2>>k3>>k5>>k6;
    t=min(k2,min(k5,k6));
    s+=t*256;k2-=t,k5-=t,k6-=t;
    t=min(k2,k3);
    s+=t*32;
    printf("%d\n",s);
    return 0;
}