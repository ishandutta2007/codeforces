#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
int a[2000];
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin>>t;
    while(t--)
    {
        int n,k;
        cin>>n>>k;
        for(int i=0;i<n;i++)cin>>a[i];
        for(int i=0;i<n-1;i++)
        {
            int u=min(k,a[i]);
            a[i]-=u;
            a[n-1]+=u;
            k-=u;
        }
        for(int i=0;i<n;i++)cout<<a[i]<<" ";
        cout<<endl;
    }
    return 0;
}