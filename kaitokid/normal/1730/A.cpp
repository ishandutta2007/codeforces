#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int fr[109];
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin>>t;
    while(t--)
    {
        for(int i=0;i<=100;i++)fr[i]=0;
        int ans=0;
        int n,c;
        cin>>n>>c;
        for(int i=0;i<n;i++)
        {
            int x;
            cin>>x;
            fr[x]++;
        }
        for(int i=0;i<=100;i++)ans+=min(c,fr[i]);
        cout<<ans<<endl;
    }


    return 0;
}