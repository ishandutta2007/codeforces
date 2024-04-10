/*
K.D. Vinit  |,,|
*/
#include<bits/stdc++.h>
using namespace std;

#define int long long

stack< array<int, 2> > odd;
stack< array<int, 2> > even;

void Print_Odd(int y)
{
    auto x = odd.top();
    odd.pop();
    cout<<y<<" "<<x[0]<<" "<<x[1]<<endl;
}

void Print_Even(int y)
{
    auto x = even.top();
    even.pop();
    cout<<y<<" "<<x[0]<<" "<<x[1]<<endl;
}


void Add_oe(int o, int e)
{
    if(!odd.empty()) Print_Odd(o);
    else Print_Even(e);
}

void Add_eo(int e, int o)
{
    if(!even.empty()) Print_Even(e);
    else Print_Odd(o);
}

void solve()
{
    int n;
    cin>>n;

    for(int i=1; i<=n; i++)
    {
        for(int j=1; j<=n; j++)
        {
            if( (i+j)%2==1 ) odd.push({i, j});
            else even.push({i, j});
        }
    }

    for(int i=1; i<=n*n; i++)
    {
        int a; cin>>a;

        if(a==1) Add_eo(2, 3);
        if(a==2) Add_oe(1, 3);
        if(a==3) Add_eo(2, 1);
    }
}

int32_t main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    solve();
    return 0;
}