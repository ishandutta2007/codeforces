// Hydro submission #62591dd937de167dd82bc78a@1650007513691
#include<bits/stdc++.h>
using namespace std;
int s,t,q[100];
int main()
{
    string c;cin>>c;
    int i,l=c.size();
    for(i=0;i<l;i++)
    if(c[i]=='Q')
    q[i]=++t;
    else q[i]=t;
    for(i=0;i<l;i++)
    if(c[i]=='A')
    s+=q[i]*(t-q[i]);
    printf("%d\n",s);
    return 0;
}