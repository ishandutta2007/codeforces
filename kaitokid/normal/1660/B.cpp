#include <bits/stdc++.h>
using namespace std;
int a[200009],n;
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin>>t;
    while(t--)
    {
        cin>>n;
        for(int i=0;i<n;i++)cin>>a[i];
        sort(a,a+n);
        int mx=a[n-1];
        int mn=0;
        if(n>1)mn=a[n-2];
        if(mx-mn>1)cout<<"NO"<<endl;
        else cout<<"YES"<<endl;
    }
    return 0;
}