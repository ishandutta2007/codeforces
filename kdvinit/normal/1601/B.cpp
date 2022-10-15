/*
K.D. Vinit  /,,/
*/
#include<bits/stdc++.h>
using namespace std;

#define int long long
#define endl "\n"

void solve()
{
    int n;
    cin>>n;

    int a[n+1], b[n+1];
    for(int i=1; i<=n; i++) cin>>a[i];
    for(int i=1; i<=n; i++) cin>>b[i];

    vector<int> ans;
    int cur=n;
    int lst=n;

    for(int i=1; 1; i++)
    {
        int r = cur-a[cur];
        if(r==0) { ans.push_back(0); break; }

        int mn=r, mni=-1;

        for(int j=lst; j>=r; j--)
        {
            int x = j+b[j];
            int y = x-a[x];

            if(y>=mn) continue;
            cur=x;
            mn=y;
            mni=j;
        }

        if(mn==r) { cout<<-1<<endl; return; }
        ans.push_back(mni);
        lst = r;
    }

    cout<<ans.size()<<endl;
    for(int x: ans) { cout<<x<<" "; }
    cout<<endl;
}

int32_t main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    solve();
    return 0;
}