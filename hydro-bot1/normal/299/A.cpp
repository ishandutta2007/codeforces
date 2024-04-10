// Hydro submission #6253d101ca53060146716f37@1649660161846
#include<bits/stdc++.h>
using namespace std;
int a[100000],s;
int main()
{
    int n,i,mn=1000000000;
    cin>>n;
    for(i=0;i<n;i++)
    {
        cin>>a[i];
        if(a[i]<mn)
        mn=a[i];
    }
    for(i=0;i<n;i++)
    s+=a[i]%mn;
    if(s) printf("-1\n");
    else printf("%d\n",mn);
    return 0;
}