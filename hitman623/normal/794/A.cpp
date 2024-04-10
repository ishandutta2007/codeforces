#include <bits/stdc++.h>
#define pb push_back
using namespace std;

int main()
{
    long n,x[100005],i,a,b,c;
    cin>>a>>b>>c;
    cin>>n;
    for(i=0;i<n;++i)
    cin>>x[i];
    sort(x,x+n);
    cout<<lower_bound(x,x+n,c)-upper_bound(x,x+n,b);
    return 0;
}