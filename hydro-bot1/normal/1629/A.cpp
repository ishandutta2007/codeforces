// Hydro submission #62972b60b0c5e75beb158543@1654074208462
#include<bits/stdc++.h>
using namespace std;
struct o{
    int a,b;
}r[100];
bool cmp(o x,o y)
{
    return x.a<y.a;
}
int main()
{
    int t,n,k,i,j;
    cin>>t;
    for(i=0;i<t;i++)
    {
        cin>>n>>k;
        for(j=0;j<n;j++)
        cin>>r[j].a;
        for(j=0;j<n;j++)
        cin>>r[j].b;
        sort(r,r+n,cmp);
        for(j=0;j<n&&k>=r[j].a;j++)
        k+=r[j].b;
        printf("%d\n",k);
    }
    return 0;
}