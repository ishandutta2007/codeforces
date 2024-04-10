// Hydro submission #6274cd24bda16328ffbaf9ac@1651821861282
#include<bits/stdc++.h>
using namespace std;
int main()
{
    int t,n,x,i;
    cin>>t;
    for(i=0;i<t;i++)
    {
        cin>>n;
        x=n/2020;
        printf(n<2020*x||n>2021*x?"NO\n":"YES\n");
    }
    return 0;
}