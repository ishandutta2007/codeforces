/*
K.D. Vinit  /,,/
*/
#include<bits/stdc++.h>
using namespace std;

#define int long long
#define endl "\n"

const int N = 5e5 + 1;
int rep[N];

void solve()
{
    int n;
    cin>>n;

    int x[n+1]={0}, y[n+1]={0};
    for(int i=1; i<=n; i++)
    {
        int q; cin>>q;
        cin>>x[i];
        if(q==2) cin>>y[i];
    }

    vector<int> ans;
    for(int i=1; i<N; i++) rep[i]=i;

    for(int i=n; i>=1; i--)
    {
        if(y[i]!=0) rep[x[i]]=rep[y[i]];
        else ans.push_back(rep[x[i]]);
    }

    reverse(ans. begin(), ans.end());
    for(int x: ans) cout<<x<<" ";
    cout<<endl;
}

int32_t main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    solve();
    return 0;
}