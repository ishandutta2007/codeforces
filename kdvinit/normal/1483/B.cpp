/*
K.D. Vinit  |,,|
*/
#include<bits/stdc++.h>
using namespace std;

//#define int long long

int GCD(int x, int y)
{
    if(y==0) return x;
    else return GCD(y, x%y);
}

int cnt=0;

void solve()
{
    int n;
    cin>>n;

    int a[n+1];
    for(int i=1; i<=n; i++) cin>>a[i];

    if(n==1)
    {
        if(a[1]==1) cout<<1<<" "<<1<<endl;
        else cout<<0<<endl;
        return;
    }

    queue< array<int, 2> > B;
    int Nxt[n+1], Prv[n+1];

    for(int i=1; i<=n; i++)
    {
        Nxt[i]=i+1;
        Prv[i]=i-1;

        if(i==1) { Nxt[i]=2; Prv[i]=n; }
        if(i==n) { Nxt[i]=1; Prv[i]=n-1; }

        if( GCD(a[i], a[Nxt[i]])==1 ) B.push({i,Nxt[i]});
    }

    vector<int> ans;
    int Used[n+1]={0};

    while(!B.empty())
    {
        auto Songs = B.front();
        B.pop();

        int Last = Songs[0];
        int Curr = Songs[1];

        int pc = Prv[Curr];
        int nc = Nxt[Curr];

        if(Used[Last] || Used[Curr]) continue;

        ans.push_back(Curr);
        Used[Curr]=1;

        if(pc==nc)
        {
            if(a[pc]==1 && Used[pc]==0) ans.push_back(pc);
            break;
        }


        if( GCD(a[pc], a[nc])==1 ) B.push({pc,nc});

        Prv[nc] = pc;
        Nxt[pc] = nc;
    }

    cout<<ans.size()<<" ";
    for(int i=0; i<ans.size(); i++) cout<<ans[i]<<" ";
    cout<<endl;

}

int32_t main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int t; cin>>t;
    while(t--) solve();
    return 0;
}