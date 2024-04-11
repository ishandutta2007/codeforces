#include <bits/stdc++.h>
using namespace std;

long long f(long long n, long long x)
{
    if (x%2==1)
        return (x/2+1);
    if (n%2==0)
        return (f(n/2,x/2)+n/2);
    return (f(n/2+1,x/2+1)+n/2);
}


int main()
{
    iostream::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    long long n0,q;
    cin>>n0>>q;
  //  for (int i=1; i<=n0; i++)
    //    cout<<f(n0,i)<<" ";
    for (int i=1; i<=q; i++)
    {
        long long x;
        cin>>x;
        cout<<f(n0,x)<<"\n";
    }
    return 0;
}