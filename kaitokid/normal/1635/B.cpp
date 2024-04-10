#include <bits/stdc++.h>
using namespace std;
int a[200009];
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin>>t;
    while(t--)
    {
        int ans=0,n;
        cin>>n;
        for(int i=0;i<n;i++)cin>>a[i];
        a[n]=1000000000;
        for(int i=1;i+1<n;i++)
        if(a[i]>a[i-1]&&a[i]>a[i+1]){ans++;a[i+1]=max(a[i],a[i+2]);}
        cout<<ans<<endl;
        for(int i=0;i<n;i++)cout<<a[i]<<" ";
        cout<<endl;
    }
    return 0;
}