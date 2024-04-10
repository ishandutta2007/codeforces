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
    n*=2;

    int a[n+1];
    int cnt1=0;

    for(int i=1; i<=n; i++)
    {
        char x; cin>>x;
        a[i] = x-'0';
        cnt1+=a[i];
    }

    if(cnt1%2==1)
    {
        cout<<-1<<endl;
        return;
    }

    vector<int> swp;

    int cur=1;
    for(int i=1; i<=n; i++)
    {
        int j = i;
        while(j<=n && a[j]==a[i]) j++;
        int cnt = j-i;

        if(cnt%2==0)
        {
            i=j-1;
            continue;
        }

        if(a[i]==cur)
        {
            swp.push_back(j-1);
            a[j-1] = (1-cur);
            cur = (1-cur);
            i=j-2;
            continue;
        }

        swp.push_back(j);
        a[j] = (1-cur);
        cur = (1-cur);
        i = j;
        continue;
    }

    cout<<swp.size()<<" ";
    for(int x: swp) cout<<x<<" ";
    cout<<endl;

    for(int i=1; i<=n; i+=2) cout<<i<<" ";
    cout<<endl;
}

int32_t main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int t; cin>>t;
    while(t--) solve();
    return 0;
}