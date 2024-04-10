#include <bits/stdc++.h>

using namespace std;

int n, a[110];

int main()
{
cin>>n;


for(int i=1;i<=n;i++)
{
    cin>>a[i];
}

for(int i=1;i<n;i++)
{
    int minp=i;
    for(int j=i+1;j<=n;j++)
    {
        if(a[j]<a[minp])
        {
            minp=j;
        }
    }
    for(int k=minp;k>i;k--)
    {
        cout<<k-1<<' '<<k<<'\n';
        swap(a[k-1], a[k]);
    }
}

    return 0;
}