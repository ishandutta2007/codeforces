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

    int done=0;
    vector<char> ans;

    char x, y, lst;
    cin>>x>>y;
    ans.push_back(x);
    ans.push_back(y);
    lst = y;

    for(int i=2; i<=n-2; i++)
    {
        cin>>x>>y;
        if(x!=lst)
        {
            done=1;
            ans.push_back(x);
        }
        lst=y;
        ans.push_back(y);
    }

    if(!done) ans.push_back('a');

    for(char i: ans) cout<<i;
    cout<<endl;
}

int32_t main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int t; cin>>t;
    while(t--) solve();
    return 0;
}