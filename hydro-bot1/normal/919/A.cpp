// Hydro submission #62591f6837de167dd82bcd01@1650007912690
#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n,m,i;
    float a,b,mn=100;
    cin>>n>>m;
    for(i=0;i<n;i++)
    {
        cin>>a>>b;
        mn=min(mn,a/b);
    }
    printf("%f\n",m*mn);
    return 0;
}