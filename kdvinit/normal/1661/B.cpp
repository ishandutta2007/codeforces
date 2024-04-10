/*
K.D. Vinit  /,,/
*/
#include<bits/stdc++.h>
using namespace std;

#define int long long
#define endl "\n"

const int N = 32768;
int val[N];

void solve()
{
    int n;
    cin>>n;
    cout<<val[n]<<endl;
}

int32_t main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    for(int i=0; i<N; i++) val[i]=-1;

    queue<pair<int, int>> qu;
    qu.push({0, 0});

    while(!qu.empty())
    {
        auto cur = qu.front();
        qu.pop();

        int chi = cur.first;
        int dep = cur.second;

        if(val[chi]==-1) val[chi]=dep;

        int v1 = (chi-1+N)%N;
        if(val[v1]==-1) qu.push({v1, dep+1});

        int v2=0, v3=0;
        if(chi%2==0)
        {
            v2 = chi/2;
            v3 = (chi+N)/2;
            if(val[v2]==-1) qu.push({v2, dep+1});
            if(val[v3]==-1) qu.push({v3, dep+1});
        }
    }

    int t; cin>>t;
    while(t--) solve();
    return 0;
}