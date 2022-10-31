// Hydro submission #6253c132ca530601467156e8@1649656114370
#include<bits/stdc++.h>
using namespace std;
int a[1000];
int main()
{
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    int n,k,i;
    cin>>n>>k;
    for(i=1;i<=n;i++)
    cin>>a[i];
    while(!a[k])
    {
        k++;
        if(k>n)
        k=1;
    }
    printf("%d\n",k);
    return 0;
}