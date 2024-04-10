/*
K.D. Vinit  |,,|
*/
#include<bits/stdc++.h>
using namespace std;

#define int long long

void solve()
{
    int n;
    cin>>n;

    int h[n+1];
    for(int i=1; i<=n; i++) cin>>h[i];

    int b[n+1];
    for(int i=1; i<=n; i++) cin>>b[i];

    int dp[n+1];
    stack<int> mnh;
    stack<int> mxdp;

    dp[0]=0;
    h[0]=0;
    mnh.push(0);

    int lh = 0;
    int Neg_Infi = -1e15;

    for(int i=1; i<=n; i++)
    {
        int cur_mx_dp = Neg_Infi;

        while(h[mnh.top()]>h[i])
        {
            cur_mx_dp = max(cur_mx_dp, mxdp.top());
            mxdp.pop();
            mnh.pop();
        }

        int val = dp[mnh.top()] + b[i];
        //cout<<val<<endl;

        if(mnh.top()!=0) val = max(val, dp[mnh.top()]);
        val = max(val, cur_mx_dp + b[i]);

        dp[i] = val;
        cur_mx_dp = max(cur_mx_dp, val);

        mxdp.push(cur_mx_dp);
        mnh.push(i);

        //cout<<dp[i]<<" ";
    }
    //cout<<endl;

    cout<<dp[n]<<endl;
}

int32_t main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    solve();
    return 0;
}