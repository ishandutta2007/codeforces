// Hydro submission #6253c1de48f7830132791aa8@1649656286422
#include<bits/stdc++.h>
using namespace std;
int a[100],s,t;
int main()
{
    int n,i;
    cin>>n;
    for(i=0;i<n;i++)
    {
        cin>>a[i];
        s+=a[i];
    }
    for(i=0;i<n;i++)
    if(a[i]%2) t++;
    if(s%2) printf("%d\n",t);
    else printf("%d\n",n-t);
    return 0;
}