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

    int a[n+1];
    for(int i=1; i<=n; i++) cin>>a[i];

    int p2[4]={16, 8, 4, 2};

    for(int i=0; i<=3; i++)
    {
        int len = p2[i];
        if(len>n) continue;

        for(int j=1; j<n; j+=len)
        {
            int pos=1;
            for(int k=j+1; k<j+len; k++)
            {
                if(a[k-1]>a[k]) pos=0;
            }
            if(pos==1)
            {
                cout<<len<<endl;
                return;
            }
        }
    }

    cout<<1<<endl;
}

int32_t main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    solve();
    return 0;
}