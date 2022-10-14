#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n,ans;
    cin>>n;
    ans=(n+n/2);cout<<ans<<endl;
    for(int i=1;i<n;i+=2)cout<<i+1<<" ";
    for(int i=0;i<n;i+=2)cout<<i+1<<" ";
    for(int i=1;i<n;i+=2)cout<<i+1<<" ";

    return 0;
}