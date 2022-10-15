/*
K.D. Vinit  |,,|
*/
#include<bits/stdc++.h>
using namespace std;

#define int long long

void solve()
{
    int n, q;
    cin>>n>>q;

    int a[n+1];
    for(int i=1; i<=n; i++) cin>>a[i];

    int pos[51]={0};
    for(int i=1; i<=n; i++)
    {
        if(pos[a[i]]!=0) continue;
        pos[a[i]]=i;
    }

    while(q--)
    {
        int x;
        cin>>x;

        int y = pos[x];
        cout<<y<<" ";

        for(int i=1; i<=50; i++)
        {
            if(pos[i]<y) pos[i]++;
        }

        pos[x]=1;
    }
    cout<<endl;
}

int32_t main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    solve();
    return 0;
}