/*
K.D. Vinit  /,,/
*/
#include<bits/stdc++.h>
using namespace std;

#define int long long
#define endl "\n"

void solve()
{
    int n, q;
    cin>>n>>q;

    int sum=0;
    map<int, int> mp;

    for(int i=1; i<=n; i++)
    {
        int x; cin>>x;
        mp[i]=x;
        sum+=x;
    }

    int lst=-1;

    while(q--)
    {
        int t; cin>>t;
        if(t==1)
        {
            int i, x;
            cin>>i>>x;

            if(mp[i]==0)
            {
                sum+=(x-lst);
                mp[i]=x;
            }
            else
            {
                sum+=(x-mp[i]);
                mp[i]=x;
            }

        }
        else
        {
            int x; cin>>x;
            sum = (n*x);
            lst = x;
            mp.clear();
        }

        cout<<sum<<endl;
    }
}

int32_t main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    solve();
    return 0;
}