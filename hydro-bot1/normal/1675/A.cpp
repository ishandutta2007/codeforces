// Hydro submission #6291d7f21313ac7ae9c0e8f1@1653747169596
#include<bits/stdc++.h>
using namespace std;
int main()
{
    int t,a,b,c,x,y;
    cin>>t;
    while(t--)
    {
        cin>>a>>b>>c>>x>>y;
        printf(a+c<x||b+c<y||a+b+c<x+y?"NO\n":"YES\n");
    }
    return 0;
}