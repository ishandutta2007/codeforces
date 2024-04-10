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

    int ans[n+1],a[n+1];
    for(int i=1;i<=n;i++)
    {
        char x; cin>>x;
        a[i]=x-96;
    }

    set< pair<int,int> > inc;
    set< pair<int,int> >::iterator itr;

    int cnt=1;
    inc.insert({a[1],1});
    ans[1]=1;
    for(int i=2;i<=n;i++)
    {
        int x=a[i];
        pair<int, int> sml=*inc.begin();
        if(x<sml.first)
        {
            cnt++;
            ans[i]=cnt;
            inc.insert({x,cnt});
            continue;
        }

        itr=inc.upper_bound({x,cnt+1});
        itr--;
        pair<int, int> req=*itr;

        ans[i]=req.second;
        inc.erase(req);
        inc.insert({x,ans[i]});
    }

    cout<<cnt<<endl;

    for(int i=1;i<=n;i++) cout<<ans[i]<<" ";
    cout<<endl;
}

int32_t main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    solve();
    return 0;
}