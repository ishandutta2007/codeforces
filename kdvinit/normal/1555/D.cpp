/*
K.D. Vinit  |,,|
*/
#include<bits/stdc++.h>
using namespace std;

#define int long long

void Calc(char a[], int pre[], int n, string s)
{
    pre[0]=0;
    //cout<<"Hello"<<endl;
    //cout<<s<<endl;
    for(int i=1; i<=n; i++)
    {
        char x = s[(i%3)];
        //cout<<i<<" "<<x<<endl;
        pre[i]=pre[i-1];
        if(x!=a[i]) pre[i]++;
    }
}

void solve()
{
    int n, m;
    cin>>n>>m;

    char a[n+1];
    for(int i=1; i<=n; i++) cin>>a[i];

    //cout<<"Hello"<<endl;

    int pre[6][n+1];
    Calc(a, pre[0], n, "abc");
    Calc(a, pre[1], n, "bca");
    Calc(a, pre[2], n, "cab");
    Calc(a, pre[3], n, "cba");
    Calc(a, pre[4], n, "bac");
    Calc(a, pre[5], n, "acb");

    //cout<<"Hello"<<endl;

    while(m--)
    {
        int l, r;
        cin>>l>>r;
        int ans = n+1;
        for(int i=0; i<6; i++)
        {
            int tmp = pre[i][r] - pre[i][l-1];
            ans = min(ans, tmp);
        }
        cout<<ans<<endl;
    }
}

int32_t main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    solve();
    return 0;
}