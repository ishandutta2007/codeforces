// Hydro submission #6274c97ebda16328ffbaf6a2@1651820927273
#include<bits/stdc++.h>
using namespace std;
int main()
{
    int t,n,a,b,c,i,j;
    cin>>t;
    for(i=0;i<t;i++)
    {
        cin>>n>>a>>b;
        for(j=2;j<n;j++)
        cin>>c;
        if(a+b>c)
        printf("-1\n");
        else printf("1 2 %d\n",n);
    }
    return 0;
}