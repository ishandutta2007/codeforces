/*
K.D. Vinit  /,,/
*/
#include<bits/stdc++.h>
using namespace std;

#define int long long
#define endl "\n"

void solve()
{
    int n, k;
    cin>>n>>k;

    map<int, int> mp;
    set<int> st;

    for(int i=1; i<=n; i++)
    {
        int x; cin>>x;
        mp[x]++;
        if(mp[x]==k) st.insert(x);
    }

    if(st.size()==0) { cout<<-1<<endl; return; }

    int ans=1;
    int lst=-1;
    int cnt=0;
    int lstl=-1;
    int ff = *st.begin();
    int al=ff, ar=ff;

    for(int x: st)
    {
        if(x==lst+1)
        {
            cnt++;
            if(cnt>ans)
            {
                ans=cnt;
                al=lstl;
                ar=x;
            }
        }
        else
        {
            cnt=1;
            lstl=x;
        }

        lst=x;
    }

    cout<<al<<" "<<ar<<endl;
}

int32_t main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int t; cin>>t;
    while(t--) solve();
    return 0;
}