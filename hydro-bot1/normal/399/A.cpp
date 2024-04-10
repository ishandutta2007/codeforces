// Hydro submission #6253d484ca530601467174f0@1649661061221
#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n,p,k,i;
    cin>>n>>p>>k;
    if(p-k>1) printf("<< ");
    for(i=p-k;i<=p+k&&i<=n;i++)
    {
    	if(i<1) continue;
        if(i==p) printf("(%d) ",i);
        else printf("%d ",i);
    }
    if(p+k<n) printf(">>\n");
    return 0;
}