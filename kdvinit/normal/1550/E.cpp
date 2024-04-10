/*
K.D. Vinit  |,,|
*/
#include<bits/stdc++.h>
using namespace std;

#define int long long

const int N = 2e5 + 1;
const int Infi = 1e9;

int n, k;
char a[N];

bool check(int len)
{
    int pre[n+2][k+1];
    for(int j=1; j<=k; j++) pre[0][j]=0, pre[n+1][j]=Infi;
    for(int i=1; i<=n; i++)
    {
        for(int j=1; j<=k; j++) pre[i][j]=pre[i-1][j]+(a[i]=='?');
        int j = a[i]-'a'+1; pre[i][j]++;
    }

    int nxt[n+2][k+1];
    for(int i=1; i<=k; i++) nxt[n+1][i]=n+1;

    for(int i=1; i<=k; i++)
    {
        int lst=1;
        int cnt=0;
        char x = 'a'+i-1;
        for(int j=n; j>=0; j--)
        {
            nxt[j][i] = nxt[j+1][i];
            if(cnt>=len) nxt[j][i] = j+len;

            if(j!=0 && (a[j]==x || a[j]=='?')) cnt++;
            else cnt=0;
        }
    }

    int m = (1<<k);
    int dp[m];

    dp[0]=0;
    for(int i=1; i<m; i++)
    {
        dp[i]=n+1;
        for(int j=1; j<=k; j++)
        {
            int x = 1<<(j-1);
            if((i&x)==0) continue;
            int y = i-x;
            dp[i] = min(dp[i], nxt[dp[y]][j]);
        }
    }

    return dp[m-1]<=n;
}

void solve()
{
    cin>>n>>k;
    for(int i=1; i<=n; i++) cin>>a[i];

    int l=0, r=n+1;
    while(l+1!=r)
    {
        int mid=(l+r)/2;
        if(check(mid)) l=mid;
        else r=mid;
    }
    cout<<l<<endl;
}

int32_t main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    solve();
    return 0;
}