/*
K.D. Vinit  /,,/
*/
#include<bits/stdc++.h>
using namespace std;

#define int long long
#define endl "\n"

void solve()
{
    int n, m;
    cin>>n>>m;

    int a[n+1][m+1];
    for(int i=1; i<=n; i++)
    {
        for(int j=1; j<=m; j++)
        {
            char x; cin>>x;
            a[i][j]=(x-'0');
        }
    }

    int p3[1001]={0};
    int p2[101]={0};

    int p3r[1001];
    int p2r[101];


    for(int i=1; i<=n; i++)
    {
        for(int j=2; j<=m; j++)
        {
            int num = a[i][j-1]*10 + a[i][j];
            p2[num]=i;
            p2r[num]=j;
        }

        for(int j=3; j<=m; j++)
        {
            int num = a[i][j-2]*100 + a[i][j-1]*10 + a[i][j];
            p3[num]=i;
            p3r[num]=j;
        }
    }

    int fin[m+1];
    for(int j=1; j<=m; j++)
    {
        char x; cin>>x;
        fin[j]=(x-'0');
    }

    int pos[m+1]={0}, lst[m+1]={0}, seg[m+1];
    int ll[m+1], rr[m+1];

    pos[0]=1;

    for(int i=1; i<=m; i++)
    {
        if(i>1)
        {
            int num = fin[i-1]*10 + fin[i];
            if(p2[num]!=0 && pos[i-2]==1)
            {
                pos[i]=1;
                lst[i]=i-2;
                seg[i]=p2[num];
                rr[i] = p2r[num];
                ll[i] = rr[i]-1;
            }
        }

        if(i>2)
        {
            int num = fin[i-2]*100 + fin[i-1]*10 + fin[i];
            if(p3[num]!=0 && pos[i-3]==1)
            {
                pos[i]=1;
                lst[i]=i-3;
                seg[i]=p3[num];
                rr[i] = p3r[num];
                ll[i] = rr[i]-2;
            }
        }
    }

    if(pos[m]==0) { cout<<-1<<endl; return; }

    vector<array<int, 3>> ans;

    int cur = m;
    while(cur!=0)
    {
        ans.push_back({ll[cur], rr[cur], seg[cur]});
        cur = lst[cur];
    }

    reverse(ans.begin(), ans.end());

    cout<<ans.size()<<endl;
    for(auto x: ans)
    {
        cout<<x[0]<<" "<<x[1]<<" "<<x[2]<<endl;
    }
}

int32_t main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int t; cin>>t;
    while(t--) solve();
    return 0;
}