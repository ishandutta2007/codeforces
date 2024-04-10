// Hydro submission #6247f08a993deab656107065@1648881803965
#include<bits/stdc++.h>
using namespace std;
bool f[100];
int main()
{
    int n,m,i;
    cin>>n;
    for(i=0;i<n;i++)
    {
        cin>>m;
        f[i]=m%2;
    }
    if(f[n-1]!=f[n-3]&&f[n-1]!=f[n-2])
    printf("%d\n",n);
    else if(f[0]!=f[1]&&f[0]!=f[2])
    printf("1\n");
    else
    {
        for(i=1;i<n-1;i++)
        if(f[i]!=f[i-1]&&f[i]!=f[i+1])
        printf("%d",i+1);
    }
    return 0;
}