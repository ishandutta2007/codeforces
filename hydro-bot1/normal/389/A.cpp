// Hydro submission #6253d41348f78301327929be@1649660948836
#include<bits/stdc++.h>
using namespace std;
int main()
{
    int x,n,i,s;
    cin>>n>>s;
    for(i=1;i<n;i++)
    {
        cin>>x;
        s=__gcd(s,x);
    }
    printf("%d\n",s*n);
    return 0;
}