// Hydro submission #62ef20fc74296d3511bba7d9@1659838716550
#include<bits/stdc++.h>
using namespace std;
int x[100002];
int main()
{
    int n,i;cin>>n;
    for(i=1;i<=n;i++)
    cin>>x[i];
    x[0]=x[2],x[n+1]=x[n-1];
    for(i=1;i<=n;i++)
    printf("%d %d\n",min(abs(x[i-1]-x[i]),abs(x[i+1]-x[i])),max(x[i]-x[1],x[n]-x[i]));
    return 0;
}