/*
K.D. Vinit  /,,/
*/
#include<bits/stdc++.h>
using namespace std;

#define endl "\n"

const int infy = 1e9;

int solve()
{
    int n;
    cin>>n;

    int dp1[2001];
    for(int i=0; i<=2000; i++) dp1[i]=infy;

    dp1[0]=0;
    for(int i=1; i<=n; i++)
    {
        int x; cin>>x;

        int dp2[2001];
        for(int j=0; j<=2000; j++) dp2[j]=infy;

        for(int j=0; j<=2000; j++)
        {
            if(dp1[j]==infy) continue;

            int l1 = j;
            int l2 = dp1[j];

            int l3 = max((int)0, l1-x);
            int l4 = l2+x;

            if(l3<2001) dp2[l3]=min(dp2[l3], l4);
            if(l4<2001) dp2[l4]=min(dp2[l4], l3);

            int l5 = max((int)0, l2-x);
            int l6 = l1+x;

            if(l5<2001) dp2[l5]=min(dp2[l5], l6);
            if(l6<2001) dp2[l6]=min(dp2[l6], l5);
        }

        for(int j=0; j<=2000; j++) dp1[j]=dp2[j];
    }

    int ans=1e6;
    for(int j=0; j<=2000; j++)
    {
        if(dp1[j]==infy) continue;
        int tmp = j+dp1[j];
        ans = min(ans, tmp);
    }
    return ans;
}

int32_t main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int t; cin>>t;
    while(t--) cout<<solve()<<endl;
    return 0;
}