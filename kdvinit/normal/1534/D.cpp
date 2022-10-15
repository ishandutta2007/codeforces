/*
K.D. Vinit  |,,|
*/
#include<bits/stdc++.h>
using namespace std;

#define int long long

const int N = 2002;
vector< array<int, 2> > edge;
int d[N];
int n;

void Query(int r)
{
    cout<<"? "<<r<<endl;
    for(int i=1; i<=n; i++) cin>>d[i];
}

void Answer()
{
    cout<<"!"<<endl;
    int m = edge.size();
    for(int i=0; i<m; i++) cout<<edge[i][0]<<" "<<edge[i][1]<<endl;
}

void solve()
{
    cin>>n;
    edge.clear();

    Query(1);
    vector<int> odd, even;
    for(int i=2; i<=n; i++)
    {
        if(d[i]==1) edge.push_back({1, i});

        if(d[i]%2==1) odd.push_back(i);
        else even.push_back(i);
    }

    vector<int> take;
    if(odd.size() <= even.size()) take = odd;
    else take = even;

    while(!take.empty())
    {
        int v = take.back(); take.pop_back(); Query(v);
        for(int i=2; i<=n; i++) if(d[i]==1) edge.push_back({v, i});
    }

    Answer();
}

int32_t main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    solve();
    return 0;
}