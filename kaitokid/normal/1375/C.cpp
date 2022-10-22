#include <bits/stdc++.h>

using namespace std;
int t,n;
int a[300009];
int main()
{
    ios::sync_with_stdio(0);
    cin>>t;
    while(t--)
    {
        cin>>n;
        for(int i=0;i<n;i++)cin>>a[i];
        if(a[n-1]>a[0])cout<<"YES\n";
        else cout<<"NO\n";
    }
    return 0;
}