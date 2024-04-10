// Hydro submission #6247f40e0bc575b66aa57c88@1648882703181
#include<bits/stdc++.h>
using namespace std;
int main()
{
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    int n,a,b,i;
    cin>>n;
    for(i=0;i<3;i++)
    {
        cin>>a>>b;
        if(n==a)
        n=b;
        else if(n==b)
        n=a;
    }
    printf("%d\n",n);
    return 0;
}