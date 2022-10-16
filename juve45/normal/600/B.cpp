#include <bits/stdc++.h>

using namespace std;

int n, m, a[200009], b[200009];

int bin(int k, int st, int dr)
{
    if(st==dr)
        return st;
    int mid=(st+dr+1)/2;
    if(a[mid]<=k)
        return bin(k, mid, dr);
    return bin(k, st, mid-1);
}

int main()
{
cin>>n>>m;
a[0]=-1000000001;
for(int i=1;i<=n;i++)
{
    cin>>a[i];
}

for(int i=1;i<=m;i++)
{
    cin>>b[i];
}

sort(a+1, a+n+1);
for(int i=1;i<=m;i++)
{
    cout<<bin(b[i], 0, n)<<' ';
}
cout<<'\n';
    return 0;
}