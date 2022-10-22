#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int fr[39];
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin>>t;
    while(t--)
    {
        memset(fr,0,sizeof fr);
        int n,k;
        cin>>n>>k;
        int x;
        for(int i=0;i<n;i++)
        {
            cin>>x;
            for(int j=0;j<31;j++)if(x&(1<<j))fr[j]++;
        }

        int ans=0;
        for(int i=30;i>=0;i--)
        {
            if(fr[i]+k<n)continue;
            ans|=(1<<i);
            k-=(n-fr[i]);

        }
        cout<<ans<<endl;

    }

    return 0;

}