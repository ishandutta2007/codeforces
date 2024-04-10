/*
K.D. Vinit  |,,|
*/
#include<bits/stdc++.h>
using namespace std;

#define int long long

void solve()
{
    int n, m;
    cin>>n>>m;

    int l[m+1];
    int sum = 0;
    for(int i=1; i<=m; i++) { cin>>l[i]; sum+=l[i]; }

    if(sum<n) { cout<<-1<<endl; return; }

    int mx[m+2] = {0};
    for(int i=m; i>=1; i--)
    {
        mx[i] = max(l[i], mx[i+1]+1);
    }

    if(mx[1]>n) { cout<<-1<<endl; return; }

    int p[m+1];
    int done=0;

    int ls=0;
    int le=0;

    if(mx[1]==n) done=1;
    for(int i=1; i<=m; i++)
    {
        int cs = ls+1;

        if(done==1)
        {
            p[i]=cs;
        }
        else
        {
            while(cs!=le+1 && cs+mx[i+1]<n && cs+l[i]-1<n) cs++;

            if(cs+mx[i+1]==n) done=1;
            p[i]=cs;
        }

        ls = p[i];
        le = p[i]+l[i]-1;
    }

    for(int i=1; i<=m; i++) cout<<p[i]<<" ";
    cout<<endl;
}

int32_t main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    solve();
    return 0;
}