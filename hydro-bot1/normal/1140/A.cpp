// Hydro submission #625cec5181ef68d42bcbae8d@1650256978141
#include<bits/stdc++.h>
using namespace std;
int a[10000],b,s;
int main()
{
    int n,i;
    cin>>n;
    for(i=1;i<=n;i++)
    {
        cin>>a[i];
        b=max(b,a[i]);
        if(b<=i)
        s++;
    }
    printf("%d\n",s);
    return 0;
}