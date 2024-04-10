// Hydro submission #62591e4637de167dd82bc959@1650007623871
#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n,i,a,s1=0,s;
    cin>>n;
    for(i=0;i<n;i++)
    {
        cin>>a;
        if(a==1) s1++;
    }
    s=min(s1,n-s1);
    printf("%d\n",s+max(s1-s,0)/3);
    return 0;
}