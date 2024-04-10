// Hydro submission #62550d6bac286d0a56b86bc8@1649741234196
#include<bits/stdc++.h>
using namespace std;
string c;
int main()
{
    cin>>c;int i,s=-1,t;
    for(i=0;i<c.size();i++)
    if(c[i]==65||c[i]==69
    ||c[i]==73||c[i]==79
    ||c[i]==85||c[i]==89)
    t=max(t,i-s),s=i;
    printf("%d\n",max(t,int(c.size())-s));
    return 0;
}