#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        int mx=0,ans=0;
        for(int i=1;i<=n;i++)
        {
            int x;
            cin>>x;
            mx=max(mx,x);
            if(i==mx)ans++;
        }
        cout<<ans<<endl;
    }
    return 0;
}