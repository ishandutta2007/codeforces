/*
K.D. Vinit  |,,|
*/
#include<bits/stdc++.h>
using namespace std;

#define int long long

const int N = 1e5+1;
int a[N][6];

bool winner(int i, int j)
{
    int cnt=0;
    for(int k=1; k<=5; k++)
    {
        if(a[i][k]<a[j][k]) cnt++;
    }
    return (cnt>2);
}

void solve()
{
    int n;
    cin>>n;

    for(int i=1; i<=n; i++)
    {
        for(int j=1; j<=5; j++) cin>>a[i][j];
    }

    int cur=1;
    for(int i=2; i<=n; i++)
    {
        if(winner(i, cur)) cur=i;
    }

    for(int i=1; i<=n; i++)
    {
        if(i==cur) continue;
        if(winner(i, cur))
        {
            cout<<-1<<endl;
            return;
        }
    }

    cout<<cur<<endl;
}

int32_t main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int t; cin>>t;
    while(t--) solve();
    return 0;
}