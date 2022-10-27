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

    map<int, int> st;   st[0]=1;
    map<int, int> lst;

    for(int i=1; i<=n; i++)
    {
        char tp; int x;
        cin>>tp>>x;

        if(tp=='+') st[x]=1;
        else
        {
            int k = x;
            int cur = lst[k];
            while(st[cur]==1) cur+=k;
            lst[k]=cur;
            cout<<cur<<endl;
        }
    }
}

int32_t main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    solve();
    return 0;
}