#include<bits/stdc++.h>
using namespace std;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    int t;cin>>t;
    while(t--)
    {
        int n,m;
        cin>>n>>m;
        vector<int>a(n*m),b(n*m),ans(n*m);
        string s;
        cin>>s;
        for(int i=0;i<n*m;++i) a[i]=s[i]-'0';
        b[0]=a[0];
        for(int i=1;i<n*m;++i) b[i]=b[i-1]+a[i];
        for(int i=0;i<n*m;++i)
            if(i-m>=0) ans[i]=ans[i-m]+(b[i]-b[i-m]!=0);
            else ans[i]=(b[i]!=0);
        vector<bool>vis(m);
        int sum=0;
        for(int i=0;i<n*m;++i)
        {
            if(a[i]&&!vis[i%m])
            {
                vis[i%m]=true;
                ++sum;
            }
            ans[i]+=sum;
            cout<<ans[i]<<(i==n*m-1?'\n':' ');
        }
    }
}