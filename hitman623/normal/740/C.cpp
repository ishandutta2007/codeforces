#include <bits/stdc++.h>

using namespace std;

int main()
{
    long n,m,i,a[100000][2],d=10000000007;
    cin>>n>>m;
    for(i=0;i<m;++i)
    {cin>>a[i][0]>>a[i][1];d=min(d,abs(a[i][0]-a[i][1]));}
    cout<<d+1<<endl;
    for(i=0;i<n;++i)
    {
        cout<<i%(d+1)<<" ";
    }
    return 0;
}