/*
K.D. Vinit  /,,/
*/
#include<bits/stdc++.h>
using namespace std;

//#define int long long
#define endl "\n"

const int N = 2e5+10;
const int M = 500;      //root(2e5) = 467;

int n, m;
int x[N+1], y[N+1];
int ans[N+1]={0}, dp1[N+1]={0}, dp2[M+5][M+5];

void update(int ind, int l, int r)
{
    int sum = x[ind]+y[ind];
    int ls=0, le=0;
    for(int i=l+x[ind]; i<r; i+=sum)
    {
        dp1[i]++;
        ls=i;
    }
    for(int i=l+sum; i<r; i+=sum)
    {
        dp1[i]--;
        le=i;
    }
    if(le<ls) dp1[r]--;
}

void get_ans1()
{
    for(int i=1; i<=m; i++)
    {
        dp1[i]+=dp1[i-1];
        ans[i]+=dp1[i];
    }
}

void up2(int ind, int l, int ad)
{
    int sum = x[ind]+y[ind];
    for(int i=0; i<sum; i++)
    {
        int cur = (i-l)%sum;
        if(cur<0) cur+=sum;
        if(cur>=x[ind]) dp2[sum][i]+=ad;
    }
}

void solve()
{
    cin>>n>>m;
    for(int i=1; i<=n; i++) cin>>x[i]>>y[i];

    memset(dp2, 0, sizeof(dp2));
    int start[n+1]={0};

    for(int i=1; i<=m; i++)
    {
        int op, k; cin>>op>>k;
        int sum = x[k]+y[k];

        if(sum<=M)
        {
            if(op==1) { start[k]=i; up2(k, i, 1); }
            else { up2(k, start[k], -1); start[k]=0; }
        }
        else
        {
            if(op==1) start[k]=i;
            else { update(k, start[k], i); start[k]=0; }
        }

        for(int j=1; j<=M; j++) ans[i]+=dp2[j][(i%j)];
    }

    for(int i=1; i<=n; i++)
    {
        int sum = x[i]+y[i];
        if(sum<=M) continue;
        if(start[i]==0) continue;
        update(i, start[i], m+1);
    }

    get_ans1();
    for(int i=1; i<=m; i++) cout<<ans[i]<<endl;
}

int32_t main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    solve();
    return 0;
}