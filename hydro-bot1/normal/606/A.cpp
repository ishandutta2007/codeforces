// Hydro submission #62ef218074296d3511bba82e@1659838848343
#include<bits/stdc++.h>
#define work(f,d) f?n+=(d)/2:m-=d
using namespace std;
int n,m;
int main()
{
    int a,b,c,x,y,z;
    cin>>a>>b>>c>>x>>y>>z;
    work(a>x,a-x);
    work(b>y,b-y);
    work(c>z,c-z);
    if(n<m) printf("No\n");
    else printf("Yes\n");
    return 0;
}