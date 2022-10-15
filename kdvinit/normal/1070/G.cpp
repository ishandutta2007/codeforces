/*
K.D. Vinit  |,,|
*/
#include<bits/stdc++.h>
using namespace std;

#define int long long

const int N = 101;

int hero[N]={0}, state[N], index[N], n, m, ans[N], pre[N]={0};

bool check(int ind)
{
    int cnt=0;
    int done[N]={0}, cstate[N];

    for(int i=1; i<=n; i++) cstate[i]=state[i];

    for(int i=ind; i>0; i--)
    {
        if(pre[i]==0 || done[i]==1) continue;
        int x = hero[i];
        int y = index[i];
        for(int j=i; j<=ind; j++)
        {
            x+=cstate[j];
            if(x<0) break;
        }
        if(x<0) continue;
        ans[++cnt]=y;
        for(int j=i; j<=ind; j++) cstate[j]=0;
        done[i]=1;
    }

    for(int i=ind; i<=n; i++)
    {
        if(pre[i]==0 || done[i]==1) continue;
        int x = hero[i];
        int y = index[i];
        for(int j=i; j>=ind; j--)
        {
            x+=cstate[j];
            if(x<0) break;
        }
        if(x<0) continue;
        ans[++cnt]=y;
        for(int j=ind; j<=i; j++) cstate[j]=0;
        done[i]=1;
    }

    for(int i=ind; i>0; i--)
    {
        if(pre[i]==0 || done[i]==1) continue;
        int x = hero[i];
        int y = index[i];
        for(int j=i; j<=ind; j++)
        {
            x+=cstate[j];
            if(x<0) break;
        }
        if(x<0) continue;
        ans[++cnt]=y;
        for(int j=i; j<=ind; j++) cstate[j]=0;
        done[i]=1;
    }

    for(int i=ind; i<=n; i++)
    {
        if(pre[i]==0 || done[i]==1) continue;
        int x = hero[i];
        int y = index[i];
        for(int j=i; j>=ind; j--)
        {
            x+=cstate[j];
            if(x<0) break;
        }
        if(x<0) continue;
        ans[++cnt]=y;
        for(int j=ind; j<=i; j++) cstate[j]=0;
        done[i]=1;
    }

    for(int i=ind; i>0; i--)
    {
        if(pre[i]==0 || done[i]==1) continue;
        int x = hero[i];
        int y = index[i];
        for(int j=i; j<=ind; j++)
        {
            x+=cstate[j];
            if(x<0) break;
        }
        if(x<0) continue;
        ans[++cnt]=y;
        for(int j=i; j<=ind; j++) cstate[j]=0;
        done[i]=1;
    }

    for(int i=ind; i<=n; i++)
    {
        if(pre[i]==0 || done[i]==1) continue;
        int x = hero[i];
        int y = index[i];
        for(int j=i; j>=ind; j--)
        {
            x+=cstate[j];
            if(x<0) break;
        }
        if(x<0) continue;
        ans[++cnt]=y;
        for(int j=ind; j<=i; j++) cstate[j]=0;
        done[i]=1;
    }

    return (cnt==m);
}

void solve()
{
    cin>>n>>m;

    for(int i=1; i<=m; i++)
    {
        int s, h;
        cin>>s>>h;
        hero[s]=h;
        index[s]=i;
        pre[s]=1;
    }

    for(int i=1; i<=n; i++) cin>>state[i];

    for(int i=1; i<=n; i++)
    {
        if(hero[i]==0) continue;
        hero[i]+=state[i];
        state[i]=0;
        if(hero[i]<0) { cout<<-1<<endl; return; }
    }

    for(int i=1; i<=n; i++)
    {
        if(!check(i)) continue;
        cout<<i<<endl;
        for(int i=1; i<=m; i++) cout<<ans[i]<<" ";
        cout<<endl;
        return;
    }
    cout<<-1<<endl;
}

int32_t main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    solve();
    return 0;
}