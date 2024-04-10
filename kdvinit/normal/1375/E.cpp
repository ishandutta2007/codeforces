#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int n;
    cin>>n;

    int a[n+1],m=(n*n)/2;
    long long int b[n+1],c[n+1];

    int ans1[m],ans2[m],cntr=0;
    for(int i=1;i<=n;i++)
    {
        cin>>b[i];
        c[i]=b[i];
    }
    sort(c+1,c+n+1);

    for(int i=1;i<=n;i++)
    {
        long long int x=c[i];
        int j;
        for(j=1;j<=n;j++)
        {
            if(b[j]==x)break;
        }
        b[j]=0;
        a[j]=i;
    }

    while(1)
    {
        if(n==1) break;

        int x=a[n];
        for(int i=1;i<n;i++)
        {
            if(a[i]<x) continue;
            int y=a[i]-x;
            ans1[cntr+y]=i;
            ans2[cntr+y]=n;
            a[i]--;
        }

        cntr+=n-x;
        n--;
    }

    cout<<cntr<<endl;
    for(int i=1;i<=cntr;i++)
    {
        cout<<ans1[i]<<" "<<ans2[i]<<endl;
    }

    return 0;
}