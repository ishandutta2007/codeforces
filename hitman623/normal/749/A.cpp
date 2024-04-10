#include <bits/stdc++.h>

using namespace std;

int main()
{
    long n,i;
    cin>>n;
    cout<<n/2<<endl;
    for(i=0;i<n/2-(n&1);++i)
        cout<<2<<" ";
    if(n&1) cout<<3;
    return 0;
}