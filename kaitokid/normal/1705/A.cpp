#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int a[209],n,x;
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin>>t;
    while(t--)
    {
        cin>>n>>x;
        for(int i=0;i<2*n;i++)cin>>a[i];
        sort(a,a+2*n);
        bool ans=true;
        for(int i=0;i<n;i++)
            if(a[i+n]<a[i]+x)ans=false;
        if(ans)cout<<"YES"<<endl;
        else cout<<"NO"<<endl;

    }

    return 0;
}