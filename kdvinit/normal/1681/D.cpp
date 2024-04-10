/*
K.D. Vinit  /,,/
*/
#include<bits/stdc++.h>
using namespace std;

#define int long long
#define endl "\n"

bool check(int x, int i)
{
    while(x!=0)
    {
        int y=x%10;
        if(y==i) return true;
        x/=10;
    }
    return false;
}

int len(int x)
{
    string sx = to_string(x);
    return sx.size();
}

void solve()
{
    int n, x;
    cin>>n>>x;

    int pos=0;
    for(int i=2; i<=9; i++) if(check(x, i)) pos=1;

    if(pos==0) { cout<<-1<<endl; return; }

    int mx[10]={0};
    for(int i=2; i<=9; i++)
    {
        if(check(x, i)) mx[i]=x;
    }

    int mov=0;
    while(1)
    {
        mov++;
        if(mov>100) { cout<<-1<<endl; return; }

        int mx2[10]={0};
        for(int i=2; i<=9; i++)
        {
            int y = mx[i];
            int z = y*i;
            if(len(z)>=n) { cout<<mov<<endl; return; }
            for(int j=2; j<=9; j++)
            {
                if(check(z, j)) mx2[j]=max(mx2[j], z);
            }
        }

        for(int i=2; i<=9; i++) mx[i]=max(mx[i], mx2[i]);
    }
}

map<int, int> dp;
int eval(int x, int n)
{
    if(dp[x]!=0) return dp[x];

    int ans=10*n;
    for(int i=2; i<=9; i++)
    {
        if(check(x, i)==0) continue;

        int y = x*i;
        if(len(y)>=n) { ans=1; break; }

        ans=min(ans, eval(y, n)+1);
    }

    dp[x]=ans;
    return ans;
}

void solve2()
{
    int n, x;
    cin>>n>>x;

    int pos=0;
    for(int i=2; i<=9; i++) if(check(x, i)) pos=1;

    if(pos==0) { cout<<-1<<endl; return; }

    int ans = eval(x, n);
    cout<<ans<<endl;
}

int32_t main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    solve2();
    return 0;
}