// Hydro submission #62591c2637de167dd82bc35d@1650007079188
#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n,k,x,s=0,c,i;
    cin>>n>>k>>x;
    for(i=0;i<n;i++)
    if(i<n-k)
    cin>>c,s+=c;
    else s+=x;
    printf("%d\n",s);
    return 0;
}