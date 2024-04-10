// Hydro submission #625cea9581ef68d42bcba9b0@1650256534260
#include<bits/stdc++.h>
using namespace std;
int u[100],s,mx;
int main()
{
    int n,k,a,i;
    cin>>n>>k;
    for(i=0;i<n;i++)
    {
        cin>>a;
        u[a-1]++;
        if(u[a-1]>mx)
        mx=u[a-1];
    }
    for(i=0;i<100;i++)
    if(u[i]) s++;
    mx=mx%k?mx+k-mx%k:mx;
    printf("%d\n",s*mx-n);
    return 0;
}