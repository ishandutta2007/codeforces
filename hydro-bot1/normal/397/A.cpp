// Hydro submission #6253d46248f78301327929f3@1649661027124
#include<bits/stdc++.h>
using namespace std;
bool f[100];
int main()
{
    int n,i,j,a,b,l,r,s=0;
    cin>>n>>a>>b;
    for(i=1;i<n;i++)
    {
        cin>>l>>r;
        for(j=l;j<r;j++)
        f[j]=true;
    }
    for(i=a;i<b;i++)
    if(!f[i]) s++;
    printf("%d\n",s);
    return 0;
}