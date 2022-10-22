#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
ll a[200009],n,t,k;
int main()
{
    ios::sync_with_stdio(0);
    cin>>t;
    while(t--)
    {
    cin>>n;
    int d=n;
    for(int i=n-1;i>=1;i--)
        d=(d+i+1)/2;
    cout<<d<<endl;
    d=n;
    for(int i=n-1;i>=1;i--)
    {cout<<i<<" "<<d<<endl;
    d=(d+1+i)/2;
    }
    }
    return 0;
}